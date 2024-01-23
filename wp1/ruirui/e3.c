#include <stdio.h>    // includes I/O library for getChar, putChar
#include <stdlib.h>   // includes stdlib for strtol
#include <time.h>

#define HIGHEST_NUMBER 100

int main(const int argc, const char **argv) {
    srand(time(NULL));

    /* ------------------------ VARIABLES ----------------------- */

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long shiftAmt = strtol(argv[1], &endptr, 10);   // gets long version of first argument
    const int num = rand() % HIGHEST_NUMBER + 1;

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

    int guess;
    scanf("%d", &guess);

    printf("%d", guess);
    // while (guess)
}