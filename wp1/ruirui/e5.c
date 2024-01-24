#include <stdio.h>    // includes standard I/O library
#include <stdlib.h>   // includes library for strtol
#include <time.h>     // includes time header for time function

/* ========================= DEFINES ======================== */

#define DEFAULT_MAX        100   // Defines the maximum number of the values in the table
#define DEFAULT_MAX_NUMBER 20    // Defines the maximum value of random numbers

/* ======================== VARIABLES ======================= */

unsigned int tableSize = DEFAULT_MAX;   //
unsigned int maxNumber = DEFAULT_MAX_NUMBER;

/* ================== FUNCTION DECLARATIONS ================= */

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

// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(const int argc, char **argv) {
    if (!loadParams(argc, argv))
        return 0;

    int table[tableSize];
    int frequency[maxNumber + 1];

    for (int i = 0; i < maxNumber + 1; i++) {
        frequency[i] = 0;
    }

    create_random(table);

    count_frequency(table, frequency);

    draw_histogram(frequency);
}

char loadParams(const int argc, char **argv) {
    char *endptr;

    if (argc < 2)
        return 1;

    // gets long version of first argument
    tableSize = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0') {
        printf("First argument is invalid\n");
        return 0;
    }

    if (argc < 3)
        return 1;

    // gets long version of second argument
    maxNumber = strtol(argv[2], &endptr, 10);

    if (*endptr != '\0') {
        printf("Second argument is invalid\n");
        return 0;
    }

    return 1;
}

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab) {
    srand(time(NULL));

    for (int i = 0; i < tableSize; i++) {
        tab[i] = rand() % (maxNumber + 1);
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < tableSize; i++) {
        freq[tab[i]]++;
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq) {
    for (int i = 0; i <= maxNumber; i++) {
        const int num = freq[i];
        if (num) {
            if (i > 99)
                printf("%d ", i);
            else if (i > 9)
                printf("%d  ", i);
            else
                printf("%d   ", i);

            for (int x = 0; x < num; x++)
                printf("x");

            printf("\n");
        }
    }
}