#include "stdlib.h"
#include "memory.h"
#include "stdbool.h"

typedef struct {
    int data[100];
    int top = 0;
} UintStack;

void init_stack(UintStack* stack) {
    memset(stack->data, 0, sizeof(stack->data));
    stack->top = 0;
}

bool stack_push(UintStack* stack, int v) {
    if (stack->top >= 100) {
        return false;
    }
    stack->data[stack->top++] = v;
    return true;
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

void task_6(UintStack* stack) {
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
    int temp = stack->data[minIndex];
    stack->data[minIndex] = stack->data[maxIndex];
    stack->data[maxIndex] = temp;
}

int main() {
    UintStack s; init_stack(&s);
    stack_push(&s, 42);
    stack_push(&s, 100);
    stack_push(&s, 5);
    stack_push(&s, 7);
    print_stack(&s);
    task_6(&s);
    print_stack(&s);
    return 0;
}