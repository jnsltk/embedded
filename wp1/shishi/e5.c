// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define section
// #define MAX 100      // Defines the maximum number of the values in the
// table #define MAXNUMBER 20 // Defines the maximus value of random numbers

/**
 * This program alculates statistical values for an array of integers,
 * and plots a histogram for the frequency of different numbers in the array.
 */

/* -------------------------- Function declarations -------------------------
 */

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random (int *tab, int MAX, int MAXNUMBER);

// This function takes the *tab of random numbers
// and creates a table with the frequecy counts for these numbers
void count_frequency (int *tab, int *freq, int MAX, int MAXNUMBER);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram (int *freq, int MAXNUMBER);

/* -------------------------- Function definitions --------------------------
 */

// Main program section

// The main entry point for the program
int main (int argc, char *argv[])
{
    const int MAX = atoi (argv[1]);
    const int MAXNUMBER = atoi (argv[2]);
    int table[MAX];
    int frequency[MAXNUMBER];
    create_random (table, MAX, MAXNUMBER);
    count_frequency (table, frequency, MAX, MAXNUMBER);
    draw_histogram (frequency, MAXNUMBER);
}

void create_random (int *tab, int MAX, int MAXNUMBER)
{
    srand (time (NULL));
    int num;
    for (int i = 0; i < MAX; i++)
        {
            num = 1 + rand () % MAXNUMBER;
            tab[i] = num;
        }
    for (int m = 0; m < MAX; m++)
        {
            printf ("%d\t", tab[m]);
        }
    printf ("\n");
}

void count_frequency (int *tab, int *freq, int MAX, int MAXNUMBER)
{
    // printf ("MAXNUMBER: %d\n", MAXNUMBER);
    for (int i = 0; i < MAXNUMBER; i++)
        {
            freq[i] = 0;
        }

    for (int m = 0; m < MAX; m++)
        {
            int value = tab[m];
            freq[value - 1]++;
        }
}

void draw_histogram (int *freq, int MAXNUMBER)
{
    char x = 'x';
    for (int i = 0; i < MAXNUMBER; i++)
        {
            if (freq[i] != 0)
                {
                    printf ("%d\t ", i + 1);
                    int times = freq[i];
                    while (times != 0)
                        {
                            putchar (x);
                            times--;
                        }
                    putchar ('\n');
                }
        }
}
