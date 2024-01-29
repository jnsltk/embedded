// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 5
// Submission code:

#include <stdio.h>    // includes standard I/O library
#include <stdlib.h>   // includes library for strtoul
#include <time.h>     // includes time header for time function

/* ========================= DEFINES ======================== */

#define DEFAULT_MAX        100   // defines the maximum number of the values in the table
#define DEFAULT_MAX_NUMBER 20    // defines the maximum value of random numbers

/* ======================== VARIABLES ======================= */

unsigned int tableSize = DEFAULT_MAX;          // initialises table size with a default
unsigned int maxNumber = DEFAULT_MAX_NUMBER;   // initialises the maximum number with a default

/* ================== FUNCTION DECLARATIONS ================= */

// declares function which loads the parameters passed into the program
char loadParams(const int argc, char **argv);

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

/* ================== FUNCTION DEFINITIONS ================== */

// The main entry point for the program
int main(const int argc, char **argv) {
    if (!loadParams(argc, argv))   // if the user provided invalid arguments
        return 0;                  // quit the program

    int table[tableSize];           // declares table of random numbers
    int frequency[maxNumber + 1];   // declares array of the frequencies of the numbers

    for (int i = 0; i < maxNumber + 1; i++) {   // loops through the frequency array
        frequency[i] = 0;                       // sets all entries to zero
    }

    create_random(table);   // fills table with random values

    // fills frequency array with the occurence of the different numbers
    count_frequency(table, frequency);

    draw_histogram(frequency);   // prints out frequency table
}

// defines function which loads the parameters passed into the program
char loadParams(const int argc, char **argv) {
    char *endptr;   // declares pointer which will store the address of where the

    if (argc < 2)   // if the user did not provide any arguments
        return 1;   // returns 1 indicating a valid input state

    // gets long version of first argument
    tableSize = strtoul(argv[1], &endptr, 10);

    if (*endptr != '\0') {   // if the argument did not only contain digits
        printf("First argument is invalid\n");
        return 0;   // returns 0 indicating invalid input state
    }

    if (argc < 3)   // if the user did not provide two arguments
        return 1;   // return 1 indicating valid input state

    // gets long version of second argument
    maxNumber = strtoul(argv[2], &endptr, 10);

    if (*endptr != '\0') {   // if the argument did not only contain digits
        printf("Second argument is invalid\n");
        return 0;   // returns 0 indicating invalid input state
    }

    return 1;   // returns 1 indicating valid input state
}

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab) {
    srand(time(NULL));   // sets randomising seed using the current timer

    for (int i = 0; i < tableSize; i++) {   // loop through the
        // sets the i'th element to a random number between 0 and maxnumber
        tab[i] = rand() % (maxNumber + 1);
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < tableSize; i++) {   // loops through the random number table
        // increments the recorded frequency of the number found in the random table
        freq[tab[i]]++;
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq) {
    for (int i = 0; i <= maxNumber; i++) {   // loops through frequency array
        const int num = freq[i];             // initialises the num as the i'th frequency
        if (num) {                           // if the number is not zero
            if (i > 99)                      // if the number is bigger than 99
                printf("%d ", i);
            else if (i > 9)   // else if the number is bigger than 9
                printf("%d  ", i);
            else   // if the number is smaller than 10
                printf("%d   ", i);

            for (int x = 0; x < num; x++)   // for every time the number occured
                printf("x");

            printf("\n");
        }
    }
}