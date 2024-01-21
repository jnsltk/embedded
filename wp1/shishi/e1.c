// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <stdio.h>

// Define section
#define SENTENSE_1                                                            \
    "I have only 1 date."            // define string constant for SENTENSE_1
#define SENTENSE_2 "I have 2 dates." // define string constant for SENTENSE_2
#define SENTENSE_3 "I have 3 dates." // define string constant for SENTENSE_3
#define SENTENSE_4 "I have 4 dates." // define string constant for SENTENSE_4
#define SENTENSE_5 "I have 5 dates." // define string constant for SENTENSE_5

// Main program section

/**
 * This program reads and integer number between 1 and 5 and outputs a
 * unique sentence corresponding to the input number. The program will
 * continue to ask for a new number and exit if the number is not in the
 * interval 1 to 5.
 */

// Main function
int main ()
{
    int number; // declare a int variable to store the input number

    printf ("Enter a number between 1 and 5:\t");
    scanf ("%d", &number); // get the number entered by the user and put it
                           // in the the address of "number"

    while (number < 6
           && number > 0) // loop the prompts for entering a number as long as
                          // the input number is between 1 and 5
        {
            switch (number) // determine which number was input
                {
                case 1: // if the number is 1, output SENTENSE_1
                    printf ("%s\n", SENTENSE_1);
                    break; // exit switch

                case 2: // if the number is 2, output SENTENSE_2
                    printf ("%s\n", SENTENSE_2);
                    break; // exit switch
                case 3:    // if the number is 3, output SENTENSE_3
                    printf ("%s\n", SENTENSE_3);
                    break; // exit switch
                case 4:    // if the number is 4, output SENTENSE_4
                    printf ("%s\n", SENTENSE_4);
                    break; // exit switch
                case 5:    // if the number is 5, output SENTENSE_5
                    printf ("%s\n", SENTENSE_5);
                    break; // exit switch
                }
            printf ("\nEnter a number between 1 and 5:\t");
            scanf ("%d", &number); // get the number entered by the user and
                                   // store it in the the address of "number"
        }

    // exit the program
    return 0;
}