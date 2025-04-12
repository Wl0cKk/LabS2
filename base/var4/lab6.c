#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define RECORDS_COUNT 8

typedef struct {
    char name[20];
    int passport;
} Record;

typedef struct Node {
    Record* record;
    struct Node *left, *right;
} Node;

Record* create_record(const char* name, int passport) {
    Record* record = malloc(sizeof(Record));
    strncpy(record->name, name, sizeof(record->name) - 1);
    record->name[sizeof(record->name) - 1] = '\0';
    record->passport = passport;
    return record;
}

Node* create_leaf(Record* record) {
    Node* node = malloc(sizeof(Node));
    node->record = record; node->left = node->right = NULL;
    return node;
}

void add_leaf(Node* root, Record* record) {
    Node *prev = NULL, *temp = root;
    while (temp) {
        prev = temp;
        if (record->passport == temp->record->passport) {
            printf("Duplicate passport: %d\n", record->passport);
            return;
        }
        temp = (record->passport < temp->record->passport) ? temp->left : temp->right;
    }
    temp = create_leaf(record);
    (record->passport < prev->record->passport) ? (prev->left = temp) : (prev->right = temp);
}

void print_tree(Node* root, int level) {
    if (!root) return;
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("\t");
    printf("%d\n", root->record->passport);
    print_tree(root->left, level + 1);
}

Record* sortedRecords[RECORDS_COUNT] = {NULL};
int sortedIndex = 0;

void sort_records_by_passport(Node* root) {
    if (root) {
        sort_records_by_passport(root->left);
        sortedRecords[sortedIndex++] = root->record;
        sort_records_by_passport(root->right);
    }
}

void make_balanced(Node** nodePtr, int n, int k) {
    if (n == k) *nodePtr = NULL;
    else {
        int m = (n + k) / 2;
        *nodePtr = create_leaf(sortedRecords[m]);
        make_balanced(&(*nodePtr)->left, n, m);
        make_balanced(&(*nodePtr)->right, m + 1, k);
    }
}

Record* search_by_passport(Node* node, int passport) {
    return (!node) ? NULL :
           (passport == node->record->passport) ? node->record :
           (passport < node->record->passport) ? search_by_passport(node->left, passport) :
                                                 search_by_passport(node->right, passport);
}

Node* remove_record_by_passport(Node* root, int passport) {
    Node *del = root, *prevDel = NULL;
    while (del && del->record->passport != passport) {
        prevDel = del;
        del = (del->record->passport > passport) ? del->left : del->right;
    }
    if (!del) {
        printf("\nCannot find a record with passport %d\n", passport);
        return root;
    }
    Node *replacing = !del->right ? del->left : (!del->left ? del->right : NULL);
    if (del->left && del->right) {
        Node *prevReplacing = del, *replacing = del->left;
        while (replacing->right) {
            prevReplacing = replacing;
            replacing = replacing->right;
        }
        if (prevReplacing != del) {
            prevReplacing->right = replacing->left;
            replacing->left = del->left;
        }
        replacing->right = del->right;
    }
    root = (del == root) ? replacing : (del->record->passport < prevDel->record->passport ? (prevDel->left = replacing) : (prevDel->right = replacing));
    free(del);
    return root;
}

void walk_tree_left_root_right(Node* node) {
    if (node) {
        walk_tree_left_root_right(node->left);
        printf("%d ", node->record->passport);
        walk_tree_left_root_right(node->right);
    }
}

void free_tree(Node* node) {
    if (node) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int task_depth(Node* node) {
    return (!node) ? 0 : 1 + (task_depth(node->left) > task_depth(node->right) ? task_depth(node->left) : task_depth(node->right));
}

int main() {
    Record records[] = {{"John", 100}, {"Doe", 101}, {"Eric", 200}, {"Hanna", 900}, {"Diya", 550},
                        {"Charles", 180}, {"Nora", 150}, {"Cian", 165}};
    Node* root = create_leaf(&records[0]);
    for (int i = 1; i < RECORDS_COUNT; i++) add_leaf(root, &records[i]);

    printf("\nUnbalanced tree:\n");
    print_tree(root, 0);

    sort_records_by_passport(root);
    make_balanced(&root, 0, RECORDS_COUNT);
    printf("\nBalanced tree:\n");
    print_tree(root, 0);

    Record* newRecord = create_record("Gamble", 777);
    add_leaf(root, newRecord);
    printf("\nTree after adding:\n");
    print_tree(root, 0);

    int to_find = 101;
    Record* record = search_by_passport(root, to_find);
    printf(record ? "\nFound record with passport %d: '%s'\n" : "\nCannot find a record with passport == %d\n", record->passport, record->name);
    
    int to_del = 180;
    root = remove_record_by_passport(root, to_del);
    printf("\nTree after deleting record with passport %d:\n", to_del);
    print_tree(root, 0);
    
    printf("\nLEFT->ROOT->RIGHT: ");
    walk_tree_left_root_right(root);
    printf("\nMaximum depth of the tree: %d\n", task_depth(root));
     
    free_tree(root);
    return 0;
}
