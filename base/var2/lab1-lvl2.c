#include <stdio.h>

int main() {
    char str[] = "00000111100000111111";
    char cchr = str[0];
    int cc = 1;
    int minc = 100;
    char minchr = str[0];
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == cchr) {
            cc++;
        } else {
            if (cc < minc) {
                minc = cc;
                minchr = cchr;
            }
            cchr = str[i];
            cc = 1;
        }
    }
    if (cc < minc) {
        minc = cc;
        minchr = cchr;
    }
    printf("Shortest group consist of: ");
    for (int i = 0; i < minc; i++) {
        printf("%c", minchr);
    }
    printf("\n");
    return 0;
}
