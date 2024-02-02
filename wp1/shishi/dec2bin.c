// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define MAX_VALUE 4294967295

// Function prototype
int check_number (char *input);

// Main program section

/**
 *
 */

// Main function
int main (int argc, char *argv[])
{
    // The programs should accept any number between 0 and the maximum value of
    // type long in C for your compiler

    // The program should use the smallest possible datatype for a given,
    // number.

    // printf ("%s\n", argv[1]);
    // unsigned char num = *argv[1];
    // printf ("size: %lu\n", sizeof (num));
    if (argc > 1
        && strcmp ("-h", argv[1])
               == 0) // If the user provides the first argument "-h", the
                     // program will provide the info how to use it.
        {
            printf ("You can use this program by following the instructions "
                    "as below:\nProvide a number after the the file name.");
        }
    if (argc < 2)
        {
            printf ("Error: You need to provide a number.");
            return 2;
        }
    if (check_number (argv[1])
        == 0) // error case 2: check the argument is not a number
        {
            printf ("Error: Invalid number.\n");
            return 2;
        }
    else
        {
            // int input_num = atoi (argv[1]);
            char *nPtr;
            long input_num = strtoul (argv[1], &nPtr, 10);
            // printf ("%lu\n", input_num);

            // when the number is smaller than 256 -> 8 bits, by using unsigned
            // char
            if (input_num < 256)
                {
                    unsigned mask = 1 << 7;
                    unsigned char num = input_num;
                    //  convert a number in a decimal format to a binary format
                    for (int i = 0; i < 8; i++)
                        {
                            unsigned char bit_num
                                = (input_num & mask) ? '1' : '0';
                            putchar (bit_num);
                            mask >>= 1;
                        }
                }
            // when the number is between 256 and 65,536 -> 16 bits, by using
            // unsigned short int
            else if (input_num >= 256 && input_num < 65536)
                {
                    unsigned mask = 1 << 15;
                    unsigned short int num = input_num;
                    for (int i = 0; i < 16; i++)
                        {
                            unsigned char bit_num
                                = (input_num & mask) ? '1' : '0';
                            putchar (bit_num);
                            mask >>= 1;
                        }
                }
            // when the number is between 65,536 and 4,294,967,295 -> 32 bits,
            // by using unsigned long int
            else if ((input_num >= 65536) && (input_num < MAX_VALUE))
                {
                    unsigned mask = 1 << 31;
                    unsigned long int num = input_num;
                    printf ("%lu\n", num);
                    for (int i = 0; i < 32; i++)
                        {
                            unsigned char bit_num = (num & mask) ? '1' : '0';
                            putchar (bit_num);
                            mask >>= 1;
                        }
                }
        }
}

// Check number function with 0/1 as return value:
// 0 -> false, i.e., input is not a number;
// 1 -> true, i.e., input is a number
int check_number (char *input)
{
    // loop through chars in the char array (i.e., input)
    for (int i = 0; i < strlen (input); i++)
        {
            if (isdigit (input[i])
                == 0) // when the char at the current index is not a digit,
                      // then it is equal to 0(false)
                {
                    return 0; // return 0 means that input is not a number
                }
        }
    return 1; // return 1 means that input is a number
}
