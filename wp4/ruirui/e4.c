#include <stdio.h>

/* ------------------ FUNCTION DECLARATIONS ----------------- */

int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);

/* ------------------ FUNCTION DEFINITIONS ------------------ */

int main() {
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int testSize = sizeof(test) / sizeof(int);
    int searchRes;

    for (int i = 0; i < testSize; i++) {
        searchRes = search_number(test[i], test, testSize);
        if (test[i] < 10)
            printf("%d   : expected %d,  got %d\n", test[i], i, searchRes);
        else
            printf("%d  : expected %d,  got %d\n", test[i], i, searchRes);

        if (i != searchRes) {
            fprintf(stderr, "Search failed tests\n");
            return 1;
        }
    }

    searchRes = search_number(-10, test, testSize);
    printf("-10 : expected -1, got %d\n", searchRes);

    if (searchRes != -1) {
        fprintf(stderr, "Search failed tests\n");
        return 1;
    }

    sort(testSize, test);

    printf("The sorted list is:\n");

    for (int i = 0; i < testSize; i++)
        printf("%d ", test[i]);

    printf("\n");
}

int search_number(int number, int tab[], int size) {
    for (int i = 0; i < size; i++)
        if (tab[i] == number)
            return i;
    return -1;
}

void sort(int number, int tab[]) {
    int tmp;
    for (int i = 0; i < number; i++) {
        int smolI = i;
        for (int j = i + 1; j < number; j++)
            if (tab[j] < tab[smolI])
                smolI = j;
        tmp = tab[smolI];
        tab[smolI] = tab[i];
        tab[i] = tmp;
    }
}