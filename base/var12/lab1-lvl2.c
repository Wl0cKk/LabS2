#include <stdio.h>

int main() {
    char str[] = "crop salmon wait phrase accident jungle vibrant earth crawl chunk olympic throw";
    int k = 8;
    int word_bg = 0;
    
    if (str[k] == ' ') {
        for (int i = k-1; i >= 0; i--) {
            if (str[i] == ' ') {
                word_bg = i;
                break;
            }
        }
        
        for (int i = word_bg + 1; i < k; i++) {
            printf("%c", str[i]);
        }
    } else {
        for (int i = k; i >= 0; i--) {
            if (str[i] == ' ') {
                word_bg = i;
                break;
            }
        }
        word_bg += 1;
        while (str[word_bg] != ' ') {
            printf("%c", str[word_bg]);
            word_bg++;
        }
    }
    return 0;
}
