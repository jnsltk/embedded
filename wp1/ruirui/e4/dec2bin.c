#include <stdio.h>
#include <stdlib.h>   // includes stdlib for strtol

int getNumber();

int main() {
    const int input = getNumber();

    printf("%d", input);
    return 0;
}

int getNumber() {        // defines function which reads a number in range from sdin
    char inputStr[11];   // reserves char array used to temporarily store the string the user enters
    fgets(inputStr, sizeof(inputStr), stdin);   // reads a string from stdin with

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long guessInt = strtol(inputStr, &endptr, 10);   // gets long version of first argument

    // if the number is valid
    if (*endptr == '\n')
        return guessInt;   // return entered argument as a number
    else {                 // if the number is not valid
        fprintf(stderr, "Invalid number");
        return -1;
    }
}