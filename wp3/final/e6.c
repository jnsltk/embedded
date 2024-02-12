#include <stdio.h>    // includes standard i/o library
#include <string.h>   // includes string library for strcpy

#define MAX_INPUT 21   // defines the maximum input length

// custom function to copy a string
void copyString(char *dest, char *src) {
    do {                // do-while loop to copy the string
        *dest = *src;   // copies the character from src to dest
        dest++;         // increments the destination pointer
        // increments the source pointer and checks if it's the end of the string
    } while (*(++src) != '\0');

    *dest = '\0';   // adds the null terminator to the end of the string
}

// main function
int main() {
    // declares the original array and the two copies
    char input[MAX_INPUT], c1[MAX_INPUT], c2[MAX_INPUT];
    fgets(input, MAX_INPUT, stdin);   // reads string from stdin

    strcpy(c1, input);       // copies the string using strcpy
    copyString(c2, input);   // copies the string using my own brilliant function

    printf("Original:   %s\n", input);
    printf("strcpy:     %s\n", c1);
    printf("copyString: %s\n", c2);
}