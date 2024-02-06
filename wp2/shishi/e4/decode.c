// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 333555

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
    // check the number of arguments and the values are valid
    if ((argc != 2) || (validate_input(argv[1]) != 1)) {
        printf("Error: Invalid input.\n");
        return 2;   // terminate the program with returned error code 2
    }

    unsigned char engine_on;   // define a variable to store the value for engine_on
    unsigned char gear_pos;    // define a variable to store the value for gear_pos
    unsigned char key_pos;     // define a variable to store the value for key_pos
    unsigned char brake1;      // define a variable to store the value for brake1
    unsigned char brake2;      // define a variable to store the value for brake2

    // convert to binary representation
    char *c = argv[1];   // define a pointer to user input
    int num = 0;         // define a variable to store converted decimal number from user input(hex)
    int counter = 1;     // define a variable as exponent during integer conversion
    while (*c) {         // loop through the user input (command-line arg)
        if (*c >= 'A' && *c <= 'F') {   // check whether the current char is between 'A' and 'F'
            num += (pow(16, counter--)) * (*c - 55);   // if it is, update the num
        } else if (*c >= '0' &&
                   *c <= '9') {   // check whether the current char is between '0' and '9'
            num += pow(16, counter--) * (*c - '0');   // if it is, update the num
        }
        c++;   // move the pointer forward
    }
    unsigned char mask = 1;   // declare a variable mask to do bit operations
    brake2 = num & mask;      // retrieve the value of brake2 with bit operation

    brake1 = (num >> 1) & (mask);   // right shift 1 bit, and retrieve the value of brake1

    // key_pos has two bits
    key_pos = (num >> 2) & (mask);   // right shift 2 bits, and retrieve the value of brake1 with
                                     // its less significant bit
    key_pos += (num >> 2) &
               (mask << 1);   // left shift the mask 1 bit, retrieve the value of
                              // brake1 with its more significant bit, and add to the previous value

    // gear_pos has three bits
    gear_pos = (num >> 4) & (mask);   // right shift 4 bits, and retrieve the value of gear_pos
    for (int i = 1; i < 3; i++) {     // loop through 2 times
        gear_pos +=
            (num >> 4) &
            (mask << i);   // left shift the mask 1 bit each time, and add up the retrieved values
    }

    engine_on = (num >> 7) & (mask);   // right shift 7 bits, and retrieve the value of engine_on

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

// This function checks that the user input is valid
int validate_input(char *input) {
    char *c = input;   // define a pointer to the input
    int count = 0;     // declare a variable to store the number of elements in the input
    while (*c) {       // loop through the input
        count++;       // increment th count by 1
        if (!((*c >= 'A' && *c <= 'F') ||
              (*c >= '0' &&
               *c <= '9'))) {   // check if any element in the input is not 'A'-'F' or '0'-'9'
            return 0;           // the input is invalid, return 0 (false)
        }
        if (count == 1) {   // when count is 1, that means it is the first char in the input
            int num;   // define a variable num to store the integer value of the first char (the
                       // first number from the hexadecimal)
            if (*c >= '0' &&
                *c <= '9') {              // check if the current char value is between '0' and '9'
                num = (int) (*c - '0');   // retrieve its integer value
            } else if (*c >= 'A' &&
                       *c <= 'F') {   // check if the current char value is between 'A' and 'F'
                num = *c - 55;        // retrieve its integer value
            }
            // check the gear_pos range is max 4 -> 100
            unsigned char mask =
                1 << 2;                // define a variable mask left shifted by 2 for bit operation
            if ((num & mask) == 4) {   // check if the number is 4 with bit operation, i.e., 01xx
                if ((((mask >> 1) & num) == 2) ||
                    (((mask >> 2) & num) == 1)) {   // if the number is invalid with 0110 || 0111
                    return 0;                       // return 0 (false)
                }
            }
        } else if (count == 2) {   // when count is 2, that means it is the second char in the input
            int num;
            if (*c >= '0' &&
                *c <= '9') {              // check if the current char value is between '0' and '9'
                num = (int) (*c - '0');   // retrieve its integer value
            } else if (*c >= 'A' &&
                       *c <= 'F') {   // check if the current char value is between 'A' and 'F'
                num = *c - 55;        // retrieve its integer value
            }
            unsigned char mask =
                1 << 3;                // define a variable mask left shifted by 3 for bit operation
            if ((num & mask) == 8) {   // check if the number is 8 with bit operation, i.e., 1000
                if (((mask >> 1) & num) == 4) {   // if the number is invalid with 1100
                    return 0;                     // return 0 (false)
                }
            }
        }
        c++;   // move the pointer forward
    }
    // return true (valid hex)
    return 1;
}
