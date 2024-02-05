// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------ Define macros ----------------------------- */
#define MAX 5

/* ------------------------------ Define struct ----------------------------- */
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

/**
 * This program reates a linked list with a NUMBER of records of type REGTYPE.
 */

// Main function
int main(int argc, char *argv[]) {
    int nr = 0;                        // define a counter used for counting the number of nodes
    REGTYPE *act_post, *head = NULL;   // define pointers with type REGTYPE

    srand(time(0));         // Random seed
    head = random_list();   // set the head node
    act_post = head;        // set the pointer to head

    while (act_post != NULL) {   // loop until it reaches the last node
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;   // move the pointer to the next node
    }

    char input[4];          // declare an array to store user input
    int i = 0;              // define a variable as the counter in the loop
    int data = 0;           // define a variable to store the input number after validation
    int status = 0;         // define a variable to store the input validation status
    while (status != 1) {   // loop until user gives a valid input
        for (int i = 0; i < 4; i++) {   // initialize the input array
            input[i] = 0;               // initialize the element with 0 as default
        }
        data = 0;   // reset the input number to default 0
        printf("\nEnter a number between 0 and 100: ");
        char c;   // declare a variable to store the stdin temporarily
        while ((c = getchar()) != EOF &&
               c != '\n') {   // loop until it reaches the end and it is not a new line
            input[i++] = c;   // store the read in char in the input array and then increment the
                              // counter(index) by 1
        }
        status = validate_num(
            input,
            &data);   // validate the input value, and store the result in the variable status
        i = 0;        // reset the counter to default 0
    }
    REGTYPE *temp;                  // declare a pointer of type REGTYPE
    temp = head;                    // set the pointer to head
    head = add_first(temp, data);   // update the head node after adding a new node to the beginning
    act_post = head;                // reset the act_post pointer to head

    nr = 0;   // reset the node counter to 0
    printf("\n\nThe result after inserting a new node at the beginning : ");
    while (act_post != NULL) {   // loop through all nodes
        printf("\nPost nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;   // move the pointer to the next node
    }

    // Free the allocated memory
    while ((act_post = head) != NULL) {   // loop through the nodes
        head = act_post->next;            // update the head node to the adjacent node
        free(act_post);                   // free the allocated memory
    }

    // exit the program successfully
    return 0;
}

// This function creates a linked list with a NUMBER of records of type REGTYPE.
// The value of the variable data is given a random number between 0 and 100.
REGTYPE *random_list(void) {
    int nr, i = 0;   // define variable nr to store the generalized random number, and variable i to
                     // store the counter for nodes
    REGTYPE *top, *old, *item;       // declare pointers with type REGTYPE
    top = malloc(sizeof(REGTYPE));   // create node top

    while (i <= 3) {          // loop until
        if (item != NULL) {   // check item has been created
            old = item;       // set pointer old to pointer item
        }
        item = malloc(sizeof(REGTYPE));   // create node item
        nr = rand() % 100;                // place the generalized random number in the variable nr

        if (i == 0) {           // when it is the first node
            top->number = nr;   // set the number of the top node with the value
            top->prev = NULL;   // set the previous node address to NULL
        }

        item->number = nr;      // set node item number with the value
        if (i == 1) {           // when it is the second node
            top->next = item;   // set the next of the top node to item's address
            item->prev = top;   // set the previous node address to top's address
        }
        if (i > 1) {             // when it is the third node
            old->next = item;    // set the node old's next node address to item's address
            item->prev = old;    // set the previous node address to old's address
            item->next = NULL;   // set the item node's next node address to NULL
        }
        i++;   // increment the node counter by 1
    }
    item->next = NULL;   // set the node item's next address to NULL
    return (top);        // return the head node
}

// This function adds a new record to the first position of the list and assign the field numbers
// the value of data. The function must return a pointer to the new first entry in the list. Extend
// main() so that this function is tested
REGTYPE *add_first(REGTYPE *temp, int data) {
    REGTYPE *new;                    // declare a pointer of type REGTYPE
    new = malloc(sizeof(REGTYPE));   // create node new
    if (new != NULL) {               // check if node new has been created
        new->number = data;          // set the node new value
        new->prev = NULL;            // set the node new previous node address to NULL
        if (temp != NULL) {          // if the temp (the head) has been created
            new->next = temp;        // set the node new's next to the temp address
            temp->prev = new;        // set the prev to the node new's address
        }
    }
    // REGTYPE *test = new;

    return (new);   // return the new head
}

// This function validates user input
int validate_num(char *input, int *num) {
    char *c = input;   // define a pointer to the input
    int i = 0;         // define a counter to count the number of elements in the input
    while (*c) {       // loop through the input
        if (*c > '9' || *c < '0') {   // check if the input is not valid number
            return 0;                 // return false (invalid)
        }
        if (i > 0) {                // if it is not the first char from the input
            (*num) = (*num) * 10;   // multiplying the current number by 10, e.g., 3 -> 30
        }
        (*num) += *c - 48;              // convert the char to int
        if (*num > 100 || *num < 0) {   // if the converted number is out of range (0-100)
            return 0;                   // return false (invalid)
        }
        i++;   // increment the counter by 1
        c++;   // move the pointer forward
    }
    return 1;   // return true (valid)
}