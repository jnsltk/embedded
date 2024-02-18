#include <stdio.h>

// bubble sort algorithm
void sort(int number, int tab[]) {
    int temp;

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

// binary search algorithm
int binary_search(int number, int tab[], int size) {
    int left = 0;
    int right = size - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (tab[middle] == number) {
            return middle;
        } else if (tab[middle] < number) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

// simple search by iterating through the array
int search(int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

    sort(10, test);

    int res = binary_search(23, test, 10);
    printf("Number found at: %d\n", res);

    
    res = search(23, test, 10);
    printf("Number found at: %d\n", res);

    int *p = test;

    do {
        printf("%d ", *p);
    } while ((++p - test) < 10);
}
