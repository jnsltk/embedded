#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_help(char **argv);

int main(int argc, char **argv) {
    char *bin_n = NULL;

    if (argc == 2) {
        bin_n = argv[1];
    } else {
        char *str_read = fgets(bin_n, sizeof(long), stdin);

        if (!str_read) {
            fprintf(stderr, "ERROR: no argument provided\n");
            show_help(argv);
            return 2;
        }
    }

    if (strlen(bin_n) > sizeof(long) * 8) {
        printf(
            "Number too large for this system, please provide a number no longer than %ld bytes\n",
            sizeof(long));
    }

    int bin_place = pow(2, strlen(bin_n) - 1);
    unsigned long int n = 0;
    for (int i = 0; i < strlen(bin_n); i++) {
        if (bin_n[i] == '1') {
            n += bin_place;
        } else if (bin_n[i] != '0') {
            printf("Number not binary. Please provide a binary number no longer than %ld bytes\n",
                   sizeof(long));
            show_help(argv);
            return 2;
        }
        bin_place /= 2;
    }
    printf("%lX\n", n);
    return 0;
}

void show_help(char **argv) {
    printf("Usage:\n %s [integer] -- Convert decimal integer to binary (maximum %ld bytes)\n %s "
           "[-h | --help] -- Show this help message\n",
           argv[0], sizeof(long), argv[0]);
}
