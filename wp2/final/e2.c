#include <stdio.h>    // includes standard i/o library for putchar, getchar, printf, etc.
#include <stdlib.h>   // includes standard library for malloc, free, etc.
#include <time.h>     // includes time library for time function for random seed

// #### Constants #####
#define NUMBER        100   // defines the maximum number for random number generation
#define MAX           5     // defines the amount of nodes initially created in the list
#define ADD_FIRST_AMT 4     // defines the amount of nodes to add to the list

// ##### typedefs          ####
typedef struct q {    // defines a linked list items struct
    int number;       // the value of the node
    struct q *next;   // pointer to the next node
    struct q *prev;   // pointer to the previous node
} REGTYPE;            // names it REGTYPE

// ##### Function declarations   #####

REGTYPE *random_list(void);   // declares function to create a random list
// declares function to add a node to the beginning of the list
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
int main(int argc, char *argv[]) {

    // declares pointer to head and temporary pointer to current node
    REGTYPE *act_post, *head = NULL;
    srand(time(NULL));      //   Random seed
    head = random_list();   // Create a random list

    int nr = 0;                  // counter used when printing list
    act_post = head;             // sets the current node to the head of the list
    while (act_post != NULL) {   // loop through the list until no more nodes
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;   // sets the current node to the next node
    }

    putchar('\n');   // print a newline character

    for (unsigned char i = 0; i < ADD_FIRST_AMT; i++)   // loop through the amount of nodes to add
        head = add_first(head, i);                      // adds a node to the beginning of the list

    act_post = head;             // sets the current node to the head of the list
    nr = 0;                      // resets the counter used when printing list
    while (act_post != NULL) {   // loop through the list until no more nodes
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;   // sets the current node to the next node
    }

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL) {   // loop through the list until no more nodes
        head = act_post->next;            // sets the head to the next node
        free(act_post);                   // frees the current node
    }

    return 0;   // returns 0 to indicate successful execution
}

// ====     End of main   ======================================

// ##### Function definitions #####

// Defines function to create a random list
REGTYPE *random_list(void) {
    int i = 0;                                 // sets counter to 0
    REGTYPE *old = NULL, *item, *top = NULL;   // declares pointers used when creating list

    old = malloc(sizeof(REGTYPE));   // allocates memory for the first node

    while (i < MAX) {                     // loop through the amount of nodes to create
        item = malloc(sizeof(REGTYPE));   // allocates memory for the current node
        item->number =
            rand() % (NUMBER + 1);   // sets the value of the current node to a random number

        item->prev = old;   // sets the previous node of the current node to the old node

        if (old != NULL)
            old->next = item;   // sets the next node of the old node to the current node
        old = item;             // sets the old node to the current node

        if (top == NULL)   // if it is the first node
            top = old;     // sets the top node to the current node

        i++;   // increments the counter of how many nodes have been created
    }

    return top;   // returns the top node of the list
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data) {
    REGTYPE *new = malloc(sizeof(REGTYPE));   // allocates memory for the new node
    new->number = data;                       // sets the value of the new node to the argument
    new->next = temp;   // sets the next node of the new node to the current head

    temp->prev = new;   // sets the previous node of the current head to the new node
    return new;         // returns the new node as the new head
}