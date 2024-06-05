#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

void task_7(BiDirList* originalList, BiDirList* resultList) {
    ListItem* current = originalList->head;
    ListItem* max_item = originalList->head;
    int max_value = originalList->head->value;

    while (current != NULL) {
        if (current->value > max_value) {
            max_item = current;
            max_value = current->value;
        }
        current = current->next;
    }

    current = originalList->head->next;
    while (current != max_item) {
        add_to_end(resultList, current->value);
        ListItem* temp = current;
        current = current->next;
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }

    if (max_item->prev != NULL) {
        max_item->prev->next = NULL;
    }
    max_item->prev = NULL;
}

int main() {
    srand(time(NULL));
    BiDirList originalList;
    BiDirList resultList;

    init_list(&originalList);
    init_list(&resultList);

    for (int i = 0; i < 10; ++i) {
        add_to_end(&originalList, rand() % 21 - 10);
    }

    print_forward(&originalList);

    task_7(&originalList, &resultList);

    printf("Elements moved to new list:\n");
    print_forward(&resultList);
    print_backward(&resultList);

    return 0;
}
