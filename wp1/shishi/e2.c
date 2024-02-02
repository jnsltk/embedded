// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main program section

/**
 * The program “shifts characters” in the ASCII-code table of a given input
 * string
 */

// Function prototype
int check_number (char *input);

// Main function
int main (int argc, char *argv[])
{
    // handle errors (including 2 cases)
    if (argc < 2) // error case 1: check the argument is empty
        {
            printf ("Error: No number provided. Please provide a number as a "
                    "command line argument.\n");
        }
    else if (check_number (argv[1])
             == 0) // error case 2: check the argument is not a number
        {
            printf ("Error: Invalid number.\n");
        }
    else // when no errors occured from reading the command-line argument
        {
            unsigned char shift_num
                = atoi (argv[1]); // declare a variable shift_num and use it to
                                  // store the command-line argument
            char letter;          // declare the variable letter, for
                                  // storing each input char later
            printf ("Enter a text: ");

            // loop the prompts for entering a text until EOF
            while ((letter = getchar ()) != EOF)
                {
                    // when it reads 'enter' key, it adds a new line and
                    // prompts a new text
                    if (letter == '\n')
                        {
                            printf ("\nEnter a text: ");
                        }
                    if ((letter <= 'A' && letter <= 'Z')
                        || (letter <= 'a' && letter <= 'z'))
                        {
                            printf ("failed");
                            return 1;
                        }
                    char endletter = (letter <= 90) ? 'Z' : 'z';
                    char shifted_value = letter + shift_num;
                    if (shifted_value % endletter == shifted_value)
                        {
                            putchar (shifted_value);
                        }
                    else
                        {
                            putchar (shifted_value % endletter + endletter
                                     - 26);
                        }
                }
        }

    // exit program
    return 0;
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