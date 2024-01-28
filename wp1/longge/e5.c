#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX       100   // Defines the maximum number of the values in the table
#define MAXNUMBER 20    // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// ------ Function definitions ----------
void create_random(int *tab) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % (MAXNUMBER + 1);
    }
}

void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < MAX; i++) {
        freq[tab[i]]++;
    }
}

void draw_histogram(int *freq) {
    for (int i = 0; i <= MAXNUMBER; i++) {
        if (i < 10) {
            printf("%d:   ", i);
        } else if (i < 100) {
            printf("%d:  ", i);
        } else {
            printf("%d: ", i);
        }
        for (int j = 0; j < freq[i]; j++) {
            putchar('+');
        }
        putchar('\n');
    }
}


// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void) {
    int table[MAX];
    int frequency[MAXNUMBER + 1];

    create_random(table);

    count_frequency(table, frequency);

    draw_histogram(frequency);
}
