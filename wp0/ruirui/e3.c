// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 0
// Exercise 3
// Submission code:

// Includes the standard input/output library
#include <stdio.h>
// Includes the string library
#include <string.h>

// Entry point of the program
int main (const int argc, const char *argv[])
{
    if (argc == 1)
        { // No argument provided
            printf ("No argument provided! \n");
        }
    else if (argc > 2)
        { // Too many arguments provided
            printf ("Too many arguments provided! \n");
        }

    // If there is atleast 1 argument and the first argument is at least two
    // characters long
    const int bigEnoughFirstArg = (argc >= 2 && strlen (argv[1]) >= 2);
    // If the first argument exists and is big enough and the first two
    // characters are "-h"
    const int isHelp
        = (bigEnoughFirstArg && argv[1][0] == '-' && argv[1][1] == 'h');
    if (argc != 2 || isHelp)
        { // If there is not exactly one argument or the
          // argument is "-h"
            printf ("Example usage: %s %s\nTo get help: %s -h\n", argv[0],
                    "\"Me\"", argv[0]);
            // Returns success if the argument is "-h", otherwise return
            // failure as the program is not used correctly
            return 0;
        }

    printf ("Hello World - I'm %s! \n", argv[1]);
}