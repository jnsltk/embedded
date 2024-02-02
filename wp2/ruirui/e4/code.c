#include <stdio.h>

char i, maxes[] = {1, 3, 2, 1, 1};

void shiftIn(unsigned char n, unsigned char j) {
    if (j == maxes[i]) {
        if (n)
            i = -2;
    } else {
        shiftIn(n >> 1, j + 1);
        putchar((n & 1) + '0');
    }
}

int main(int argc, char **argv) {
    if (argc != 6)
        return fprintf(stderr, "5 args expected\n");

    for (i = 0; i < 5; i++) {
        if (argv[i + 1][1] != '\0')
            return fprintf(stderr, "Err: Bad argument\n");

        shiftIn(argv[i + 1][0] - '0', 0);
    }

    putchar('\n');
}