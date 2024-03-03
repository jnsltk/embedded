/* ----------------------------- Include section ---------------------------- */
#include <Smartcar.h>

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

    for(byte i = 0; i < 4; i++)
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
        annoying();
    } else {
        sound(dist);   // start a tone from the speaker shall indicate how close an object is
        light(dist);   // light up LEDs to indicate how close an object is to the vehicle
    }

    delay(50);   // delay for 50ms
}

// This function gets the distance between the car and the obstacle
int getDistance() {
    return front.getDistance();
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
    long i, vol = map(dist, 20, 150, 4, 0);

    for (i = 0; i < vol; i++)   // loop until the led index which should be on
        digitalWrite(leds[i], HIGH);   // turn on the leds

    for (; i < 4; i++)                // loop from the led index which should be off
        digitalWrite(leds[i], LOW);   // turn off the leds
}

void annoying() {
  for(byte i = 0; i < 4; i++)
    digitalWrite(leds[i], HIGH);

  analogWrite(BUZZER, vol);
  delay(200);

  for(byte i = 0; i < 4; i++)
    digitalWrite(leds[i], LOW);

  analogWrite(BUZZER, 0);
  delay(200);
}