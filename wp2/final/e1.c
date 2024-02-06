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
// Main function
int main(int argc, char **argv) {
    char commands[20];    // define a string of characters 'm' and 't' to move or turn the robot
    ROBOT robot;          // define one struct ROBOT variable
    ROBOT *robot_ptr;     // define a pointer to a struct ROBOT
    robot_ptr = &robot;   // assign address of robot to robot_ptr
    int status = propmt_start(
        &robot_ptr,
        commands);   // define a variable to store the status of the program. 2->End the program

    while (status !=
           2) {   // loop (let the program run) as long as user does not want to quit the program
        // loop prompting for user input until the input is valid,
        // i.e., return value 1 -> true, 0 -> false
        while (status == 0) {
            printf("Error: Invalid input.\n");
            status = propmt_start(&robot_ptr,
                                  commands);   // retrieve the valid status of user input again
        }
        if (status == 1) {                        // check whether the user input is valid
            perform_commands(&robot, commands);   // proceed the commands to control the robot
            status = propmt_start(&robot_ptr, commands);   // propmting user input again
        }
    }
    // exit the program successfully
    return 0;
}

// This function propmts commands from the user, and return the valid status, i.e., whether the user
// input is valid
int propmt_start(ROBOT **robot_ptr, char *commands) {
    char x_input[3];   // declare an array to store x coordinate from the user input
    char y_input[3];   // declare an array to store y coordinate from the user input
    char c;            // declare a char variable to store stdin temporarily
    int num = 0;       // define a variable to store the valid x/y coordinates temporarilly after
                       // validating the user input
    printf("Enter the x coordinate, y coordinate and commands for the robot's starting postion:\n");

    // initialize the array
    for (int i = 0; i < 3; i++) {
        y_input[i] = 0;   // initialize the elements in the array with default value 0
        x_input[i] = 0;   // initialize the elements in the array with default value 0
    }
    // initialize the array
    for (int i = 0; i < 20; i++) {
        commands[i] = 0;   // initialize the elements in the array with default value 0
    }
    int elem_count = 1;   // define a variable to store the number of elements from the user input
    int i = 0;            // define a variable to store the number of elements in the array
    while ((c = getchar()) != EOF) {   // read all the input chars
        if (c == '\n') {               // when it reaches the new line
            break;                     // break out the loop
        }
        if (c == 'q') {   // when it reads 'q' -> user wants to quit the program
            return 2;     // return the program status as 2 to the main function
        }
        if (elem_count == 1) {      // when it is the 1st element from the user input
            if (c != ' ') {         // check if it is not a space
                x_input[i++] = c;   // add the char to x_input
            } else {                // when it is a space
                i = 0;              // reset the index counter for the array
                elem_count++;   // the number of the element from the user input is incremented by 1
            }
        } else if (elem_count == 2) {   // when it is the 2nd element from the user input
            if (c != ' ') {             // check if it is not a space
                y_input[i++] = c;       // add the char to y_input
            } else {                    // when it is a space
                i = 0;                  // reset the index counter for the array
                elem_count++;   // the number of the element from the user input is incremented by 1
            }
        } else if (elem_count == 3) {   // when it is the 3rn element from the user input
            if (c != ' ') {             // check if it is not a space
                commands[i++] = c;      // add the char to commands
            } else {                    // when it is a space
                i = 0;                  // reset the index counter for the array
                elem_count++;   // the number of the element from the user input is incremented by 1
            }
        }
    }

    if (validate_num(x_input, &num) ==
        0) {                        // check if the x coordinate is invalid from user input
        return 0;                   // reture false
    } else {                        // if it is valid
        (*robot_ptr)->xpos = num;   // store the valid value in the robot xpos
        num = 0;                    // reset the num value to 0
    }
    if (validate_num(y_input, &num) ==
        0) {        // check if the x coordinate is invalid from user input
        return 0;   // reture false
    } else {
        (*robot_ptr)->ypos = num;   // store the valid value in the robot ypos
        num = 0;                    // reset the num value to 0
    }

    char *command = commands;                           // define a pointer to commands
    while (*command) {                                  // loop through all commands
        if ((*command != 't') && (*command != 'm')) {   // if the command is not 'm' or 't'
            return 0;                                   // reture false
        }
        command++;   // move the pointer forward
    }
    (*robot_ptr)->dir = START_DIR;   // set the start position of the robot (N)
    return 1;                        // return true
}

// This function performs commands from the user, move or turn the robot
void perform_commands(ROBOT *robot_ptr, char *commands) {
    char *c = commands;           // define a variable to store the command character
    while (*c) {                  // loop through the commands
        if (*c == 'm') {          // when it is a move command
            move(&robot_ptr);     // move the robot
        } else if (*c == 't') {   // when it is a turn command
            turn(&robot_ptr);     // turn the robot
        }
        c++;   // move the pointer forward
    }

    printf("The robot is currently at postion -> x: %d\ty: %d\n", (robot_ptr)->xpos,
           (robot_ptr)->ypos);
}

// This function moves the robot 1 step
// and ensures the x and y cords ranging between 0-99
void move(ROBOT **robot_ptr) {
    // check direction
    if ((*robot_ptr)->dir == N) {        // when the direction the N
        if ((*robot_ptr)->ypos < 99) {   // if the current y cord is less than the max range
            (*robot_ptr)->ypos++;        // the robot can move 1 step
        } else {                         // otherwise, output reaching the range message
            printf("The robot can not move further to the north, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == S) {   // when the direction the S
        if ((*robot_ptr)->ypos > 0) {      // if the current y cord is bigger than the min range
            (*robot_ptr)->ypos--;          // the robot can move 1 step
        } else {                           // otherwise, output reaching the range message
            printf("The robot can not move further to the south, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == O) {   // when the direction the O
        if ((*robot_ptr)->xpos < 99) {     // if the current y cord is less than the max range
            (*robot_ptr)->xpos++;          // the robot can move 1 step
        } else {                           // otherwise, output reaching the range message
            printf("The robot can not move further to the east, as it has reached the range.\n");
        }
    } else if ((*robot_ptr)->dir == W) {   // when the direction the W
        if ((*robot_ptr)->xpos > 0) {      // if the current y cord is bigger than the min range
            (*robot_ptr)->xpos--;          // the robot can move 1 step
        } else {                           // otherwise, output reaching the range message
            printf("The robot can not move further to the west, as it has reached the range.\n");
        }
    }
}

// This function turns the robot 90 degrees clockwise
void turn(ROBOT **robot_ptr) {
    // check current direction
    if ((*robot_ptr)->dir == N) {          // when the direction the N
        (*robot_ptr)->dir = O;             // the robot turns to O
    } else if ((*robot_ptr)->dir == S) {   // when the direction the S
        (*robot_ptr)->dir = W;             // the robot turns to W
    } else if ((*robot_ptr)->dir == O) {   // when the direction the O
        (*robot_ptr)->dir = S;             // the robot turns to S
    } else if ((*robot_ptr)->dir == W) {   // when the direction the W
        (*robot_ptr)->dir = N;             // the robot turns to N
    }
}

// This function validates the user input
int validate_num(char *input, int *num) {
    char *c = input;   // define a pointer to the input
    int i = 0;         // define a variable used as exponent
    while (*c) {       // loop through the input
        if (*c > '9' || *c < '0' ||
            i >= 2) {   // when the current char is not a number or the input is more than 2 digits
            return 0;   // return 0 as invalid(false)
        }
        (*num) = (*num) * pow(10, i);   // multiply the number by 10^i
        (*num) += *c - 48;              // convert char to int
        if (*num > 99 || *num < 0) {    // check the number is not within the required range
            return 0;                   // return 0 as invalid (false)
        }
        i++;   // increment by 1
        c++;   // move the pointer forward
    }
    return 1;   // return valid (true)
}