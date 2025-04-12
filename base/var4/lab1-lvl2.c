#include <stdio.h>

int main() {
    char str[] = "010010111110011110000";
    char initchr = str[0];
    int c = 1;
    for (int i = 1; str[i] != '\0'; ++i) {
        if (str[i] == initchr) {
            c++;
        } else {
            if (!(c & 1))  {
                for (int j = 0; j < c; ++j) printf("%c", initchr);
                printf("\n");
            }
            initchr = str[i];
            c = 1;
        }
    }
    if (!(c & 1))  {
        for (int j = 0; j < c; ++j) printf("%c", initchr);
        printf("\n");
    }
    return 0;
}
