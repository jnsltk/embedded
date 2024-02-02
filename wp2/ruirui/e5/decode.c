#include <stdio.h>

#define TO_HEX -'A' + 10

int main(int argc, char **argv) {
    if (argc != 2)
        return fprintf(stderr, "1 argument expected\n");

    char *c = argv[1];
    unsigned char n = 0;

    do {
        n <<= 4;

        if (*c >= 'A' && *c <= 'F')
            n |= (*c + TO_HEX);
        else if (*c >= '0' && *c <= '9')
            n |= (*c - '0');
        else
            return fprintf(stderr, "Invalid input: %c\n", *c);
    } while (*(++c) != '\0');
    printf("%hhu\n", n);
}