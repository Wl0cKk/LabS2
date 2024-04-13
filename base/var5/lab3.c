#include "stdio.h"
#include "stdlib.h"

int ackermann_r(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann_r(m - 1, 1);
    } else {
        return ackermann_r(m - 1, ackermann_r(m, n - 1));
    }
}

int ackermann_i(int m, int n) {
    int* value = (int*)malloc(sizeof(int) * 100);
    int top = -1;
    value[++top] = m;
    while (top != -1) {
        m = value[top--];

        if (m == 0) {
            n += m + 1;
        } else if (n == 0) {
            value[++top] = m - 1;
            n = 1;
        } else {
            value[++top] = m - 1;
            value[++top] = m;
            n -= 1;
        }
    }
    free(value);
    return n;
}

int main() {
    int m = 2;
    int n = 2;
    printf("Recursive function result: %d\n", ackermann_r(m, n));
    printf("Iterative function result: %d\n", ackermann_i(m, n));
    return 0;
}