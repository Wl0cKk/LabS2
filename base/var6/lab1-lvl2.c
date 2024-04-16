#include "stdio.h"
#include "stdbool.h"

void OGroupsOfDigits(char str[]) {
    int isdigit = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            printf("%c", str[i]);
            isdigit = true;
        } else {
            if (isdigit) {
                printf("\n");
                isdigit = false;
            }
        }
    }
    puts("\n\n============\n");
}

int main() {
    char str[] = "eogng 7654,456787,,,,,,.545345.3536.3wegw45y.35+3434f2wef.45-fef43";
    puts("\n============\n"); OGroupsOfDigits(str);
    return 0;
}
