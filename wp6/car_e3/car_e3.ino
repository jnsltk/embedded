/* ----------------------------- Include section ---------------------------- */
#include <Smartcar.h> // include the Smartcar library

/* ----------------------------- Define section ----------------------------- */
const int GYROSCOPE_OFFSET = 37;   // define offset 37

const int TRIGGER_PIN = 5;   // define trigger pin

const int ECHO_PIN = 18;   // define echo pin

const int BUZZER = 19;   // define buzzer pin

// define pins for leds
const int leds[] = {2, 4, 23, 32};

const unsigned int MAX_DISTANCE = 200;   // define the MAX_DISTANCE

ArduinoRuntime arduinoRuntime;   // declare an objdect of ArduinoRuntime
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);   // define leftMotor
BrushedMotor rightMotor(arduinoRuntime,
                        smartcarlib::pins::v2::rightMotorPins);   // define rightMotor
DifferentialControl control(leftMotor, rightMotor);               // define control for motors
GY50 gyroscope(arduinoRuntime, GYROSCOPE_OFFSET);                 // define gyroscope
HeadingCar car(control, gyroscope);                               // define the object car

int carSpeed = 30;   // define a variable to store car speed

SR04 front(arduinoRuntime, TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);   // define the ultrasonic sensor

/* -------------------------- Main program sectioin ------------------------- */
// set up the configerations
void setup() {
    pinMode(BUZZER, OUTPUT);   // configure BUZZER as OUTPUT

    for(byte i = 0; i < 4; i++) // loops through LEDs
      pinMode(leds[i], OUTPUT);   // configure leds as OUTPUT
}

// code that run in loop
void loop() {
    int dist = getDistance();   // retrieve the distance from the obstacle
    if (dist < 150) {           // check if the distance less than 150
        car.setSpeed(-(
            map(dist, 20, 150, 10, carSpeed)));   // set the car speed which is gradually decreased
                                                  // based on the distance to the obstacle
    }

    if (dist < 20) {       // check if the distance less than 20
        car.setSpeed(0);   // stop the car
        annoying(); // annoying sound and light
    } else {
        sound(dist);   // start a tone from the speaker shall indicate how close an object is
        light(dist);   // light up LEDs to indicate how close an object is to the vehicle
    }

    delay(50);   // delay for 50ms
}

// This function gets the distance between the car and the obstacle
int getDistance() {
    return front.getDistance(); // return the distance from the obstacle
}

// This function start a tone to indicate how close an object is
void sound(int dist) {
    long vol =
        map(dist, 20, 150, 255, 0);   // get the sound volume based on the distance to the obstacle
    analogWrite(BUZZER, vol);     // sound the buzzer to the corresponding volumm
}

// This function turns on LEDs to indicate how close an object is to the vehicle
void light(int dist) {
    // define an counter variable i and an index variable for leds
    long i, vol = map(dist, 20, 150, 3, 0);

    for (i = 0; i < vol; i++)   // loop until the led index which should be on
        digitalWrite(leds[i], HIGH);   // turn on the leds

    for (; i < 4; i++)                // loop from the led index which should be off
        digitalWrite(leds[i], LOW);   // turn off the leds
}

// This function makes an annoying sound and light for when the car is too close to an obstacle
void annoying() {
  for(byte i = 0; i < 4; i++) // loops through LEDs
    digitalWrite(leds[i], HIGH); // turn on the leds

  analogWrite(BUZZER, 255); // put buzzer to max volume
  delay(200); // delay for 200ms

  for(byte i = 0; i < 4; i++) // loops through LEDs
    digitalWrite(leds[i], LOW); // turn off the leds

  analogWrite(BUZZER, 0); // turn off the buzzer
  delay(200); // delay for 200ms
}