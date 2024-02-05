// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct q {
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

/* -------------------------- Function declaration -------------------------- */

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
int validate_num(char *input, int *num);

/* -------------------------- Main program section -------------------------- */
int main(int argc, char *argv[]) {
    int nr = 0;
    REGTYPE *act_post, *head = NULL;

    srand(time(0));   // Random seed
    head = random_list();
    act_post = head;

    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // propmt for user input
    // printf("\nEnter a number between 0 and 100: ");
    char input[4];
    int i = 0;
    int data = 0;
    int status = 0;
    while (status != 1) {
        for (int i = 0; i < 4; i++) {
            input[i] = 0;
        }
        data = 0;
        printf("\nEnter a number between 0 and 100: ");
        char c;
        while ((c = getchar()) != EOF && c != '\n') {
            input[i++] = c;
        }
        status = validate_num(input, &data);
        i = 0;
    }
    REGTYPE *temp;
    temp = head;
    head = add_first(temp, data);
    act_post = head;

    nr = 0;
    printf("\n\nThe result after inserting a new node at the beginning : ");
    while (act_post != NULL) {
        printf("\nPost nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // Free the allocated memory
    while ((act_post = head) != NULL) {
        head = act_post->next;
        free(act_post);
    }

    // exit the program successfully
    return 0;
}

// This function creates a linked list with a NUMBER of records of type REGTYPE.
// The value of the variable data is given a random number between 0 and 100.
REGTYPE *random_list(void) {
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    top = malloc(sizeof(REGTYPE));   // create node

    while (i <= 3) {
        if (item != NULL) {
            old = item;
        }
        item = malloc(sizeof(REGTYPE));   // create node
        nr = rand() % 100;                // place the generalized random number in the variable nr
        // printf("Generated nr: %d\n", nr);
        if (i == 0) {
            top->number = nr;
            top->prev = NULL;
        }

        item->number = nr;
        if (i == 1) {
            top->next = item;
            item->prev = top;
        }
        if (i > 1) {
            old->next = item;
            item->prev = old;
            item->next = NULL;
        }
        i++;
    }
    item->next = NULL;
    return (top);
}

// This function adds a new record to the first position of the list and assign the field numbers
// the value of data. The function must return a pointer to the new first entry in the list. Extend
// main() so that this function is tested
REGTYPE *add_first(REGTYPE *temp, int data) {
    REGTYPE *new;
    new = malloc(sizeof(REGTYPE));   // create node
    if (new != NULL) {
        new->number = data;
        new->prev = NULL;
        if (temp != NULL) {
            new->next = temp;
            temp->prev = new;
        }
    }
    REGTYPE *test = new;

    return (new);
}

int validate_num(char *input, int *num) {
    char *c = input;
    int i = 0;
    while (*c) {
        if (*c > 57 || *c < 48) {
            return 0;
        }
        if (i > 0) {
            (*num) = (*num) * 10;
        }
        (*num) += *c - 48;
        if (*num > 100 || *num < 0) {
            return 0;
        }
        i++;
        c++;
    }
    return 1;
}