#include <stdio.h>

double recursive(int n) {
    if (n == 2) {
        return 2.0/1 * 2.0/3;
    }

    return recursive(n - 2) * ((2.0*n-2)/(2.0*n-3)) * (2.0*n/(2.0*n+1));
}

double iterative(int n) {
    double result = 2.0/1 * 2.0/3;
    for (int i = 4; i <= n; i += 2) {
        result *= ((2.0*i-2)/(2.0*i-3)) * (2.0*i/(2.0*i+1));
    }
    
    return result;
}

int main() {
    int n = 4;

    printf("Recursive: %.5lf\n", recursive(n));
    printf("Iterative: %.5lf\n", iterative(n));

    return 0;
}
