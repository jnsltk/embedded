// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 3
// Submission code: 9272

// Include standard input output header file
#include <stdio.h>
// Include string.h header file
#include <string.h>

// Main function in the program
int main(int argc, char *argv[]) 
{
    // Check if there are any arguments provided
    if (argc == 1) 
    {
        printf("No argument provided!\n");
    }
    // Else check if there are too many arguments provided (more than one)
    else if (argc > 2) 
    {
        printf("Too many arguments provided\n");
    }

    // Check if any arguments were provided, if yes, check if its value is "-h"
    if (argc != 2 || strcmp(argv[1], "-h") == 0) 
    {
        printf("Usage:\n %s [name]\n %s [-h] -- Show this help message\n", argv[0], argv[0]);
    }
    // If there is an argument, and it's not -h, print it together with greeting
    else 
    {
        printf("Hello World! - I'm %s!\n", argv[1]);
    }

    // Return 0 to show successful execution
    return 0;
}

