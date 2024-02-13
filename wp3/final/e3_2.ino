// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 023513

#define ROW1 11 // define ROW1 to pin 11
#define ROW2 10 // define ROW2 to pin 10
#define ROW3 9 // define ROW3 to pin 9
#define ROW4 8 // define ROW4 to pin 8

#define COL1 7 // define COL1 to pin 7
#define COL2 6 // define COL2 to pin 6
#define COL3 5 // define COL3 to pin 5
#define COL4 4 // define COL4 to pin 4

// define the keys on the keypad
const char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'}, 
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

int getCol(); // function to get the column
int getRow(); // function to get the row
char getInputChar(int col, int row); // function to get the character that is pressed

void setup() // define the setup function, which runs once when the sketch starts
{
    Serial.begin(9600); // initialize the serial communication

    pinMode(ROW1, OUTPUT); // set the ROW1 pin to output
    pinMode(ROW2, OUTPUT); // set the ROW2 pin to output
    pinMode(ROW3, OUTPUT); // set the ROW3 pin to output
    pinMode(ROW4, OUTPUT); // set the ROW4 pin to output

    pinMode(COL1, INPUT); // set the COL1 pin to input
    pinMode(COL2, INPUT); // set the COL2 pin to input
    pinMode(COL3, INPUT); // set the COL3 pin to input
    pinMode(COL4, INPUT); // set the COL4 pin to input
}

void loop() // define the loop function, which runs repeatedly
{
    switch (getCol()) { // switch statement to check which column is pressed
        case COL1: { // if COL1 is pressed
                       Serial.println(getInputChar(COL1, getRow())); // print the character that is pressed (passing the column and the result of getRow() function)
                       delay(1000); // wait for 1 second
                       break; // break the switch statement
                   }
        case COL2: { // if COL2 is pressed
                       Serial.println(getInputChar(COL2, getRow())); // print the character that is pressed (passing the column and the result of getRow() function)
                       delay(1000); // wait for 1 second
                       break; // break the switch statement
                   }
        case COL3: { // if COL3 is pressed
                       Serial.println(getInputChar(COL3, getRow())); // print the character that is pressed (passing the column and the result of getRow() function)
                       delay(1000); // wait for 1 second
                       break; // break the switch statement
                   }
        case COL4: { // if COL4 is pressed
                       Serial.println(getInputChar(COL4, getRow())); // print the character that is pressed (passing the column and the result of getRow() function)
                       delay(1000); // wait for 1 second
                       break; // break the switch statement
                   }
    }
}

int getCol() { // function to get the column
    if (digitalRead(COL1) == 0) return COL1; // if COL1 is pressed, return COL1
    if (digitalRead(COL2) == 0) return COL2; // if COL2 is pressed, return COL2
    if (digitalRead(COL3) == 0) return COL3; // if COL3 is pressed, return COL3
    if (digitalRead(COL4) == 0) return COL4; // if COL4 is pressed, return COL4
}

int getRow() { // function to get the row
    char rows[4] = { ROW1, ROW2, ROW3, ROW4 }; // define an array of the rows
    char row = -1; // define the row variable and set it to -1
    for (char i = 0; i < 4; i++) { // for loop to iterate through the rows
        pinMode(rows[i], INPUT); // set the current row to input
        row = digitalRead(rows[i]); // read the current row
        pinMode(rows[i], OUTPUT); // set the current row to output
        if (row == 1) return rows[i]; // if the current row is pressed, return the current row
    }
    return 0; // if no row is pressed, return 0
}

char getInputChar(int col, int row) { // function to get the character that is pressed from the array
    int c; // define the c variable for the column
    int r; // define the r variable for the row

    c = map(col, COL1, COL4, 0, 3); // map the column to the array
    r = map(row, ROW1, ROW4, 0, 3); // map the row to the array

    return keys[r][c]; // return the character that is pressed
}

