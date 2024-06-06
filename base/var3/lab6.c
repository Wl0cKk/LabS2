#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>

const int ItemsCount = 8;
int sortedIndex = 0;

typedef struct {
    char name[20];
    int uid;
} Item;

struct Node {
    Item* item;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Item* create_item(const char* name, int uid) {
    Item* item = (Item*)malloc(sizeof(Item));
    strncpy(&item->name[0], name, strlen(name));
    item->uid = uid;
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
        if (item->uid == temp->item->uid) {
            printf("Duplicate uid: %d", item->uid);
            find = false;
        } else {
            if (item->uid < temp->item->uid) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }
    if (find) {
        temp = create_leaf(item);
        if (item->uid < prev->item->uid) {
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
        printf("    ");
    }
    printf("%d\n", root->item->uid);
    print_tree(root->left, level + 1);
}

Item* sortedItems[ItemsCount] = {NULL};

void sort_items_by_uid(Node* root) {
    if (root == NULL) {
        return;
    }
    sort_items_by_uid(root->left);
    sortedItems[sortedIndex++] = root->item;
    sort_items_by_uid(root->right);
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

Item* search_by_uid(Node* node, int uid) {
    if (node == NULL) {
        return NULL;
    }
    if (uid == node->item->uid) {
        return node->item;
    }
    if (uid < node->item->uid) {
        return search_by_uid(node->left, uid);
    } else {
        return search_by_uid(node->right, uid);
    }
}

Node* remove_item_by_uid(Node* root, int uid) {
    Node* del = root;
    Node* prevDel = NULL;
    Node* replacing = NULL;
    Node* prevReplacing = NULL;

    while (del != NULL && del->item->uid != uid) {
        prevDel = del;
        if (del->item->uid > uid) {
            del = del->left;
        } else {
            del = del->right;
        }
    }

    if (del == NULL) {
        printf("\nCannot find an item with uid %d\n", uid);
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
        if (del->item->uid < prevDel->item->uid) {
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
    printf("%d ", node->item->uid);
    walk_tree_left_root_right(node->right);
}

void walk_tree_root_left_right(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->item->uid);
    walk_tree_root_left_right(node->left);
    walk_tree_root_left_right(node->right);
}

void walk_tree_left_right_root(Node* node) {
    if (node == NULL) {
        return;
    }
    walk_tree_left_right_root(node->left);
    walk_tree_left_right_root(node->right);
    printf("%d ", node->item->uid);
}


void free_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int task_3(Node* node, int key) {
    if (node == NULL) {
        return 0;
    }

    if (node->left != NULL && node->left->item->uid == key) {
        free_tree(node->left); // Remove the left branch
        node->left = NULL;
    } else if (node->right != NULL && node->right->item->uid == key) {
        free_tree(node->right); // Remove the right branch
        node->right = NULL;
    }

    int left_leaves = task_3(node->left, key);
    int right_leaves = task_3(node->right, key);

    return left_leaves + right_leaves;
}



Item items[] = {{"display", 100}, {"keyboard", 101}, {"mouse", 200}, {"motherboard", 900}, {"power supply", 550}, {"cpu", 180}, {"gpu", 150}, {"case", 165}};


int main() {

    Node* root = create_leaf(&items[0]);
    for (int i = 1; i < ItemsCount; ++i) {
        Item* item = &items[i];
        add_leaf(root, item);
    }
    printf("\nUnbalanced tree:\n");
    print_tree(root, 0);

    sort_items_by_uid(root);
    make_balanced(&root, 0, ItemsCount);
    printf("\nBalanced tree:\n");
    print_tree(root, 0);

    Item* newItem = create_item("floppy-disk", 420);
    add_leaf(root, newItem);
    printf("\nTree after adding:\n");
    print_tree(root, 0);

    int to_find = 420;
    Item* item = search_by_uid(root, to_find);
    if (item != NULL) {
        printf("\nFound item with uid %d: '%s'\n", item->uid, item->name);
    } else {
        printf("\nCannot find an item with uid == %d\n", to_find);
    }

    int to_del = 180;
    root = remove_item_by_uid(root, to_del);
    printf("\nTree after deleting item with uid %d:\n", to_del);
    print_tree(root, 0);

    printf("\nLEFT->ROOT->RIGHT: ");
    walk_tree_left_root_right(root);

    printf("\nROOT->LEFT->RIGHT: ");
    walk_tree_root_left_right(root);

    printf("\nLEFT->RIGHT->ROOT: ");
    walk_tree_left_right_root(root);

    printf("\n===============================\n");
    task_3(root, 200);
    print_tree(root, 0);

    free_tree(root);
    free(newItem);

    return 0;
}