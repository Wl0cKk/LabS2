#include <stdio.h>
#include <string.h>

const char *str = "eogng -4343.534 -76,54.429wrguih5632dff787w,,,,,,.545345.3536.33323wegw45y.35+3434f2wef.45-fef43";
const int fraction = 2;

int main() {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        double d;
        if (sscanf(&str[i], "%lf", &d) > 0) {
            printf("%.*lf", fraction, d);
            break;
        }
    }
    return 0;
}
