#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

typedef struct ListItem {
    int value;
    struct ListItem* prev;
    struct ListItem* next;
} ListItem;

typedef struct {
    ListItem* head;
    ListItem* tail;
} BiDirList;

ListItem* create_item(int value) {
    ListItem* item = (ListItem*)malloc(sizeof(ListItem));
    item->value = value;
    item->prev = NULL;
    item->next = NULL;
    return item;
}

void init_list(BiDirList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void add_to_end(BiDirList* list, int value) {
    ListItem* new_item = create_item(value);
    if (list->tail == NULL) {
        list->head = new_item;
        list->tail = new_item;
    } else {
        new_item->prev = list->tail;
        list->tail->next = new_item;
        list->tail = new_item;
    }
}

void print_forward(BiDirList* list) {
    ListItem* current = list->head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_backward(BiDirList* list) {
    ListItem* current = list->tail;
    printf("Backward: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");
}

void task_11(BiDirList* list) {
    ListItem* current = list->head;

    int sum = 0;
    int count = 0;

    while (current != NULL) {
        sum += current->value;
        count++;
        current = current->next;
    }

    if (count > 0) {
        int average = sum / count;
        printf("Average: %d\n", average);
        list->head->value = average;
    }
}

int main() {
    srand(time(NULL));
    BiDirList list;
    init_list(&list);

    for (int i = 0; i < 5; ++i) {
        add_to_end(&list, rand() % 201 - 100);
    }

    print_forward(&list);
    print_backward(&list);

    task_11(&list);

    print_forward(&list);
    print_backward(&list);

    return 0;
}