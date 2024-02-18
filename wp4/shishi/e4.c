// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>

/* -------------------------- Function declaration -------------------------- */
int search_number(int number, int tab[],
                  int size);          // This function determines if number is in the array
void sort(int number, int tab[]);     // This function sorts the list tab with bubble sort algorithm
void swap(int *num1, int *num2);      // This function swaps the values in two addresses
void find_min(int *tab, int **min);   // This function finds the minimum in a list
/* -------------------------- Main program section -------------------------- */

/**
 * This program
 * a) searches a number n in the list, returns the index for the first position of n,
 * otherwise it returns -1;
 * b) sorts an array of integers with bubble sort algorithm.
 */

int *last;   // declare a pointer to the last element of the list
int *prev;   // declare a pointer to the previous minimum on top of the list

// Main function
int main() {
    // initialize an array for the purpose of testing the search_number function
    int array[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

    int n = 10;
    int size = sizeof(array) / sizeof(int);   // store the size of the array
    last = array + size - 1;                  // store the address of the last element in the array

    int index = search_number(n, array, size);   // retrieve the index of n in the array
    printf("Result index: %d\n", index);

    prev = array;           // initialize prev with the first element address
    int *tab = array + 1;   // define a pointer to the second element in the array
    sort(*prev, tab);       // sort the array

    // print out the sorted array
    printf("Sorted array: ");
    int *p = array;
    int i = 0;
    while (p <= last) {
        printf("%d ", *p);
        p++;
    }
    putchar('\n');
    //  exit the program successfully
    return 0;
}

// Given an integer n, an array of integers and the size of the array, this function determines if n
// is in the array. If n is in the array, the function returns the index for the first position of n
// (in case of several) otherwise it returns -1.
int search_number(int number, int tab[], int size) {
    int *ptr = tab;             // define a pointer to the array tab
    int i = 0;                  // define a counter, used for array index
    while (i < size) {          // loop through the array tab
        if (*ptr == number) {   // if the number is in the array
            return i;           // return its index
        }
        i++;     // increment the index by 1
        ptr++;   // move the pointer forward
    }
    return -1;   // return -1, indicates no result found
}

// This function sorts an array of integers via bubble sort algorithm
void sort(int number, int tab[]) {
    int *ptr = tab;   // define a pointer to the current list

    int *min = tab;   // define a pointer to store the minimum value, and initialize it to the first
                      // element in the current list
    int **min_ptrptr = &min;     // define a pointer of the pointer to the minimum(min)
    find_min(ptr, min_ptrptr);   // find the minimum value in the list

    // swap the minimum with the first in list
    if (*min < number) {
        swap(prev, min);
    }

    //  repeat this but exclude the previous minimum on top of the list and search only in the rest
    //  of the list
    prev = ptr++;   // update the previous minimum on top of the list, then move the ptr forward
    if (ptr <= last) {      // check if the pointer ptr reaches the last element in the array
        sort(*prev, ptr);   // sort the rest of the array recursively
    }
}

// This function swap the values of two addresses
void swap(int *num1, int *num2) {
    int temp = *num1;   // store the num1 value temporarily in a variable
    *num1 = *num2;      // update the num1 value to the num2 value
    *num2 = temp;       // update the num2 value to the temp(previous num1) value
}

// This function finds the minimum value in the list
void find_min(int *tab, int **min) {
    int *ptr = tab;           // define a pointer to the current list
    while (ptr <= last) {     // loop until the last element in the list
        if (*ptr < **min) {   // check if the current value is smaller than the min value
            *min = ptr;       // update the min value to the current value
        }
        ptr++;   // move the pointer forward
    }
}