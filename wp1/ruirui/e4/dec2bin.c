// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 4
// Submission code: 35128211

#include <limits.h>   // includes type size limits library
#include <stdio.h>    // includes standard I/O library
#include <stdlib.h>   // includes stdlib for strtoul

// defines function which reads a number in range from sdin
char getNumber(char *inputStr, unsigned long *output);
// defines function which prints a number as binary
void printAsBin(unsigned long *input, unsigned char size);

// main function of program
int main(const int argc, char **argv) {
    // first argument is -h
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("This is a program that converts numbers to binary. Please run without -h and enter "
               "any positive whole number\n");
        return 0;   // exits program
    }

    unsigned long num;   // defines variable used to store the number read from stdin
    char didParseNum;   // defines variable used to store whether the number was parsed successfully

    if (argc > 1)                                 // if there is at least one argument
        didParseNum = getNumber(argv[1], &num);   // parses the first argument
    else {
        char input[30];                         // allocates char array for storing user input
        fgets(input, sizeof(input), stdin);     // reads a string from stdin
        didParseNum = getNumber(input, &num);   // parses the string
    }

    if (!didParseNum) {   // if the number was not parsed successfully
        printf("Invalid number\n");
        return 2;   // exits program with error code 2
    }

    if (num <= UCHAR_MAX) {              // if number fits in unsigned char
        unsigned char inputChar = num;   // creates unsigned char version of number
        printAsBin(((unsigned long *) &inputChar), sizeof(unsigned char));   // prints as binary
    } else if (num <= USHRT_MAX) {         // if number fits in unsigned short
        unsigned short inputShort = num;   // creates unsigned short version of number
        printAsBin(((unsigned long *) &inputShort), sizeof(unsigned short));   // prints as binary
    } else if (num <= UINT_MAX) {      // if number fits in unsigned int
        unsigned int inputInt = num;   // creates unsigned int version of number
        printAsBin(((unsigned long *) &inputInt), sizeof(unsigned int));   // prints as binary
    } else {   // if number fits in neither unsigned char, unsigned short or unsigned int
        printAsBin(&num, sizeof(unsigned long));   // prints as binary
    }

    return 0;   // exits program
}

// defines function which reads a number in range from sdin
char getNumber(char *inputStr, unsigned long *output) {
    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    *output = strtoul(inputStr, &endptr, 10);   // gets long version of first argument

    // if the number is valid
    return *endptr == '\n' || *endptr == '\0';
}

// defines function which prints a number as binary
void printAsBin(unsigned long *input, const unsigned char size) {
    const char bitAmt = size * 8;   // calculates amount of bits in the number
    // initiates filter for getting most significant bit of n
    const unsigned long filter = (1UL << (bitAmt - 1UL));

    // loops through the bits of the result number
    for (int i = 0; i < bitAmt; i++) {
        // essentially gets the currently most significant bit of n
        const unsigned char bit = (*input & filter) != 0UL;

        printf("%hhu", bit);
        *input <<= 1;   // shift n one step to the left
    }

    putchar('\n');   // prints newline
}