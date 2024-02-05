// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <math.h>
#include <stdio.h>

/* -------------------------- Function declaration -------------------------- */
int validate_input(char *input);

/* -------------------------- Main program section -------------------------- */

/**
 * This program takes 1 argument (one argument, hexadecimal number) and prints out the bit positions
 * for the engine, gear, etc.
 */

// Main function
// The main function takes 1 argument, hexadecimal number
int main(int argc, char **argv) {
    // check the number of arguments
    if ((argc != 2) || (validate_input(argv[1]) != 1)) {
        printf("Error: Invalid input.\n");
        return 2;
    }

    unsigned char engine_on = 0;
    unsigned char gear_pos = 0;
    unsigned char key_pos = 0;
    unsigned char brake1 = 0;
    unsigned char brake2 = 0;

    // convert to binary representation
    char *c = argv[1];
    int num = 0;
    int counter = 1;
    while (*c) {
        if (*c >= 'A' && *c <= 'F') {
            num += (pow(16, counter--)) * (*c - 55);
        } else if (*c >= '0' && *c <= '9') {
            num += pow(16, counter--) * (*c - '0');
        }
        c++;
    }
    unsigned char mask = 1;
    brake2 = num & mask;

    brake1 = (num >> 1) & (mask);

    for (int i = 0; i < 2; i++) {
        key_pos += (num >> 2) & (mask << i);
    }

    for (int i = 0; i < 3; i++) {
        gear_pos += (num >> 4) & (mask << i);
    }

    unsigned char engine = (num >> 7) & (mask);

    printf("%s\t\t%s\n", "Name", "Value");
    printf("%s\n", "-------------------------");
    printf("%s\t%d\n", "engine_on", engine_on);
    printf("%s\t%d\n", "gear_pos", gear_pos);
    printf("%s\t\t%d\n", "key_pos", key_pos);
    printf("%s\t\t%d\n", "brake1", brake1);
    printf("%s\t\t%d", "brake2", brake2);

    // exit the program successfully
    return 0;
}

int validate_input(char *input) {
    char *c = input;
    int count = 0;
    while (*c) {
        count++;
        if (!((*c >= 'A' && *c <= 'F') || (*c >= '0' && *c <= '9'))) {
            return 0;
        }
        if (count == 1) {
            int num;
            if (*c >= '0' && *c <= '9') {
                num = (int) (*c - '0');
            } else if (*c >= 'A' && *c <= 'F') {
                num = *c - 65;
            }
            printf("num: %d\n", num);   // 0101
            // check the gear_pos range is max 4 -> 100
            unsigned char mask = 1 << 2;
            if ((num & mask) == 4) {
                if ((((mask >> 1) & num) == 2) || (((mask >> 2) & num) == 1)) {   // 0110 || 0111
                    return 0;
                }
            }
        }
        c++;
    }
    // return true (valid hex)
    return 1;
}
