#include "stdio.h"

int superfastsolution(int item) {
    return item - 1;
}

int recursion(int a[], int st, int end, int item) {
    if (st <= end) {
        int mid = (st + end) / 2;

        if (a[mid] == item) {
            return mid - 1;
        } else if (a[mid] < item) {
            return recursion(a, mid + 1, end, item);
        } else {
            return recursion(a, st, mid - 1, item);
        }
    }
    return 404;
}

int iteration(int a[], int end, int item) {
    int st = 0 ;
    while (st <= end) {
        int mid = (st+end) / 2;

        if (a[mid] == item) {
            return mid - 1;
        } else if(a[mid] < item) {
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return 404;
}

int main() {
    int l = 1;
    int s;
    printf("Input length: "); scanf("%d", &l);
    printf("Input item to search: "); scanf("%d", &s);
    int arr[l];
    for (int i = 1; i < l; ++i ) {
        arr[i] = i;
    }
    printf("Recursive function result: %d\n", recursion(arr, 0, l-1, s));
    printf("Iterative function result: %d\n", iteration(arr, l, s));
    return 0;
}