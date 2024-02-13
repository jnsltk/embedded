// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>

/* ------------------------------ Define macros ----------------------------- */
#define MAX 20

void copyString(char *copy_array, char *ori_array);
/* -------------------------- Main program section -------------------------- */

/**
 * This program reads in a string with a maximum of 20 characters from the keyboard and stores the
 * string in a local string variable.
 * The program should be able to both read in from keyboard or from a text file ‘myfile.txt’
 * containing one string of characters.
 */

// Main function
int main(int argc, char **argv) {

    char array[MAX] = {0};   // define a string
    if (argc == 2) {         // when reading in from the keyboard
        if (strlen(argv[1]) >
            20) {   // check if the input string exceeds the max number of characters
            printf("Error: The input string has to be a maximum of %d characters.", MAX);
            return 2;   // terminate the program with error code 2
        }
        strcpy(array, argv[1]);   // store the string in a local string variable by using library
                                  // function stcpy(...)
    } else {                      // when reading in from the test file ‘myfile.txt’
        char temp_array[MAX] = {0};   // define a temporary string variable
        int i = 0;                    // define a int variable used for string index
        char c;                       // declare a char to store stdin char
        while ((c = getchar()) != EOF &&
               i < MAX) {   // read in stdin until the end of the file, the read in string has to be
                            // with a maximum of 20 characters
            temp_array[i++] = c;   // store the current char value in the array
        }
        temp_array[i] = '\0';   // assign a terminator at the end of the string
        copyString(array,
                   temp_array);   // copy the string to another string by using our own function
    }
    // Main program ends by printing out the copied string in the console
    printf("%s", array);

    //  exit the program successfully
    return 0;
}

// This function copies the string to another string
void copyString(char *copy_array, char *ori_array) {
    char *ptr = ori_array;        // define a pointer to the original array
    int i = 0;                    // define a variable used for array indexes
    while (*ptr) {                // loop through the original array
        copy_array[i++] = *ptr;   // assign the current char value to the copied array
        ptr++;                    // move the pointer forward
    }
}