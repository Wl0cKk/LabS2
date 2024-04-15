#include "stdio.h"

int main() {
    char str[] = "00000111110101010111110000001110000000000";
   int i = 1, cc = 1, cg = 0, pc = str[0];
    while (1) {
        if (str[i] != pc) {
            if (cc == 5) {
                ++cg;
            }
            cc = 0;
            pc = str[i];
        }
        ++cc;
        if ((str[i++] == '\0')) break;
    }
    printf("Result: %d", cg);
    return 0;
}