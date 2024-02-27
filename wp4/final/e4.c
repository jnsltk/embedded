// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 4
// Exercise 4
// Submission code: 892561

#include <stdio.h>   // include the standard input/output library

void sort(int number, int tab[]) {   // function to sort the array
    int temp;                        // temporary variable to store the value of the current element
    for (int i = 0; i < number; i++) {   // iterate through the array
        for (int j = i; j < number - 1;
             j++) {                      // iterate from the current element to the end of the array
            if (tab[j] > tab[j + 1]) {   // if the current element is greater than the next one
                temp =
                    tab[j];   // assign the value of the current element to the temporary variable
                tab[j] =
                    tab[j + 1];   // assign the value of the next element to the current element
                tab[j + 1] =
                    temp;   // assign the value of the temporary variable to the next element
            }
        }
    }
}

int search(int number, int tab[], int size) {   // function to search for a number in the array
    for (int i = 0; i < size; i++) {            // iterate through the array
        if (tab[i] == number) {                 // if the current element is equal to the number
            return i;                           // return the index of the current element
        }
    }
    return -1;   // if the number is not found, return -1
}

int main(void) {                                         // main function
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};   // test array

    printf("Unsorted array with indices:\n");
    int i = 0;                         // index variable
    int *p = test;                     // pointer to the first element of the array
    do {                               // iterate through the array...
        printf("%d: %d\n", i++, *p);   // print the current element
    } while ((++p - test) < 10);       // ...while the pointer is not at the end of the array

    printf("Searching for the number 23 in the array...\n");
    int res = search(23, test, 10);   // search for the number 23 in the array
    printf("Number found at: %d\n", res);

    sort(10, test);   // sort the array

    printf("Sorted array with indices:\n");
    i = 0;                             // index variable
    p = test;                          // pointer to the first element of the array
    do {                               // iterate through the array...
        printf("%d: %d\n", i++, *p);   // print the current element
    } while ((++p - test) < 10);       // ...while the pointer is not at the end of the array
}
