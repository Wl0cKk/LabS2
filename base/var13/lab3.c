#include "stdio.h"
#include "math.h"

double recursive(double x, unsigned int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return pow(recursive(x, n / 2), 2);
    } else {
        return x * recursive(x, n - 1);
    }
}

double iterative(double x, unsigned int n) {
    double res = 1;
    while (n > 0) {
        if (n % 2 == 0) {
            x *= x;
            n /= 2;
        } else {
            res *= x;
            --n;
        }
    }
    return res;
}

int main() {
    double x = 23;
    int n = 5;
    printf("Recursive: %.lf\n", recursive(x, n));
    printf("Iterative: %.lf\n", iterative(x, n));
    return 0;
}