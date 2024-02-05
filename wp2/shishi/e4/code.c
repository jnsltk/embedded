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

    // check the number of arguments
    if ((argc != 6) || (validate_values(argv[1], argv[2], argv[3], argv[4], argv[5]) != 1)) {
        printf("Error: Invalid input.");
        return 2;
    }

    // check the arguments are valid
    unsigned char byte = 0;   // declare a byte variable to pack the input values

    int values[5] = {7, 4, 2, 1, 0};
    for (int i = 5; i > 0; i--) {
        byte += (*argv[i] - '0') << values[i - 1];
    }
    printf("%X", (int) byte);

    // exit the program successfully
    return 0;
}

int validate_values(char *engine, char *gear, char *key, char *brake1, char *brake2) {
    if (strlen(engine) != 1 || strlen(gear) != 1 || strlen(key) != 1 || strlen(brake1) != 1 ||
        strlen(brake2) != 1) {
        return 0;
    }

    if ((*engine != '0' && *engine != '1') || (*brake1 != '0' && *brake1 != '1') ||
        (*brake2 != '0' && *brake2 != '1') || (*gear < '0' || *gear > '4') ||
        (*key < '0' || *key > '2')) {
        return 0;
    }

    return 1;
}