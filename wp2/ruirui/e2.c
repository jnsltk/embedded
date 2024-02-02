#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX           5
#define NUMBER        10
#define ADD_FIRST_AMT 4

// ##### typedefs          ####
typedef struct q {
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations   #####

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
int main(int argc, char *argv[]) {
    int nr = 0;

    REGTYPE *act_post, *head = NULL;

    srand(time(0));   //   Random seed
    head = random_list();

    for (unsigned char i = 0; i < ADD_FIRST_AMT; i++)
        head = add_first(head, i);

    act_post = head;

    while (act_post != NULL) {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL) {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}

// ====     End of main   ======================================

REGTYPE *random_list(void) {
    int nr, i = 1;
    REGTYPE *top, *old, *item;

    top = old = malloc(sizeof(REGTYPE));

    while (i < NUMBER) {
        item = malloc(sizeof(REGTYPE));
        item->number = random() % (MAX + 1);
        item->prev = old;

        old->next = item;
        old = item;

        i++;
    }

    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data) {
    REGTYPE *new = malloc(sizeof(REGTYPE));
    new->number = data;
    new->next = temp;

    temp->prev = new;
    return new;
}