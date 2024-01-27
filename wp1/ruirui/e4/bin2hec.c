#include <limits.h>
#include <stdio.h>

char getNumber(unsigned long *output);
void printAsHex(unsigned long *input, const unsigned char size);

int main() {
    unsigned long input = 0;
    if (!getNumber(&input)) {
        fprintf(stderr, "Invalid number\n");
        return 2;
    }

    if (input <= UCHAR_MAX) {
        unsigned char inputChar = input;
        printAsHex(((unsigned long *) &inputChar), sizeof(unsigned char));
    } else if (input <= USHRT_MAX) {
        unsigned short inputShort = input;
        printAsHex(((unsigned long *) &inputShort), sizeof(unsigned short));
    } else if (input <= UINT_MAX) {
        unsigned int inputInt = input;
        printAsHex(((unsigned long *) &inputInt), sizeof(unsigned int));
    } else {
        printAsHex(&input, sizeof(unsigned long));
    }

    return 0;
}

// defines function which reads a number in range from sdin
char getNumber(unsigned long *output) {

    char inputStr[70];   // reserves char array used to temporarily store the string the user enters
    fgets(inputStr, sizeof(inputStr), stdin);   // reads a string from stdin with

    char *c = inputStr;
    unsigned long mask = (1UL << (sizeof(unsigned long) * 8UL - 1UL));

    do {
        if (*c == '1') {
            *output |= mask;
        }

        mask >>= 1;
        c++;

        if (mask == 0)
            return 0;
    } while (*c != '\n');   // while the string has characters

    while (mask != 0) {
        mask >>= 1;
        *output >>= 1;
    }

    return 1;
}

void printAsHex(unsigned long *input, const unsigned char size) {
    for (int i = size * 2 - 4; i >= 0; i--) {
        const unsigned long mask = 0b1111UL << (i * 4);
        const unsigned char output = (*input & mask) >> (i * 4);

        if (output < 10)
            printf("%hhu", output);
        else
            printf("%c", output + 55);
    }

    printf("\n");
}