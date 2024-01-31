// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

// Include section
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main program section

/**
 *
 */

// Main function
int main (int argc, char *argv[])
{
    unsigned char max_digits = (sizeof (long) * 8) + 1;
    // char buffer[max_digits];
    char bin_num[max_digits];
    char *input;
    // char bin_num[str_len];
    if (argc < 2)
        {
            char c;
            //*bin_num = bin_num[max_digits];
            int i = 0;
            while (((c = getchar ()) != EOF) && (c != '\n')
                   && ((c == '1') || (c == '0')))
                {
                    *input++ = c;
                    i++;
                }
            input = input - i;
            *bin_num = bin_num[i + 1];
            for (int m = 0; m < i; m++)
                {
                    bin_num[m] = *input;
                    input++;
                }
            bin_num[i] = '\0';
        }
    else
        {
            int str_len = strlen (argv[1]) + 1;
            strcpy (bin_num, argv[1]);
            printf ("pass by argv %s\n", bin_num);
        }

    int output = 0;

    /**
     * Solution 1
     */
    // char *c = bin_num;
    // do
    //     {
    //         int bit = *c == '1' ? 1 : 0;
    //         output = (output << 1) | bit;
    //         // printf ("%c\n", *c);
    //         c++;
    //     }
    // while (*c);
    // printf ("%X\n", output);

    /**
     * Solution 2
     */
    int counter = 3;
    char *c = bin_num;
    while (*c)
        {
            int bit = *c == '1' ? 1 : 0;
            output += pow (2, counter) * bit;
            if (counter > 0)
                {
                    counter--;
                }
            else
                {
                    counter = 3;
                    if (*(c + 1))
                        {
                            putchar ('0');
                        }
                }
            c++;
            // printf ("current output: %X\n", output);
        }
    printf ("%X\n", output);

    // exit the program
    return 0;
}