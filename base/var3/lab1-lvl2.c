#include "stdio.h"

int main() {
    char str[] = "010010111110011110000";
    char initchr = str[0];
    int c = 1;
    int max = 1;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == initchr) {
            c++;
        } else {
            initchr = str[i];
            c = 1;
        }
        if (c > max) max = c;
    }
    printf("Longest group length: %d", max);
    return 0;
}