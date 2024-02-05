// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 3
// Submission code: 35128211

#include <stdio.h>    // includes I/O library for getChar, printf, fgets
#include <stdlib.h>   // includes stdlib for strtol
#include <time.h>     // includes time header for time function

#define HIGHEST_NUMBER 100   // defines highest number that can be generated
#define MAX_NUMBER     6     // defines max number of guesses

void doRound();    // declares function which contains the code to perform a round
int getNumber();   // declares function which reads a number in range from sdin

// defines main function which is the start point of the program
int main(const int argc, const char **argv) {
    // sets the seed used for the random number generation based on the current time
    srand(time(NULL));

    do {             // loop for performing rounds until user gets bored
        doRound();   // performs game one round
        printf("Do you want to play again? (y/n): ");
        // while the stdin reads 'y' (the second getchar() clears the newline character)
    } while (getchar() == 'y' && getchar() == '\n');
}

// defines function which contains the code to perform a round
void doRound() {
    // creates the number for the user to guess, randomly, within the range 1 to HIGHEST_NUMBER
    const int num = rand() % HIGHEST_NUMBER + 1;
    int guess = getNumber();   // gets a valid guess from the user
    int guessAmt = 1;   // initialises variable representing amount of guesses the user has made

    while (guess != num) {   // while the user has not guessed right
        if (guess > num)     // if the guess is too high
            printf("Your guess is too too high\n");
        else   // if the guess is too low
            printf("Your guess is too low\n");

        if (guessAmt == MAX_NUMBER) {   // if the user ran out of guesses
            printf("You ran out of guesses so you lost\n");
            return;   // quits function
        }
        guess = getNumber();   // gets a valid guess from the user
        guessAmt++;            // increment amount of guesses
    }

    printf("You have guessed %d times and your guess is correct\n", guessAmt);
}

char inputStr[11];   // reserves char array used to temporarily store the string the user enters
int getNumber() {    // defines function which reads a number in range from sdin
    printf("Enter a number between 1 and %d: ", HIGHEST_NUMBER);
    fgets(inputStr, sizeof(inputStr), stdin);   // reads a string from stdin with

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long guessInt = strtol(inputStr, &endptr, 10);   // gets long version of first argument

    // if the number is valid
    if (*endptr == '\n' && guessInt > 0 && guessInt <= HIGHEST_NUMBER)
        return guessInt;   // return entered argument as a number
    else {                 // if the number is not valid
        printf("Invalid number, please try again\n");
        return getNumber();   // call the function again to allow the user to retry
    }
}