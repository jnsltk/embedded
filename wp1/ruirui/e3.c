#include <stdio.h>    // includes I/O library for getChar, putChar
#include <stdlib.h>   // includes stdlib for strtol
#include <time.h>

#define HIGHEST_NUMBER 100
#define MAX_NUMBER     6

void doRound();
int getGuess();

int main(const int argc, const char **argv) {
    srand(time(NULL));

    /* ------------------------ VARIABLES ----------------------- */

    do {
        doRound();
        printf("Do you want to play again? (y/n): ");
        // while the stdin reads 'y' (the second getchar clears the newline character)
    } while (getchar() == 'y' && getchar());
}

void doRound() {
    const int num = rand() % HIGHEST_NUMBER + 1;
    int guess = getGuess();
    int guessAmt = 1;

    while (guess != num) {
        if (guess > num)
            printf("Your guess is too too high\n");
        else
            printf("Your guess is too low\n");

        if (guessAmt == MAX_NUMBER) {
            printf("You ran out of guesses so you lost\n");
            return;
        }
        guess = getGuess();
        guessAmt++;
    }

    printf("You have guessed %d times and your guess is correct\n", guessAmt);
}

char guessStr[11];
int getGuess() {
    printf("Enter a number between 1 and %d: ", HIGHEST_NUMBER);
    fgets(guessStr, sizeof(guessStr), stdin);

    char *endptr;   // defines pointer wich will point to where the first argument stopped parsing
    const long guessInt = strtol(guessStr, &endptr, 10);   // gets long version of first argument

    if (*endptr == '\n' && guessInt > 0 && guessInt <= HIGHEST_NUMBER)
        return guessInt;
    else {
        printf("Invalid number, please try again\n");
        return getGuess();
    }
}