#include <stdio.h>

double iteration(int n) {
    double result = 1.0;

    if (n == 0) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        result = 1 / (i + result);
    }

    return result;
}

double recursion(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1 / (n + 0.5);
    } else {
        return 1 / (n + recursion(n - 1));
    }
}

int main() {
    int n = 3;
    printf("Recursion(%d) = %.10lf\n", n, recursion(n));
    printf("Iteration(%d) = %.7lf\n", n, iteration(n));

    return 0;
}
