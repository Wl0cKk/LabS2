#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>
#include <math.h>

const int ItemsCount = 8;
int sortedIndex = 0;

typedef struct {
    char name[40];
    long int ip;
} Item;

struct Node {
    Item* item;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;
void find_closest_key(Node* node, float average, long int* closestKey, float* minDifference);

Item* create_item(const char* name, long int ip) {
    Item* item = (Item*)malloc(sizeof(Item));
    strncpy(&item->name[0], name, strlen(name));
    item->ip = ip;
    return item;
}

Node* create_leaf(Item* item) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add_leaf(Node* root, Item* item) {
    Node* prev = NULL;
    Node* temp = root;
    bool find = true;
    while(temp && find) {
        prev = temp;
        if (item->ip == temp->item->ip) {
            printf("Duplicate IP: %ld", item->ip);
            find = false;
        } else {
            if (item->ip < temp->item->ip) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }
    if (find) {
        temp = create_leaf(item);
        if (item->ip < prev->item->ip) {
            prev->left = temp;
        } else {
            prev->right = temp;
        }
    }
}

void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; ++i) {
        printf("\t");
    }
    printf("%ld\n", root->item->ip);
    print_tree(root->left, level + 1);
}

Item* sortedItems[ItemsCount] = {NULL};

void sort_items_by_ip(Node* root) {
    if (root == NULL) {
        return;
    }
    sort_items_by_ip(root->left);
    sortedItems[sortedIndex++] = root->item;
    sort_items_by_ip(root->right);
}

void make_balanced(Node** nodePtr, int n, int k) {
    if (n == k) {
        *nodePtr = NULL;
        return;
    } else {
        int m = (n + k) / 2;
        Item* item = sortedItems[m];
        *nodePtr = create_leaf(item);
        make_balanced(&(*nodePtr)->left, n, m);
        make_balanced(&(*nodePtr)->right, m + 1, k);
    }
}

Item* search_by_ip(Node* node, long int ip) {
    if (node == NULL) {
        return NULL;
    }
    if (ip == node->item->ip) {
        return node->item;
    }
    if (ip < node->item->ip) {
        return search_by_ip(node->left, ip);
    } else {
        return search_by_ip(node->right, ip);
    }
}

Node* remove_item_by_ip(Node* root, long int ip) {
    Node* del = root;
    Node* prevDel = NULL;
    Node* replacing = NULL;
    Node* prevReplacing = NULL;

    while (del != NULL && del->item->ip != ip) {
        prevDel = del;
        if (del->item->ip > ip) {
            del = del->left;
        } else {
            del = del->right;
        }
    }

    if (del == NULL) {
        printf("\nCannot find computer with IP %ld\n", ip);
        return root;
    }

    if (del->right == NULL) {
        replacing = del->left;
    } else if (del->left == NULL) {
        replacing = del->right;
    } else {
        prevReplacing = del;
        replacing = del->left;
        while (replacing->right != NULL) {
            prevReplacing = replacing;
            replacing = replacing->right;
        }
        replacing->right = del->right;
        if( prevReplacing != del) {
            prevReplacing->right = replacing->left;
            replacing->left = prevReplacing;
        }
    }
    if (del == root) {
        root = replacing;
    } else {
        if (del->item->ip < prevDel->item->ip) {
            prevDel->left = replacing;
        } else {
            prevDel->right = replacing;
        }
    }
    free(del);
    return root;
}

void walk_tree_left_root_right(Node* node) {
    if (node == NULL) {
        return;
    }
    walk_tree_left_root_right(node->left);
    printf("%ld ", node->item->ip);
    walk_tree_left_root_right(node->right);
}

void walk_tree_root_left_right(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%ld ", node->item->ip);
    walk_tree_root_left_right(node->left);
    walk_tree_root_left_right(node->right);
}

void walk_tree_left_right_root(Node* node) {
    if (node == NULL) {
        return;
    }
    walk_tree_left_right_root(node->left);
    walk_tree_left_right_root(node->right);
    printf("%ld ", node->item->ip);
}


void free_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

float calculate_average(Node* node, int* totalSum, int* nodesCount){
    if (node == NULL) {
        return 0;
    }

    float leftSum = calculate_average(node->left, totalSum, nodesCount);
    *totalSum += node->item->ip;
    (*nodesCount)++;
    float rightSum = calculate_average(node->right, totalSum, nodesCount);

    return leftSum + rightSum + node->item->ip;
}

void task_13(Node* root) {
    int totalSum = 0;
    int nodesCount = 0;

    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    long int minKey = current->item->ip;

    current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    long int maxKey = current->item->ip;

    float average = (minKey + maxKey) / 2.0;

    long int closestKey = root->item->ip;
    float minDifference = fabsf(average - closestKey);
    
    find_closest_key(root, average, &closestKey, &minDifference);

    printf("\nAverage of keys closest to the middle of min(%ld) and max(%ld) keys: %.2f\n", minKey, maxKey, average);
    printf("Closest key to the average: %ld and value is \"%s\"\n", closestKey, search_by_ip(root, closestKey)->name);
}


void find_closest_key(Node* node, float average, long int* closestKey, float* minDifference) {
    if (node == NULL) {
        return;
    }

    float currentDifference = fabsf(average - node->item->ip);
    
    if (currentDifference < *minDifference) {
        *minDifference = currentDifference;
        *closestKey = node->item->ip;
    }

    find_closest_key(node->left, average, closestKey, minDifference);
    find_closest_key(node->right, average, closestKey, minDifference);
}

Item items[] = {
{"CEO_PC", 2886729994}, {"MAIL_SERVER", 2886730004}, {"FRONT_DESK_PC", 2886730014}, 
{"MARKETING_LAPTOP", 2886730019}, {"DATABASE_SERVER", 2886730024}, {"SALES_PC", 2886730025}, 
{"IT_HELPDESK_PC", 2886730026}, {"ACCOUNTING_WORKSTATION", 2886730074}};


int main() {

    Node* root = create_leaf(&items[0]);
    for (int i = 1; i < ItemsCount; ++i) {
        Item* item = &items[i];
        add_leaf(root, item);
    }
    printf("\nUnbalanced tree:\n");
    print_tree(root, 0);

    sort_items_by_ip(root);
    make_balanced(&root, 0, ItemsCount);
    printf("\nBalanced tree:\n");
    print_tree(root, 0);

    Item* newItem = create_item("CONFERENCE_ROOM_PC", 2886730072);
    add_leaf(root, newItem);
    printf("\nTree after adding:\n");
    print_tree(root, 0);

    long int to_find = 2886730019;
    Item* item = search_by_ip(root, to_find);
    if (item != NULL) {
        printf("\nFound item with ip %ld: '%s'\n", item->ip, item->name);
    } else {
        printf("\nCannot find an item with ip == %ld\n", to_find);
    }

    long int to_del = 2886730025;
    root = remove_item_by_ip(root, to_del);
    printf("\nTree after deleting item with ip %ld:\n", to_del);
    print_tree(root, 0);

    printf("\nLEFT->ROOT->RIGHT: ");
    walk_tree_left_root_right(root);

    printf("\nROOT->LEFT->RIGHT: ");
    walk_tree_root_left_right(root);

    printf("\nLEFT->RIGHT->ROOT: ");
    walk_tree_left_right_root(root);

    printf("\n===============================\n");
    
    task_13(root);

    free_tree(root);
    free(newItem);

    return 0;
}
