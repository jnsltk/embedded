#include <limits.h>
#include <stdio.h>
#include <stdlib.h>   // includes stdlib for

char getNumber(char *inputStr, unsigned long *output);
void printAsBin(unsigned long *input, unsigned char size);

int main(const int argc, char **argv) {
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("This is a program that converts numbers to binary. Please run without -h and enter "
               "any positive whole number\n");
        return 0;
    }

    unsigned long num;
    char didParseNum;

    if (argc > 1)
        didParseNum = getNumber(argv[1], &num);
    else {
        char input[30];
        fgets(input, sizeof(input), stdin);   // reads a string from stdin with
        didParseNum = getNumber(input, &num);
    }

    if (!didParseNum) {
        printf("Invalid number\n");
        return 2;
    }

    if (num <= UCHAR_MAX) {
        unsigned char inputChar = num;
        printAsBin(((unsigned long *) &inputChar), sizeof(unsigned char));
    } else if (num <= USHRT_MAX) {
        unsigned short inputShort = num;
        printAsBin(((unsigned long *) &inputShort), sizeof(unsigned short));
    } else if (num <= UINT_MAX) {
        unsigned int inputInt = num;
        printAsBin(((unsigned long *) &inputInt), sizeof(unsigned int));
    } else {
        printAsBin(&num, sizeof(unsigned long));
    }

    return 0;
}

// defines function which reads a number in range from sdin
char getNumber(char *inputStr, unsigned long *output) {
    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    *output = strtoul(inputStr, &endptr, 10);   // gets long version of first argument

    // if the number is valid
    return *endptr == '\n' || *endptr == '\0';
}

void printAsBin(unsigned long *input, const unsigned char size) {
    const char bitAmt = size * 8;
    const unsigned long filter = (1UL << (bitAmt - 1UL));

    // loops through the bits of the result number
    for (int i = 0; i < bitAmt; i++) {
        // essentially gets the currently most significant bit of n
        const unsigned char bit = (*input & filter) != 0UL;

        printf("%hhu", bit);
        *input <<= 1;   // shift n one step to the left
    }

    printf("\n");
}