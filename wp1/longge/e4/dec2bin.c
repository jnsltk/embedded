#include <math.h>
#include <stdio.h>
#include <string.h>

int get_shift_no(unsigned long int n);
void show_help(char **argv);

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "ERROR: no argument provided\n");
        show_help(argv);
        return 2;
    }

    unsigned long int n;
    if (sscanf(argv[1], "%li", &n) != 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            show_help(argv);
            return 0;
        }

        fprintf(stderr, "ERROR: not an integer\n");
        show_help(argv);
        return 2;
    }

    int shift_no = get_shift_no(n);
    if (shift_no == 0) {
        printf(
            "Number too large for this system, please provide a number no longer than %ld bytes\n",
            sizeof(long));
        show_help(argv);
        return 2;
    }

    unsigned long int mask = 1UL << shift_no;

    while (mask != 0) {
        putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }
    putchar('\n');

    return 0;
}

int get_shift_no(unsigned long int n) {
    int min_bits = (int) log2(n) + 1;

    int i = 8;
    while (i < min_bits) {
        i *= 2;
    }

    if (i > sizeof(long) * 8) {
        return 0;
    }

    return i - 1;
}

void show_help(char **argv) {
    printf("Usage:\n %s [integer] -- Convert decimal integer to binary (maximum %ld bytes)\n %s "
           "[-h | --help] -- Show this help message\n",
           argv[0], sizeof(long), argv[0]);
}
