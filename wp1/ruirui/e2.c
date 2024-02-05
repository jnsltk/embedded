// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 2
// Submission code: 35128211

#include <stdio.h>    // includes I/O library for getChar, putChar
#include <stdlib.h>   // includes stdlib for strtol

// Main function of program
int main(const int argc, const char **argv) {

    /* --------------------- EXIT CONDITIONS -------------------- */

    if (argc == 1) {   // if no argument provided
        printf("Missing argument\n");
        return 0;   // finishes program
    }

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long shiftAmt = strtol(argv[1], &endptr, 10);   // gets long version of first argument

    if (*endptr != '\0') {   // if argument is NaN
        printf("Expected a numeric argument\n");
        return 0;                // finishes program
    } else if (shiftAmt < 0) {   // if negative shift amount
        printf("Expected positive number\n");
        return 0;   // finishes program
    }

    /* -------------------- NORMAL EXECUTION -------------------- */

    char c;   // declares char c used to read from stdin

    while ((c = getchar()) != EOF) {   // while char is not End-Of-File

        // declares char representing start of upper or lower alphabet
        char start;

        if (c >= 'A' && c <= 'Z') {          // if is uppercase letter
            start = 'A';                     // sets start to uppercase A
        } else if (c >= 'a' && c <= 'z') {   // if is lowercase latter
            start = 'a';                     // sets start to lowercase a
        } else if (c == '\n') {              // if c is newline
            putchar('\n');                   // prints enter
            continue;                        // skip rest of loop iteration
        } else {                             // if c is not newline or a letter
            printf("Input contains special characters. Please type only upper- and lower-case "
                   "letters\n");
            return 0;   // exists program
        }

        // prints the read char, shifted by the amount defined as an argument
        putchar((c - start + shiftAmt) % 26 + start);
    }

    return 0;   // exits the program
}