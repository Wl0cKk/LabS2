#include "stdio.h"
#include "math.h"

double recursive(int n, double res) {
    if (n == 0) {
        return res;
    } else {
        return recursive(n - 1, sqrt(n + res));
    }
}

double iterative(int n) {
    double res = 0.0;
    for (int i = n; i > 0; --i) {
        res = sqrt(i + res);
    }
    return res;
}

int main() {
    int n = 110;
    printf("Recursive n = %d: %.52lf\n", n, recursive(n, 0.0));
    printf("Iterative n = %d: %.52lf\n", n, iterative(n));
    return 0;
}
