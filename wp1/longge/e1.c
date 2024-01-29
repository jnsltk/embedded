#include <stdio.h>

const char *sents[] = {"This is a very nice English sentence\n",
                       "I have no idea what I should write in this sentence\n",
                       "Seriously, I've no clue what to write here\n",
                       "I\'ve decided to study Sfotware Engineering and not Literature\n"
                       "because I have a hard time coming up with sentences\n",
                       "Alright one more sentence and then I\'m done\n"};

int main(int argc, char *argv[]) {
    int opt;
    do {
        printf("Please enter a number between 1-5: \n");
        scanf("%d", &opt);
        if (opt > 0 && opt < 6) {
            printf("%s", sents[opt - 1]);
        }
    } while (opt > 0 && opt < 6);
}
