#include <stdio.h>    // includes I/O library for getChar, putChar
#include <stdlib.h>   // includes stdlib for strtol

// Main function of program
int main(const int argc, const char **argv) {

    /* ------------------------ VARIABLES ----------------------- */

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long shiftAmt = strtol(argv[1], &endptr, 10);   // gets long version of first argument

    /* --------------------- EXIT CONDITIONS -------------------- */

    if (argc == 1) {   // if no argument provided
        printf("Missing argument\n");
        return 0;   // finishes program
    }

    if (*endptr != '\0') {   // if argument is NaN
        printf("Expected a numeric argument\n");
        return 0;   // finishes program
    }

    /* -------------------- NORMAL EXECUTION -------------------- */

    char c = getchar();   // initialises char from stdin

    while (c != EOF) {   // while char is not End-Of-File

        // initialises char with the start of the capital or lowercase alphabet
        const int start = (c > 'Z') ? 'a' : 'A';

        if (c == '\n')       // if stdin reads enter
            putchar('\n');   // prints enter
        else                 // if stdin does not read enter
            // prints the read char, shifted by the amount defined as an argument
            putchar((c - start + shiftAmt) % 26 + start);

        // reads a new character
        c = getchar();
    }

    return 0;   // exits the program
}