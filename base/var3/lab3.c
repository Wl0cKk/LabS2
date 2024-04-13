#include "stdio.h"

int recursion(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return recursion(n, m % n);
    }
    return m;
}

int iteration(int m, int n) {
    int r;
    while (n != 0) {
        r = n;
        n = m % n;
        m = r;
    }
    return m;
}

int main() {
    int m = 660;
    int n = 10;
    printf("Recursive function result: %d\n", recursion(m, n));
    printf("Iterative function result: %d\n", iteration(m, n));
    return 0;
}