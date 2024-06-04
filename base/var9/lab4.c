#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data[100];
    int top;
} UintStack;

void init_stack(UintStack* stack) {
    memset(stack->data, 0, sizeof(stack->data));
    stack->top = 0;
}

int stack_push(UintStack* stack, int v) {
    if (stack->top >= 100) {
        return 0;
    }
    stack->data[stack->top++] = v;
    return 1;
}

int stack_pop(UintStack* stack) {
    if (stack->top <= 0) {
        return -1;
    }
    return stack->data[--stack->top];
}

void print_stack(UintStack* stack) {
    for (int i = 0; i < stack->top; ++i) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void task_9(UintStack* stack) {
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 0; i < stack->top; ++i) {
        if (stack->data[i] < stack->data[minIndex]) {
            minIndex = i;
        }
        if (stack->data[i] > stack->data[maxIndex]) {
            maxIndex = i;
        }
    }

    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex > maxIndex) ? minIndex : maxIndex;

    for (int i = start + 1; i < end; ++i) {
        stack->data[i] = 0;
    }

    int newSize = start + 1 + (stack->top - end);

    for (int i = start + 1; i < stack->top; ++i) {
        stack->data[i] = stack->data[i + end - start - 1];
    }

    stack->top = newSize;
}


int main() {
    UintStack s;
    init_stack(&s);
    stack_push(&s, 42);
    stack_push(&s, 100);
    stack_push(&s, 55);
    stack_push(&s, 57);
    stack_push(&s, 52);
    stack_push(&s, -100);
    stack_push(&s, 5);
    stack_push(&s, 7);
    print_stack(&s);
    task_9(&s);
    print_stack(&s);
    return 0;
}

