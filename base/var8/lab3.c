#include "stdio.h"

int max_recursive(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    } else {
        int prev_max = max_recursive(arr, n - 1);
        return (prev_max > arr[n - 1]) ? prev_max : arr[n - 1];
    }
}

int max_iterative(int arr[], int n) {
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    return max_element;
}

int main() {
    int arr[] = {2, 5, 8, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Recursive: %d\n", max_recursive(arr, n));
    printf("Iterative: %d\n", max_iterative(arr, n));
    return 0;
}