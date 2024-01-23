#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // includes time header for time function

#define MAX       100   // Defines the maximum number of the values in the table
#define MAXNUMBER 20    // Defines the maximum value of random numbers

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab, const int tabSize, const int maxNumber);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq, const int tabSize);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq, const int freqSize);

// ------ Function definitions   ----------

// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(int argc, char **argv) {
    // defines pointer wich will point to where the first argument stopped parsing
    char *endptr;
    int tableSize = MAX;
    int maxNumber = MAXNUMBER;

    if (argc > 1) {
        // gets long version of first argument
        tableSize = strtol(argv[1], &endptr, 10);

        if (*endptr != '\0') {
            printf("First argument is invalid\n");
            return 0;
        }

        if (argc > 2) {
            // gets long version of first argument
            maxNumber = strtol(argv[2], &endptr, 10);

            if (*endptr != '\0') {
                printf("Second argument is invalid\n");
                return 0;
            }
        }
    }

    int table[tableSize];
    int frequency[maxNumber + 1];

    for (int i = 0; i < maxNumber + 1; i++) {
        frequency[i] = 0;
    }

    create_random(table, tableSize, maxNumber);

    count_frequency(table, frequency, tableSize);

    draw_histogram(frequency, maxNumber + 1);
}

void create_random(int *tab, const int tabSize, const int maxNumber) {
    srand(time(NULL));

    for (int i = 0; i < tabSize; i++) {
        tab[i] = rand() % (maxNumber + 1);   // TODO: check
    }
}

void count_frequency(int *tab, int *freq, const int tabSize) {
    for (int i = 0; i < tabSize; i++) {
        freq[tab[i]]++;
    }
}

void draw_histogram(int *freq, const int freqSize) {
    for (int i = 0; i < freqSize; i++) {
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