#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

const char* str = "5 90 1 -768 493 134 1 50";

int main() {
    const char* temp = str;
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    count++;

    int* digits = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        sscanf(temp, "%d", &digits[i]);
        temp = strchr(temp, ' ') + 1;
    }

    quickSort(digits, 0, count - 1);

    for (int i = 0; i < count; i++) {
        printf("%d ", digits[i]);
    }

    free(digits);
    return 0;
}
