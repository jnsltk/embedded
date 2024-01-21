// include section
#include <stdio.h>
#include <string.h>

// main program section
/**
 * This program takes a command-line argument (i.e., a name)
 * and send a greeting with the name.
 * If the user provides more than one argument or no arguments,
 * the user will get an error message and info about the param -h.
 * If the user provides the first argument "-h",
 * the program will provide the info how to use it.
 */

// main function in the program
int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp("-h", argv[1]) == 0) // If the user provides the first argument "-h", the program will provide the info how to use it.
    {
        printf("You can use this program by following the instructions as below:\nProvide a name after the the file name.");
    }
    else if (argc != 2) // if the user provides more than one argument or no arguments,the user will get an error message and info about the param -h.
    {
        printf("You need to provide one and only one argument.\n You can lean more by typing \"-h\".");
    }
    else // if the user provides one argument, he/she will receive a greeting message with his/her name.
    {
        printf("Hello World! - I'm %s!", argv[1]);
    }

    // exit the program
    return 0;
}