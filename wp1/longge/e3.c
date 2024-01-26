#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NUMBER  10
#define MAX_DIGIT   12
#define HIGHEST_NUM 100

void get_guess(int *pguess) {
    char *input_buff = malloc(sizeof(char) * MAX_DIGIT);
    memset(input_buff, 0, MAX_DIGIT);

    char *input = NULL;
    while (input == NULL) {
        input = fgets(input_buff, MAX_DIGIT, stdin);

        char *pend = NULL;
        *pguess = strtol(input, &pend, 10);

        if (input == pend || *pguess < 0 || *pguess > HIGHEST_NUM) {
            printf("Invalid number. Please input a number between 1 and %d\n", HIGHEST_NUM);
            input = NULL;
        }
    }

    free(input_buff);
}

void play_round() {
    int n = rand() % HIGHEST_NUM + 1;

    printf("I\'ve thought of a number, take a guess between 0 and %d\n", HIGHEST_NUM);
    int guess;
    get_guess(&guess);
    int guess_left = MAX_NUMBER - 1;

    while (guess != n) {
        if (guess_left == 0) {
            puts("Game over! You have no more guesses left");
            return;
        } else if (guess < n) {
            guess_left--;
            printf("Your guess is lower. You have %d more guesses left.\n", guess_left);
        } else {
            guess_left--;
            printf("Your guess is higher. You have %d more guesses left.\n", guess_left);
        }
        get_guess(&guess);
    }
    printf("You win! The number I thought of was indeed %d!\n", n);
}

int main(int argc, char **argv) {
    srand(time(0));

    int c;
    do {
        play_round();

        puts("Would you like to play again? [Y/n]");
    } while (((c = getchar()) == 'y' || c == 'Y') && getchar() == '\n');

    return 0;
}
