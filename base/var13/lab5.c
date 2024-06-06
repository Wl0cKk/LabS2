#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>


struct ListItem{
    int value;
    struct ListItem* prev;
    struct ListItem* next;
};

typedef struct ListItem ListItem;

typedef struct {
    ListItem* head;
    ListItem* tail;
} BiDirList;


ListItem* create_item(int value) {
    ListItem* newItem = (ListItem*)malloc(sizeof(ListItem));
    newItem->value = value;
    return newItem;
}

void list_push_back(BiDirList* list, int value);

void init_list(BiDirList* list) {
    list->head = NULL;
    list->tail = NULL;
    for (int i = 0; i < 15; ++i) {
        list_push_back(list, rand() % 101 - 50);
    }
}

void list_push_back(BiDirList* list, int value) {
    ListItem* newItem = create_item(value);
    if (list->tail != NULL) {
        list->tail->next = newItem;
    }
    newItem->prev = list->tail;
    list->tail = newItem;

    if (list->head == NULL) {
        list->head = newItem;
    }
}

void list_push_front(BiDirList* list, int value) {
    ListItem* newItem = create_item(value);
    newItem->next = list->head;
    if (list->head) {
        list->head->prev = newItem;
    }
    list->head = newItem;

    if (list->tail == NULL) {
        list->tail = newItem;
    }
}

void print_list_forward(BiDirList* list) {
     ListItem* current = list->head;
     while (current) {
        printf("%d ", current->value);
        current = current->next;
     }
     printf("\n");
}

void print_list_backward(BiDirList* list) {
     ListItem* current = list->tail;
     while (current) {
        printf("%d ", current->value);
        current = current->prev;
     }
     printf("\n");
}

void list_del_item(BiDirList* list, ListItem* item) {
    ListItem* prev = item->prev;
    ListItem* next = item->next;
    if (prev != NULL) prev->next = next;
    if (next != NULL) next->prev = prev;
    if (list->head == item) {
        list->head = next;
    }
    if (list->tail == item) {
        list->tail = prev;
    }
    free(item);
}

ListItem* list_search(BiDirList* list, int value) {
    ListItem* current = list->head;
    while (current) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void list_del_items_with_value(BiDirList* list, int value) {
    while (true) {
        ListItem* item = list_search(list, value);
        if (item != NULL) {
            list_del_item(list, item);
        } else {
            break;
        }
    }
}

void free_list(BiDirList* list) {
    ListItem* current = list->head;
    while (current) {
        ListItem* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

void task_13(BiDirList* list) {
    int max = -1000000000;
    ListItem* current = list->head;
    while (current) {
        if (current->value > max) {
            max = current->value;
        }
        current = current->next;
    }
    list_del_items_with_value(list, max);
}

int main() {
    BiDirList list;
    init_list(&list);
    print_list_forward(&list);
    print_list_backward(&list);
    printf("\n");

    list_push_front(&list, 100);
    list_push_back(&list, 100);
    print_list_forward(&list);
    printf("\n");

    task_13(&list);
    print_list_forward(&list);
    free_list(&list);
    return 0;
}
