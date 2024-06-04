#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

Stack* push(Stack *top, int data) {
    Stack *newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

Stack* pop(Stack *top, int *data) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    Stack *temp = top;
    *data = top->data;
    top = top->next;
    free(temp);
    return top;
}

void displayStack(Stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Stack *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int findMaxElement(Stack *top) {
    int max = top->data;
    Stack *current = top;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

Stack* sortStack(Stack* top) {
    Stack *sortedStack = NULL;
    while (top != NULL) {
        int data;
        top = pop(top, &data);

        while (sortedStack != NULL && data < sortedStack->data) {
            int temp;
            sortedStack = pop(sortedStack, &temp);
            top = push(top, temp);
        }
        sortedStack = push(sortedStack, data);
    }
    return sortedStack;
}

Stack* solveTask(Stack **top) {
    int max = findMaxElement(*top);
    Stack *newStack = NULL;
    Stack *sortedStack = NULL;
    int data;

    while ((*top) != NULL && (*top)->data != max) {
        *top = pop(*top, &data);
        newStack = push(newStack, data);
    }

    if (*top != NULL) {
        *top = pop(*top, &data);
    }

    while (*top != NULL && (*top)->data != data) {
        *top = pop(*top, &data);
        sortedStack = push(sortedStack, data);
    }

    *top = sortStack(sortedStack);

    return newStack;
}

int main() {
    Stack *top = NULL;
    int data;
    top = push(top, -67);
    top = push(top, 49);
    top = push(top, 73);
    top = push(top, -100);
    top = push(top, 4);
    top = push(top, -7);
    top = push(top, 98);
    top = push(top, 14);
    top = push(top, -2);
    printf("Original Stack: ");
    displayStack(top);

    Stack *transferredStack = solveTask(&top);

    printf("Transferred Stack: ");
    if (transferredStack != NULL) {
        printf("%d\n", transferredStack->data);
    }

    printf("Sorted Stack: ");
    displayStack(top);

    return 0;
}
