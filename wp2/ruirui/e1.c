#include <stdio.h>

/* ------------------------- MACROS ------------------------- */

#define MAX_COORD 9   // 99

#define QUIT_CHAR 'q'
#define TURN_CHAR 't'
#define MOVE_CHAR 'm'

/* --------------------- ENUMS & STRUCTS & ARRAYS -------------------- */

char *directions[4] = {"North", "East", "South", "West"};

enum DIRECTION { N, O, S, W };

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

/* ------------------------ FUNCTIONS ----------------------- */

void move(ROBOT *robot) {
    switch (robot->dir) {
        case N:
            if (robot->ypos == MAX_COORD)
                printf("Can not move further North!\n");
            else
                robot->ypos++;
            break;
        case O:
            if (robot->xpos == MAX_COORD)
                printf("Can not move further East!\n");
            else
                robot->xpos++;
            break;
        case S:
            if (robot->ypos == 0)
                printf("Can not move further South!\n");
            else
                robot->ypos--;
            break;
        case W:
            if (robot->xpos == 0)
                printf("Can not move further West!\n");
            else
                robot->xpos--;
            break;
    }
}

void turn(ROBOT *robot) {
    robot->dir = (robot->dir + 1) % 4;
}

int main() {
    ROBOT robot;
    char c;

    robot.xpos = MAX_COORD / 2;
    robot.ypos = MAX_COORD / 2;
    robot.dir = N;

    while ((c = getchar()) != QUIT_CHAR && c != EOF) {
        if (c == '\n') {
            printf("The robot is at (%d,%d), Heading %s\n", robot.xpos, robot.ypos,
                   directions[robot.dir]);
            continue;
        }

        switch (c) {
            case '\n':
                continue;
            case MOVE_CHAR:
                move(&robot);
                break;
            case TURN_CHAR:
                turn(&robot);
                break;
            default:
                printf("Valid inputs are (%c,%c,%c)\n", MOVE_CHAR, TURN_CHAR, QUIT_CHAR);
        }
    }
}