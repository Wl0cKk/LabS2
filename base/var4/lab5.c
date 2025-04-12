#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

void init_list(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

int insert_front(DoublyLinkedList* list, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head;
    new_node->prev = NULL;
    (list->head) ? (list->head->prev = new_node) : (list->tail = new_node);
    list->head = new_node;
    return 1;
}

int insert_end(DoublyLinkedList* list, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;
    (list->tail) ? (list->tail->next = new_node) : (list->head = new_node);
    list->tail = new_node;
    return 1;
}

void print_list_from_start(DoublyLinkedList* list) {
    Node* curr = list->head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void print_list_from_end(DoublyLinkedList* list) {
    Node* curr = list->tail;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

void solve_task(DoublyLinkedList* list) {
    if (list->head == NULL || list->tail == NULL || list->head == list->tail) return;
    Node* minNode = list->head;
    Node* maxNode = list->head;
    for (Node* curr = list->head; curr ; curr = curr->next) {
        if (curr->data < minNode->data) minNode = curr;
        if (curr->data > maxNode->data) maxNode = curr;
    }
    Node* curr = minNode->next;
    while (curr && curr != maxNode) {
        Node* temp = curr;
        curr = curr->next;
        if (temp->prev) temp->prev->next = curr;
        if (curr) curr->prev = temp->prev;
        free(temp);
    }
}

void free_list(DoublyLinkedList* list) {
    Node* curr = list->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
}

int main() {
    DoublyLinkedList list;
    init_list(&list);
    int arr[] = {5, 12, 56, 47, 239, 100, -5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        insert_end(&list, arr[i]);
    printf("List before solving:\n");
    print_list_from_start(&list);
    print_list_from_end(&list);
    solve_task(&list);
    printf("List after solving:\n");
    print_list_from_start(&list);
    print_list_from_end(&list);
    free_list(&list);
    return 0;
}
