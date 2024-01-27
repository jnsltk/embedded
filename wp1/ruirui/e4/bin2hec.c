#include <limits.h>
#include <stdio.h>

int main(const int argc, char **argv) {

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("This is a program that converts binary to hexadecimal. Please run without -h and "
               "enter any binary number\n");
        return 0;
    }

    unsigned char c;
    unsigned char n = 0;
    unsigned char i = 0;

    while ((c = getchar()) != '\n') {
        if (c == '1')
            n |= 1;
        else if (c != '0') {
            printf("Invalid number\n");
            return 2;
        }

        if (i == 3) {
            if (n < 10)
                printf("%d", n);
            else
                printf("%c", n + 55);

            i = n = 0;
        } else {
            n <<= 1;
            i++;
        }
    }

    if (i != 0) {
        fprintf(stderr, "Input length must be divisible by four, please add leading zeros\n");
        printf("\n");
        return 2;
    }

    printf("\n");

    return 0;
}