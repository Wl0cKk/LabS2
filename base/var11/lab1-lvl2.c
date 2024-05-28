#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char words[] = "bone chicken six good live practice spawn quick tube agree bless gold venue cargo round bridge cost plastic mad regret option decorate print title";
    const char spacer[] = " ";
    char *word = strtok(words, spacer);
    char *sorted_words[25];
    int num_words = 0;

    // Split the input string into individual words
    while (word != NULL) {
        sorted_words[num_words++] = word;
        word = strtok(NULL, spacer);
    }

    // Bubble sort
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = 0; j < num_words - i - 1; j++) {
            if (strcmp(sorted_words[j], sorted_words[j+1]) > 0) {
                char *temp = sorted_words[j];
                sorted_words[j] = sorted_words[j+1];
                sorted_words[j+1] = temp;
            }
        }
    }

    // Print the sorted words
    for (int i = 0; i < num_words; i++) {
        printf("%s ", sorted_words[i]);
    }
    printf("\n");

    return 0;
}


