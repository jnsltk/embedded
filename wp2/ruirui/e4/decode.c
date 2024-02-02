#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2)
        return fprintf(stderr, "1 argument expected\n");

    char n = 0, *c = argv[1];

    do {
        n <<= 4;

        if (*c >= 'A' && *c <= 'F')
            n |= (*c - 55);
        else if (*c >= '0' && *c <= '9')
            n |= (*c - '0');
        else
            return fprintf(stderr, "Invalid input\n");
    } while (*(++c) != '\0');

    printf("Name          Value\n---------------------\n"
           "engine_on       %hhu\n"
           "gear_pos        %hhu\n"
           "key_pos         %hhu\n"
           "break1          %hhu\n"
           "break2          %hhu\n",
           (0b10000000 & n) >> 7, (0b1110000 & n) >> 4, (0b1100 & n) >> 2, (0b10 & n) >> 1,
           0b1 & n);
}