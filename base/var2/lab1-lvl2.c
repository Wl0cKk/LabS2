#include "stdio.h"

int main() {
    char str[] = "00000111110101010111110000001110000000000";
    char statement = str[0];
    int count = 0;
    int groups = 0;
    for (int i = 0; str[i] != '\0'; ++i) { 
        if (str[i] == statement) {
            count++;
        } else {
            if (count == 5) {
                groups++;
            }
            statement = str[i];
            count = 1;
        }
    }
    if (count == 5) {
        groups++;
    }
    printf("Result: %d", groups);
    return 0;
}