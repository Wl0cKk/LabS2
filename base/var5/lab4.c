#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Stack {
    int data;
    struct Stack* next;
};

typedef struct Stack Stack;

Stack* push(Stack* top, int data) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->data = data;
    newStack->next = top;
    return newStack;
}

Stack* pop(Stack* top, int* data) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    Stack* temp = top;
    *data = top->data;
    top = top->next;
    free(temp);
    return top;
}

void printStack(Stack* top) {
    Stack* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void solveTask(Stack** top) {
    Stack* prev = NULL;
    Stack* current = *top;

    while (current != NULL) {
        int lastDigit = abs(current->data) % 10;
        if (lastDigit == 5) {
            if (prev == NULL) {
                *top = current->next;
                free(current);
                current = *top;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

Stack* sortStack(Stack* top) {
    Stack* sorted = NULL;

    while (top != NULL) {
        int temp;
        top = pop(top, &temp);

        if (sorted == NULL || sorted->data >= temp) {
            sorted = push(sorted, temp);
        } else {
            Stack* tempStack = NULL;

            while (sorted != NULL && sorted->data < temp) {
                int data;
                sorted = pop(sorted, &data);
                tempStack = push(tempStack, data);
            }

            sorted = push(sorted, temp);

            while (tempStack != NULL) {
                int data;
                tempStack = pop(tempStack, &data);
                sorted = push(sorted, data);
            }
        }
    }

    return sorted;
}

int main() {
    Stack* stack = NULL;
    Stack* positiveStack = NULL;
    Stack* negativeStack = NULL;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        stack = push(stack, rand() % 201 - 100);
    }

    printf("Original Stack: ");
    printStack(stack);

    solveTask(&stack);
    printf("Stack after removing numbers ending in 5: ");
    printStack(stack);

    printf("Sorted Stack: ");
    printStack(sortStack(stack));

    return 0;
}
