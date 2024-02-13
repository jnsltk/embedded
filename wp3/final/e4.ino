// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 023513

#include <Keypad.h>   // include the library

#define ROWS 4   // define ROWS as 4
#define COLS 4   // define COLS as 4

// use an array to store key values on the keypad
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {11, 10, 9, 8};   // connect to Arduino pins
byte colPins[COLS] = {7, 6, 5, 4};     // connect to Arduino pins

// create a keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// defines setuo function which runs once when program start
void setup() {
    Serial.begin(9600);   // initialize the serial communication
}

// defines loop function which runs continuously
void loop() {
    char pressedKey = readKey();   // store the pressed key value in a variable
    if (pressedKey != 0) {         // check whether a key got pressed
        // Print the pressed key value
        Serial.println(pressedKey);
        // delay(100);   // Wait for 1000 millisecond(s)
    }
}

// This function checks if a key being pressed, and return the key value
char readKey() {
    char pressedKey = keypad.getKey();   // get the pressed key value
    if (pressedKey) {                    // check if a key is pressed
        return pressedKey;               // if yes, return the key
    }
    return 0;   // otherwise return 0
}