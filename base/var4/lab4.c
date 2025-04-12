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
    if (stack->top >= 100) return 0;
    stack->data[stack->top++] = v;
    return 1;
}

int stack_pop(UintStack* stack) {
    if (stack->top <= 0) return -1;
    return stack->data[--stack->top];
}

void print_stack(UintStack* stack) {
    for (int i = 0; i < stack->top; ++i) printf("%d ", stack->data[i]);
    printf("\n");
}

void task_4(UintStack* stack) {
    if (stack->top < 2) return;
    int temp = stack->data[0];
    stack->data[0] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = temp;
}

int main() {
    UintStack s;
    init_stack(&s);
    int arr[] = {5, 12, 56, 47, 239, 100, -5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        stack_push(&s, arr[i]);
    printf("Before swapping:\n");
    print_stack(&s);
    task_4(&s);
    printf("After swapping:\n");
    print_stack(&s);
    return 0;
}
