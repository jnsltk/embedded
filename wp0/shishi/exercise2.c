// include section
#include <stdio.h>

// main program section
/**
 * This program takes a command-line argument (i.e., a name)
 * and send a greeting with the name
 */

// main function in the program
int main(int argc, char *argv[])
{
    printf("Hello World!  I'm %s!", argv[1]);

    // exit the program
    return 0;
}
