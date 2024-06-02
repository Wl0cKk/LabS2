#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
    char str[] = "crop salmon wait phrase accident jungle vibrant earth crawl chunk olympic throw";
    int k = 4;
    int *words_pos = malloc(sizeof(int) * strlen(str));;
    int words_count = 0;

    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            words_pos[words_count] = i;
            words_count++;
            if (str[i] == '\0') {
                break;
            }
        }
    }

    int word_index = 1;
    for (int i = 0; i < words_count; i++) {
        if (k <= words_pos[i]) {
            break;
        }
        word_index++;
    }

    printf("\nWord order number: %d\n", word_index);

    free(words_pos);
    return 0;
}
