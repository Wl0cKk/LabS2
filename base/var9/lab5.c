#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_at_beginning(DoublyLinkedList* list, int value) {
    Node* newNode = create_node(value);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insert_at_end(DoublyLinkedList* list, int value) {
    Node* newNode = create_node(value);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void print_from_beginning(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_from_end(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void task_9_dll(DoublyLinkedList* list) {
    Node* current = list->head;

    int minIndex = 0;
    int maxIndex = 0;
    int currentIndex = 0;

    while (current != NULL) {
        if (current->data < list->head->data) {
            minIndex = currentIndex;
        }
        if (current->data > list->head->data) {
            maxIndex = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }

    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex > maxIndex) ? minIndex : maxIndex;

    current = list->head;
    for (int i = 0; i < start; ++i) {
        current = current->next;
    }

    Node* temp;
    for (int i = start + 1; i < end; ++i) {
        temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        free(temp);
    }

    list->tail = current;
}

int main() {
    DoublyLinkedList dll = {NULL, NULL};

    insert_at_end(&dll, 42);
    insert_at_end(&dll, 100);
    insert_at_end(&dll, 55);
    insert_at_end(&dll, 57);
    insert_at_end(&dll, 52);
    insert_at_end(&dll, -100);
    insert_at_end(&dll, 5);
    insert_at_end(&dll, 7);

    printf("List from the beginning: ");
    print_from_beginning(&dll);
    
    task_9_dll(&dll);

    printf("Modified list from the beginning: ");
    print_from_beginning(&dll);

    // Теперь можешь опробовать другие функции, например, insert_at_beginning и print_from_end

    return 0;
}
