#include <stdio.h>
#include <math.h>

double f(double x) {
    return 7 * sin(2 * x);
}

double bisection_recursive(double a, double b, double epsilon) {
    double c = (a + b) / 2;
    if (fabs(b - a) < epsilon) {
        return c;
    }
    if (f(c) * f(a) < 0) {
        return bisection_recursive(a, c, epsilon);
    } else {
        return bisection_recursive(c, b, epsilon);
    }
}

double bisection_iterative(double a, double b, double epsilon) {
    double c = (a + b) / 2;
    while (fabs(b - a) >= epsilon) {
        c = (a + b) / 2;
        
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a = 2, b = 6, epsilon = 0.01;
    double result_recursive = bisection_recursive(a, b, epsilon);
    double result_iterative = bisection_iterative(a, b, epsilon);
    printf("Recursion: %lf\n", result_recursive);
    printf("Iteration: %lf\n", result_iterative);
    return 0;
}