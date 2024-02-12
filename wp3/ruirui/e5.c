#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX     10
#define MIN_NUM 1
#define MAX_NUM 99

int arr[MAX], *ptr = arr;

int main() {
    srand(time(NULL));

    for (unsigned short i = 0; i < MAX; i++)
        arr[i] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;

    printf("The value of the address of the array(pointer) is: %p\n", arr);
    printf("First integer in the array is (array[0]): %d\n", arr[0]);
    printf("The last integer in the array is: %d\n", arr[MAX - 1]);
    printf("The size of an integer(number of bytes) is: %lu\n", sizeof(int));
    printf("The size of the whole array in bytes is: %lu\n", sizeof(arr));

    do {
        printf("%d * 2 = %d\n", *ptr, *ptr * 2);
    } while (++ptr - arr < MAX);
}