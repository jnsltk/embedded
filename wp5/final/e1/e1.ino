// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 5
// Exercise 1
// Submission code: 662248

#define RED_LED 4 // defines pin for red LED
#define YELLOW_LED 3 // defines pin for yellow LED
#define SWITCH 2 // defines pin for switch

bool y_led_on = false; // flag to keep track of yellow LED state

void isr(); // declares function for interrupt service routine

// defines setup function
void setup() {
    pinMode(RED_LED, OUTPUT); // sets red LED pin as output
    pinMode(YELLOW_LED, OUTPUT); // sets yellow LED pin as output
    pinMode(SWITCH, INPUT); // sets switch pin as input

    attachInterrupt(digitalPinToInterrupt(SWITCH), isr, CHANGE); // attaches interrupt to switch pin
}

// defines loop function
void loop() {
    digitalWrite(RED_LED, HIGH);  // turns on red LED
    delay(1000); // delays for 1 second
    digitalWrite(RED_LED, LOW); // turns off red LED
    delay(1000); // delays for 1 second
}

// defines interrupt service routine
void isr() {
    if (y_led_on) { // if yellow LED is on
        digitalWrite(YELLOW_LED, LOW); // turns off yellow LED
        y_led_on = false; // updates flag
    } else { // if yellow LED is off
        digitalWrite(YELLOW_LED, HIGH); // turns on yellow LED
        y_led_on = true; // updates flag
    }
}
