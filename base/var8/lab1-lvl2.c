#include <stdio.h>
#include <string.h>

const char *str = "eogng-4343,534-76,54.429wrguih5632dff787w,,,,,,.545345.3536.33323wegw45y.35+3434f2wef.45-fef43";
int main()
{
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        double d;
        if (sscanf(&str[i], "%lf", &d) > 0) {
            int j = i + 1;
            int pc = 0;
            while (j < len && ((str[j] >= '0' && str[j] <= '9') || str[j] == '.' || str[j] == ',')) {
                if (str[j] == '.' || str[j] == ',') ++pc;
                if (pc > 1) break;
                ++j;
            }
            int substr_len = j - i;
            char buf[substr_len + 1];
            strncpy(buf, &str[i], substr_len);
            buf[substr_len] = 0;
            printf("%s\n", buf);
            break;
        }
    }
    return 0;
}
