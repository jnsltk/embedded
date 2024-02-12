#include <stdio.h>
#include <string.h>

#define MAX_CHAR 20

void copy_str(char *out, char *in);

int main(void) {
    char a[MAX_CHAR], b[MAX_CHAR], c[MAX_CHAR];

    char *result;
    if ((result = fgets(a, MAX_CHAR, stdin)) == NULL) {
        printf("Error reading input!\n");
    }

    strcpy(b, a);
    copy_str(c, a);

    printf("Original input: %s\n", a);
    printf("Copied with strcpy: %s\n", b);
    printf("Copied with ma own method: %s\n", c);
}

void copy_str(char *out, char *in) {
    do {
        *out = *in;
        out++;
    } while (*(++in) != '\0');

    *out = '\0';
}
