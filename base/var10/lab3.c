#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int recursive(int *arr, int start, int end) {
    if (start == end) {
        return arr[end];
    }

    int mid = (start + end) / 2;

    int max1 = recursive(arr, start, mid);
    int max2 = recursive(arr, mid+1, end);

    return (max1 > max2) ? max1 : max2;
}

int iterative(int *arr, int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        int max1 = arr[start];
        for (int i = start + 1; i <= mid; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int max2 = arr[mid + 1];
        for (int i = mid + 2; i <= end; i++) {
            if (arr[i] > max2) {
                max2 = arr[i];
            }
        }
        if (max1 > max2) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return arr[end];
}

int* generateRandomArray(int n) {
    srand(time(NULL));
    int* arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }

    return arr;
}

int main() {
    int n = 20;
    int *arr = generateRandomArray(n);
    
    printf("\nArray:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    printf("\nRecursive n = %d: MAX: %d\n", n, recursive(arr, 0, n - 1));
    printf("\nIterative n = %d: MAX: %d\n\n", n, iterative(arr, n));
    
    free(arr);
    return 0;
}
