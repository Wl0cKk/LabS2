#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "bone chicken six good live practice spawn quick tube agree bless gold venue cargo round \
    bridge cost plastic mad regret option decorate print title";
    int k;

    printf("Input K: "); scanf("%d", &k); puts("");

    if (str[k] == ' ') {
        int range = 0;
        printf("subline #1: ");
        for (int i = 0; i < strlen(str); i++) {
            if (i < k) {
                printf("%c", str[i]);
            } else if (i == k) {
                printf("\nsubline #2: ");
            } else {
                printf("%c", str[i]);
            }
        }
    } else {
        int s = k;
        while (str[s] != ' ' && s > 0) {
            s--;
        }

        printf("subline #1: ");
        for (int i = 0; i < s; i++) {
            printf("%c", str[i]);
        }

        printf("\nsubline #2: ");
        for (int i = s + 1; i < strlen(str); i++) {
            printf("%c", str[i]);
        }
    }

    return 0;
}

