// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 0
// Exercise 3
// Submission code: 
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("No argument provided! \n");
    } else if(argc > 2){
        printf("Too many arguments provided! \n");
    }
    const int bigEnoughFirstArg = (argc >= 2 && sizeof(&argv[1]) / sizeof(char) >= 2);
    const int isHelp = (bigEnoughFirstArg && argv[1][0] == '-' && argv[1][1] == 'h'); 
    if(argc != 2 || isHelp){
        printf(
            "Example usage: %s %s\nTo get help: %s -h\n", 
            argv[0], 
            "\"Me\"",
            argv[0]
        );
        return 0;
    }

    printf("Hello World - I'm %s! \n", argv[1]);
}