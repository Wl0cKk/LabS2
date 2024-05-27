#include "stdio.h"
#include "string.h"

int main() {
    char str[] = "eogng -7654,456787,,,,,,.545345.3536.3wegw45y.35+3434f2wef.45-fef43";
    int precision = 2;

    char cleanedStr[strlen(str)];
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '+' || str[i] == '-') {
            cleanedStr[j++] = str[i];
        }
    }
    cleanedStr[j] = '\0';
    double d;
    if (sscanf(cleanedStr, "%lf", &d) > 0) {
        printf("%.*lf", precision, d);
    } 
    return 0;
}
