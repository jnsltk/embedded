// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------ Define macros ----------------------------- */
#define MAX 5

/* -------------------------- Function declaration -------------------------- */
void fill_array(int *nums);

/* -------------------------- Main program section -------------------------- */

/**
 * This program creates an array of integers, array[MAX], and then fill it with MAX number of
 * random integers from 1 to 99.
 */

// Main function
int main() {

    int array[MAX];   // declare an array of integers

    // Initialize the array
    for (int i = 0; i < MAX; i++) {
        array[i] = 0;   // initialize each element with 0
    }
    fill_array(array);
    printf("The value of the address of the array (pointer) is: %p\n", &array);
    // printf("%p\n", &nums);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));
    printf("The size of the whole array in bytes is: %lu\n", (sizeof(int) * MAX));
    int i = 0;                  // define a counter
    int *num = array;           // define a pointer to the array
    while (*num && i < MAX) {   // loop the array via a pointer until the last element of the array
        printf("%d\t", *num);
        printf("%d\n", ((*num) * 2));
        i++;     // increment the counter
        num++;   // move the pointer forward
    }
    // exit the program successfully
    return 0;
}

void fill_array(int *nums) {
    srand(time(NULL));   // seed the number
    int num;             // declare a int variable
    for (int i = 0; i < MAX; i++) {
        num = rand() % 99 + 1;   // store the generated number in a variable temperarily
        nums[i] = num;           // assign the number in the array
        // printf("%d\n", nums[i]);
    }
}