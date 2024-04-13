#include <stdio.h>

int fib_r(int n) { return n <= 1 ? n : fib_r(n-1) + fib_r(n-2); }

int fib_i(int n) {
    int a, b = 0, 1;
    for (int i = 2; i <= n; ++i) {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

int main() {
    int n = 40;
    printf("\nrecursion: %d\n", fib_r(n));
    printf("\niterative: %d\n", fib_i(n));
    return 0;
}
