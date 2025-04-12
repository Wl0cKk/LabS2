#include <stdio.h>

int fib_r(int n) { 
    return n <= 1 ? n : fib_r(n-1) + fib_r(n-2); 
}

int fib_i(int n) {
    if (n <= 1) return n;    
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        b = a + b;
        a = b - a;
    }
    return b;
}

int main() {
    int n = 40;
    printf("\nrecursion: %d\n", fib_r(n));
    printf("\niterative: %d\n", fib_i(n));
    return 0;
}
