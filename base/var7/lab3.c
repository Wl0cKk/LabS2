#include "stdio.h"

double recursive(double a, double x0, int n) {
    if (n == 0) {
        return x0;
    } else {
        return 0.5 * (recursive(a, x0, n - 1) + (a / recursive(a, x0, n - 1)));
    }
}

double iterative(double a, double x0, int iterations) {
    double xn = x0;
    
    for (int i = 0; i < iterations; i++) {
        xn = 0.5 * (xn + (a / xn));
    }
    
    return xn;
}

int main() {
    double a = 16.0;
    double x0 = 0.5 * (1 + a);
    int n = 5;

    printf("Recursive: %f\n", recursive(a, x0, n));
    printf("Iterative: %f\n", iterative(a, x0, n));

    return 0;
}