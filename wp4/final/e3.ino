// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 4
// Exercise 3
// Submission code: 892561

/* ----------------------------- Include section ---------------------------- */

#include <Adafruit_NeoPixel.h> // include the Adafruit Neopixel library

/* ----------------------------- Define section ----------------------------- */

#define TEMP_SENSOR    A0            // define the pin of the temperature sensor
#define NEO_PIN        6             // define the pin of the Neopixels ring
#define NUMPIXELS      12            // define the number of pixels of the Neopixels ring
#define RED_LED_BUZZER 2             // define the pin of the red led and the buzzer
#define RING_COL       (0, 0, 255)   // define the color

/* -------------------------- Main program section -------------------------- */

// define an NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

// define the setup function which runs once
void setup() {
    pinMode(RED_LED_BUZZER, OUTPUT);   // configure RED_LED_BUZZER as OUTPUT
    pixels.begin();                    // initialize the Neopixel pixels object
    pixels.show();                     // turn off all pixels
    Serial.begin(9600);                // start the serial communication
}

// define the loop function which runs repeatedly
void loop() {
    readTemp();    // read the temperature periodically
    delay(1000);   // Wait for 1000 millisecond(s)
}

// This function reads the temperature periiodically
void readTemp() {
    double value = analogRead(TEMP_SENSOR);     // retrieve the value from the temperature sensor
    int temp = map(value, 20, 358, -40, 125);   // map the retrieved value to the farenheit degree
    Serial.println(temp);                       // print out the temperature in the serial monitor
    lightLeds(temp);                     // light up the number of leds based on the temperature
    digitalWrite(RED_LED_BUZZER, LOW);   // turn off the red led
    if (temp == 125) {                   // when the temperature reaches highest - 125°c
        digitalWrite(RED_LED_BUZZER, HIGH);   // turn on the red led
    }
}

// This function lights up the number of leds based on the temperature
void lightLeds(int temp) {
    // store the temperature thresholds in an array
    int thresholds[] = {-40, -25, -10, 5, 20, 35, 50, 65, 80, 95, 110, 124, 125};
    // calculate the number of leds needed for the thresholds
    int numLeds = sizeof(thresholds) / sizeof(thresholds[0]) + 1;

    int ledOn = 0;   // define the number of led to be turned on
    // loop through the number of leds
    for (int i = 0; i < numLeds; i++) {
        if (temp <=
            thresholds[i]) {      // check if the temperature reaches certain threshold in the array
            turnOffLeds(ledOn);   // turn off unnecessary leds
            turnOnLeds(ledOn);    // turn on the right number of leds
            break;                // break out the loop
        }
        ledOn++;   // increment the number of turned-on led by 1
    }
}

// This function turns off leds
void turnOffLeds(int startIndex) {
    // loop through the leds which are needed to be turned off
    for (int i = startIndex; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 0);   // set the led no color
        pixels.show();                // update the status
    }
}

// This function turns on leds
void turnOnLeds(int ledNum) {
    // loop through the leds which are needed to be turned on
    for (int i = 0; i < ledNum; i++) {
        pixels.setPixelColor(i, RING_COL);   // set the led with colors
        pixels.show();                       // update the status
    }
}