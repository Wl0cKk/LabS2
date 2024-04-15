#include "stdio.h"

int main() {
    char str[] = "10101010@10,01#101001     10 11111 00000 10101 01010 1 00000";
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '1' || str[i] == '0') {
            count += 1;
        } else {
            count = 0;
        }
    }
    printf("Result: %d", count);
    return 0;
}