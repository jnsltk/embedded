// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: xxxxx

/* ----------------------------- Include section ---------------------------- */
#include <math.h>
#include <stdio.h>

/* ------------------------------ Define macros ----------------------------- */
#define START_DIR N;   // the start direction is always north for the robot

/* ------------------------------- Define enum ------------------------------ */
enum DIRECTION { N, O, S, W };

/* ------------------------------ Define struct ----------------------------- */
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

/* -------------------------- Functions declaration ------------------------- */
void move(ROBOT **robot_ptr);
void turn(ROBOT **robot_ptr);
int propmt_start(ROBOT **robot_ptr, char *commands);
void perform_commands(ROBOT *robot_ptr, char *commands);
int validate_num(char *input, int *num);

/* -------------------------- Main program section -------------------------- */
int main(int argc, char **argv) {
    int x_cord;
    int y_cord;
    char commands[20];    // define a string of characters 'm' and 't' to move or turn the robot
    ROBOT robot;          // define one struct ROBOT variable
    ROBOT *robot_ptr;     // define a pointer to a struct ROBOT
    robot_ptr = &robot;   // assign address of robot to robot_ptr
    int status = propmt_start(&robot_ptr, commands);
    char c;
    // while (status != 2) {
    while (status != 2) {
        // loop prompting for user input until the input is valid,
        // i.e., return value 1 -> true, 0 -> false
        while (status == 0) {
            // bool = propmt_start_pos(&x_cord, &y_cord);
            printf("Error: Invalid input.\n");
            status = propmt_start(&robot_ptr, commands);
        }
        // printf("current code: %d", status);
        if (status == 1) {
            perform_commands(&robot, commands);
            status = propmt_start(&robot_ptr, commands);
        }
    }
    // exit the program successfully
    return 0;
}

// int propmt_start_pos(int *x_cord, int *y_cord) {
int propmt_start(ROBOT **robot_ptr, char *commands) {
    char x_input[3];
    char y_input[3];
    char c;
    int num = 0;
    printf("Enter the x coordinate, y coordinate and commands for the robot's starting postion:\n");
    // if ((c = getchar()) == 'q') {
    //     printf("quit code\n");
    //     return 2;
    // } else {
    //     // printf("got c: %c", c);
    //     x_input[0] = c;
    // }
    // scanf("%s %s %s", x_input, y_input, commands);
    for (int i = 0; i < 3; i++) {
        y_input[i] = 0;
        x_input[i] = 0;
    }
    for (int i = 0; i < 20; i++) {
        commands[i] = 0;
    }
    int elem_count = 1;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            break;
        }
        if (c == 'q') {
            return 2;
        }
        if (elem_count == 1) {
            if (c != ' ') {
                x_input[i++] = c;
            } else {
                i = 0;
                elem_count++;
            }
        } else if (elem_count == 2) {
            if (c != ' ') {
                y_input[i++] = c;
            } else {
                i = 0;
                elem_count++;
            }
        } else if (elem_count == 3) {
            if (c != ' ') {
                commands[i++] = c;
            } else {
                i = 0;
                elem_count++;
            }
        }
    }
    // printf("input x: %s y: %s commands: %s\n", x_input, y_input, commands);
    //  printf("commands: %s\n", commands);

    if (validate_num(x_input, &num) == 0) {
        return 0;
    } else {
        (*robot_ptr)->xpos = num;
        num = 0;
    }
    if (validate_num(y_input, &num) == 0) {
        return 0;
    } else {
        (*robot_ptr)->ypos = num;
        num = 0;
    }

    char *command = commands;
    while (*command) {
        if ((*command != 't') && (*command != 'm')) {
            return 0;
        }
        command++;
    }
    (*robot_ptr)->dir = START_DIR;
    // printf("direction: %d", (*robot_ptr)->dir);
    return 1;
}

void perform_commands(ROBOT *robot_ptr, char *commands) {
    char *c = commands;   // define a variable to store the command character
    while (*c) {
        if (*c == 'm') {
            move(&robot_ptr);
        } else if (*c == 't') {
            turn(&robot_ptr);
        }
        c++;
    }

    // check the x and y cords ranging between 0-99
    printf("The robot is currently at postion -> x: %d\ty: %d\n", (robot_ptr)->xpos,
           (robot_ptr)->ypos);
}

void move(ROBOT **robot_ptr) {
    // check direction
    if ((*robot_ptr)->dir == N) {
        if ((*robot_ptr)->ypos < 99) {
            (*robot_ptr)->ypos++;
        } else {
            printf("The robot can not move further to the north, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == S) {
        if ((*robot_ptr)->ypos > 0) {
            (*robot_ptr)->ypos--;
        } else {
            printf("The robot can not move further to the south, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == O) {
        if ((*robot_ptr)->xpos < 99) {
            (*robot_ptr)->xpos++;
        } else {
            printf("The robot can not move further to the east, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == W) {
        if ((*robot_ptr)->xpos > 0) {
            (*robot_ptr)->xpos--;
        } else {
            printf("The robot can not move further to the west, as it has reached the range.\n");
        }
    }
}

void turn(ROBOT **robot_ptr) {
    // check current direction
    if ((*robot_ptr)->dir == N) {
        printf("in here\n");
        (*robot_ptr)->dir = O;
    } else if ((*robot_ptr)->dir == S) {
        (*robot_ptr)->dir = W;
    } else if ((*robot_ptr)->dir == O) {
        (*robot_ptr)->dir = S;
    } else if ((*robot_ptr)->dir == W) {
        (*robot_ptr)->dir = N;
    }
}

int validate_num(char *input, int *num) {
    char *c = input;
    int i = 0;
    while (*c) {
        if (*c > 57 || *c < 48 || i >= 2) {
            return 0;
        }
        (*num) = (*num) * pow(10, i);
        (*num) += *c - 48;
        if (*num > 99 || *num < 0) {
            return 0;
        }
        i++;
        c++;
    }
    return 1;
}