#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

    for (int i = 0; i < count; i++) {
        int digit = digits[i];
        if (digit % 2 == 0) {
            printf("%d ", digit);
        }
    }

    free(digits);
    return 0;
}
