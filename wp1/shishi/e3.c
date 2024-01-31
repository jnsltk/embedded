// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define section
#define MAX_NUMBER 3

// Main program section

/**
 * This program creates a random integer number, between 1..100, and the user
 * then tries to guess the number.
 */

// Function prototype
int check_number (char *input);

// Main function

int main ()
{
    char input;    // declare a char input to store user input later
    int guess_num; // declare a int guess_num to store the guessed number later
    char game_status; // declare a game_status to store the value that whether
                      // the user wants to continue or exit the game later
    srand (time (NULL)); // randomizing the generated number by reading the
                         // clock and converting it to an unsigned integer as
                         // the seed to the random number generator
    int num; // declare a int num to store the generated random number later
    int counter; // declare a counter to count the number of guesses later
    while (game_status != 'n') // loop the game as long as the user does not
                               // input 'n' to exit the game
        {
            printf ("Let's play.\n");
            game_status = '0'; // set the default game_status value as '0'
            counter = 0;       // set the counter value as 0
            num = 1 + rand () % 100; // The rand function generates a
                                     // random integer between 1 and 100
            printf ("radom number: %d\n", num);
            while (!(counter + 1
                     > MAX_NUMBER)) // loop the propmts for guessing as long as
                                    // the number of guesses does not exceed
                                    // the MAX_NUMBER
                {
                    printf ("Enter your guess: ");
                    scanf ("%s",
                           &input); // store the user's guess in the
                                    // address of input as string
                    if (check_number (&input)
                        == 0) // check if the user input value is a valid
                              // number between 1 and 100
                        {
                            printf ("Invalid input. You should enter a number "
                                    "between 1 and 100.\n");
                            break; // break the guessing propmt loop if user
                                   // input is invalid
                        }
                    guess_num
                        = atoi (&input); // store the valid number of the user
                                         // input in the variable guess_num
                    counter++;           // increment the couter by 1

                    if (guess_num == num) // if the guess is right, showing a
                                          // message to the user
                        {
                            printf ("\nYou have guessed %d times and your "
                                    "guess is "
                                    "correct.\n",
                                    counter);
                            break; // break the guessing prompts loop
                        }
                    else if (guess_num < num) // if the guess is smaller than
                                              // the number, show a reminder
                        {
                            printf ("Your guess is too low.\n");
                        }
                    else if (guess_num > num) // if the guess is bigger than
                                              // the number, show a reminder
                        {
                            printf ("Your guess is too high.\n");
                        }
                }
            // After end of one round the user is asked for a new round or to
            // exit the game
            // loop the propmt whether the user wants to continue or exit the
            // game as long as the user does not input the required answer
            while (game_status != 'y' && game_status != 'n')
                {
                    printf ("\nDo you want to play again? Enter 'y' keys to "
                            "continue, "
                            "or 'n' "
                            "to exit\n");
                    scanf (" %c", &game_status); // store the user input in the
                                                 // address of game_status
                }
        }
    //   exit the program
    return 0;
}

// Check number function with 0/1 as return value:
// 0 -> false, i.e., input is not a number, or input is not a number between 1
// and 100; 1 -> true, i.e., input is a number between 1 and 100
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
    if (atoi (input) < 1
        || atoi (input) > 100) // when the input is a number between 1 and 100,
                               // then it returns false
        {
            return 0;
        }
    return 1; // return 1 means that input is a number
}