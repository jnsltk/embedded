// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 4
// Submission code:

#include <limits.h>   // includes type size limits library
#include <stdio.h>    // includes standard I/O library

// main function of program
int main(const int argc, char **argv) {

    // first argument is -h
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("This is a program that converts binary to hexadecimal. Please run without -h and "
               "enter any binary number\n");
        return 0;   // exits program
    }

    unsigned char c;       // defines variable used to store the character read from stdin
    unsigned char n = 0;   // defines variable used to store the 4bit number read from stdin
    unsigned char i = 0;   // defines variable used to store the amount of bits read from stdin

    // while the stdin is not a newline character
    while ((c = getchar()) != '\n') {
        if (c == '1')          // if the character is a 1
            n |= 1;            // sets the first bit of n to 1
        else if (c != '0') {   // if the character is not a 0
            printf("Invalid number\n");
            return 2;   // exits program with error code 2
        }

        if (i == 3) {     // if has read a set of 4 bits
            if (n < 10)   // if the number is less than 10
                printf("%d", n);
            else   // if the number is greater than 10
                   // prints the character representing the number in hexadecimal
                printf("%c", n + 55);

            i = n = 0;   // resets the amount of bits read and the number being read
        } else {         // if has not read a set of 4 bits
            n <<= 1;     // shifts the bits of n to the left by 1
            i++;         // increments the counter of amount of bits read
        }
    }

    putchar('\n');   // prints newline

    if (i == 0)
        return 0;   // exits program
    // if the amount of bits read is not divisible by four (meaning result is wrong)
    else {
        fprintf(stderr, "Input length must be divisible by four, please add leading zeros\n");
        return 2;   // exits program with error code 2
    }
}