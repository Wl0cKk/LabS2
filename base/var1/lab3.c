#include "stdio.h"

void recursion(int n, int b) {
    if (n != 0) {
        recursion(n / b, b);
        printf("%d", n % b);
    }
}

void iteration(int n, int b) {
    int res[128];
    int i = 0;
    while (n > 0) {
        res[i] = n % b;
        n /= b;
        ++i;
    }
    for (int j = i - 1; j >= 0; --j) {
        printf("%d", res[j]);
    }
}

int main() {
    printf("Recursive function result: "); recursion(8, 2); printf("\n");
    printf("Iterative function result: "); iteration(8, 2); printf("\n");
    return 0;
}