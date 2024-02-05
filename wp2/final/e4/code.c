// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <string.h>

/* -------------------------- Function declarations ------------------------- */
int validate_values(char *engine, char *gear, char *key, char *brake1, char *brake2);

/* -------------------------- Main program section -------------------------- */

/**
 * This program packs bits into a byte
 * This program needs to store 4 different values in a byte.
 */

// Main function
// The main function takes 5 arguments (fewer or more than 5 arguments should be treated as an
// error).
int main(int argc, char **argv) {

    // check the number of arguments and the values are valid
    if ((argc != 6) || (validate_values(argv[1], argv[2], argv[3], argv[4], argv[5]) != 1)) {
        printf("Error: Invalid input.");
        return 2;   // terminate the program with returned error code 2
    }

    // check the arguments are valid
    unsigned char byte = 0;   // declare a byte variable to pack the input values

    // define an int array to store the number of positions for bit shifting corresponding to
    // the 5 (user-input) arguments
    // e.g., argv[5] is the value for 'brake2', it needs to shift 0 position; argv[1] is the value
    // for 'engine_on', it needs to shift 7 positions
    int values[5] = {7, 4, 2, 1, 0};
    for (int i = 5; i > 0; i--) {   // loop through the 5 argument values (start from the value for
                                    // 'brake2' - i.e., the Least Significant Bit)
        byte += (*argv[i] - '0')
                << values[i - 1];   // convert these value to a decimal number with bit shifting
    }
    printf("%X", (int) byte);

    // exit the program successfully
    return 0;
}

// This function checks whether the 5 input values (the command-line arguments from the user) are
// valid. 'Valid' means that the user input values must be numbers within the range as specified
// in the WP2 description.
// If the values are valid, return 1(true), otherwise return 0(false)
int validate_values(char *engine, char *gear, char *key, char *brake1, char *brake2) {
    // Check whether the input value is more than 1 char (that is, the user tries to input a number
    // bigger than 9)
    if (strlen(engine) != 1 || strlen(gear) != 1 || strlen(key) != 1 || strlen(brake1) != 1 ||
        strlen(brake2) != 1) {
        return 0;   // invalid input values
    }
    // Check whether the input value is within the required range
    if ((*engine != '0' && *engine != '1') || (*brake1 != '0' && *brake1 != '1') ||
        (*brake2 != '0' && *brake2 != '1') || (*gear < '0' || *gear > '4') ||
        (*key < '0' || *key > '2')) {
        return 0;   // invalid input values
    }

    return 1;   // valid input values
}