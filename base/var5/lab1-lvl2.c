#include "stdio.h"
#include "stdbool.h"

int main() {
    char str[] = "10101110110111";
    bool _switch = false;
    int count = 0;
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        _switch = str[i] == '1' ? true : false;
        if (_switch) {
            count++;
        }
        if (!_switch) {
            if (count % 2 == 1) {
                res += count;
            }
            count = 0;
        }
    }
    if (count % 2 == 1) {
        res += count;
    }

    printf("Result: %d\n", res);
    return 0;
}
