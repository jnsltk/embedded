// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 023513

const int led1 = 2;     // define the pin for the LED 1 (pin 2)
const int led2 = 3;     // define the pin for the LED 2 (pin 3)
const int button = 4;   // define the pin for the button (pin 4)

int buttonState = 0;         // define the variable for the button state
unsigned long timeNow = 0;   // define the variable for the time

void setup()   // setup function (runs once)
{
    pinMode(led1, OUTPUT);    // set the LED 1 pin as an output
    pinMode(led2, OUTPUT);    // set the LED 2 pin as an output
    pinMode(button, INPUT);   // set the button pin as an input

    timeNow = millis();   // set the time to the current time
}

void loop()   // loop function (runs over and over again)
{
    buttonState = digitalRead(button);   // read the state of the button

    if (buttonState == HIGH) {      // if the button is pressed
        digitalWrite(led2, HIGH);   // turn on the LED 2
    } else {                        // if the button is not pressed
        digitalWrite(led2, LOW);    // turn off the LED 2
    }

    if (timeNow + 1000 == millis()) {   // if 1 second has passed
        digitalWrite(led1, HIGH);       // turn on the LED 1
    }

    if (timeNow + 2000 == millis()) {   // if 2 seconds have passed
        digitalWrite(led1, LOW);        // turn off the LED 1
        timeNow = millis();             // reset the time
    }
}
