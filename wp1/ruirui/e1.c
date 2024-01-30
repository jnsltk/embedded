// (C) Henrik Lagrosen, Shiyao Xin, János Litkei, group: 35 (2024)
// Work package 1
// Exercise 1
// Submission code: 35128211

#include <stdio.h>   // includes standard I/O library for scanf and printf

// defines macro s0
#define S0 "In the beginning God created the heavens and the earth.\n"

// defines macro s1
#define S1                                                                                         \
    "Now the earth was formless and empty, darkness was over the surface of the deep, and the "    \
    "Spirit of God was hovering over the waters.\n"

// defines macro s2
#define S2 "And God said, \" Let there be light, \" and there was light.\n"

// defines macro s3
#define S3 "God saw that the light was good, and he separated the light from the darkness.\n"

// defines macro s4
#define S4                                                                                         \
    "God called the light \"day,\" and the darkness he called \"night.\" And there was evening, "  \
    "and there was morning—the first day.\n"

// main function of the program
int main() {
    // initialises variable for the alternative selected from stdin, with random value
    int alt = -1;

    do {                     // starts do-while loop
        scanf("%d", &alt);   // scans digit from stdin into alt

        if (alt == 1)   // if alt is 1
            printf(S0);
        else if (alt == 2)   // if alt is 2
            printf(S1);
        else if (alt == 3)   // if alt is 3
            printf(S2);
        else if (alt == 4)   // if alt is 4
            printf(S3);
        else if (alt == 5)   // if alt is 5
            printf(S4);

    } while (alt >= 1 && alt <= 5);   // while 0 < alt < 6

    return 0;   // quits program
}