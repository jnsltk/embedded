#include <stdio.h>
#include <string.h>

#define MAX_INPUT 20

void copyString(char *dest, char *src) {
    do {
        *dest = *src;
        dest++;
    } while (*(++src) != '\0');

    *dest = '\0';
}

int main() {
    char input[MAX_INPUT], c1[MAX_INPUT], c2[MAX_INPUT];
    char *end = fgets(input, MAX_INPUT, stdin);

    strcpy(c1, input);
    copyString(c2, input);

    printf("Original:   %s\n", input);
    printf("strcpy:     %s\n", c1);
    printf("copyString: %s\n", c2);
}