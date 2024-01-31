#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const int shift_val = atoi(argv[1]);
    int input;

    while ((input = getchar()) != EOF) {
        char start;
        if (input >= 'A' && input <= 'Z') {
            start = 'A';
        } else if (input >= 'a' && input <= 'z') {
            start = 'a';
        } else if (input != '\n') {
            printf("Input contains special characters. Please type only upper- and lower-case "
                   "letters\n");
            return 0;
        }

        if (input == '\n') {
            putchar('\n');
        } else {
            int encoded_char = ((input - start + shift_val) % 26) + start;
            putchar(encoded_char);
        }
    }

    return 0;
}
