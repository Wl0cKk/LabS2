#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>


const int STACK_CAPACITY = 10;

typedef struct {
    int data[STACK_CAPACITY];
    int top;
} IntStack;


bool stack_push(IntStack* stack, int v);

void init_stack(IntStack* stack) {
    stack->top = 0;
    for (int i = 0; i < STACK_CAPACITY; ++i) {
        stack_push(stack, rand() % 101 - 50);
    }
}
bool stack_push(IntStack* stack, int v) {
    if (stack->top >= STACK_CAPACITY) {
        return false;
    }
    stack->data[stack->top++] = v;
    return true;
}
int stack_pop(IntStack* stack) {
    if (stack->top <= 0) {
        return -1;
    }
    return stack->data[--stack->top];
}

void sort_stack(IntStack* stack) {
    if (stack->top <= 0) {
        return;
    }
    for (int i = 0; i < stack->top - 1; ++i) {
        for (int j = i + 1; j < stack->top; ++j) {
            if (stack->data[i] > stack->data[j]) {
                int temp = stack->data[i];
                stack->data[i] = stack->data[j];
                stack->data[j] = temp;
            }
        }

    }
}

void print_stack(IntStack* stack) {
    for (int i = 0; i < stack->top; ++i) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
int main() {
    IntStack s;
    init_stack(&s);
    print_stack(&s);

    sort_stack(&s);
    print_stack(&s);

    stack_pop(&s);
    print_stack(&s);

    return 0;
}