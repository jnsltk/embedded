#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         20
#define HIGHEST_NUM 99

int main(void) {
    int a[MAX];
    int *p = a;

    srand(time(NULL));
    for (char i = 0; i < MAX; i++) {
        a[i] = rand() % HIGHEST_NUM + 1;
    }

    printf("The value of the address of the array (pointer) is: %p\n", a);
    printf("First integer in the array is (array[0]): %d\n", a[0]);
    printf("The last integer in the array is: %d\n", a[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %ld\n", sizeof(int));
    printf("The size of the whole array in bytes is: %ld\n", sizeof(a));

    printf("Value of each element in array: \n");
    do {
        printf("%d ", *p);
    } while (++p - a < MAX);
    putchar('\n');

    printf("Value of each element * 2 in array: \n");
    p = a;
    do {
        printf("%d ", *p * 2);
    } while (++p - a < MAX);
    putchar('\n');
}

