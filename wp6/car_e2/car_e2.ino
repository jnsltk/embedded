// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 6
// Exercise 2
// Submission code: 61L1GA

/*
The setup function does nothing, all setup is in the constructors of the different classes which comes with the Smartcar.h library.
It sets up the left and right motors, differential control, gyroscope and the car object.
The loop turns the car 180 degrees, then goes forward for 1.5 seconds, then stops the car. 
It will repeat to make an oval shape as a result.
The turn function takes a speed parameter, sets the left motors to the speed, the other motors to -1 speed, ensuring that those wheels will be 
locked, enabling it to turn. It uses to car.getHeading() function which uses the gyroscope, to know when it has turned 180 degrees.
When it has turned 180 degrees, it will stop, so it is ready to start driving straight.
*/

#include <Smartcar.h> // include the Smartcar library

const int carSpeed         = 30; // 30% of the max speed
const int GYROSCOPE_OFFSET = 37; // the offset of the gyroscope

ArduinoRuntime arduinoRuntime; // create an instance of the ArduinoRuntime
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins); // create an instance of the left motor
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins); // create an instance of the right motor
DifferentialControl control(leftMotor, rightMotor); // create an instance of the DifferentialControl

GY50 gyroscope(arduinoRuntime, GYROSCOPE_OFFSET); // create an instance of the gyroscope

HeadingCar car(control, gyroscope); // create an instance of the HeadingCar

// function to turn the car 180 degrees
void turn(int speed)
{
    int targetDegrees = 180; // the target displacement in degrees
    speed = smartcarlib::utils::getAbsolute(speed); // make sure speed is positive
    car.overrideMotorSpeed(speed, -1); // left motor goes forward, right motor stays locked

    const auto initialHeading = car.getHeading(); // get the initial heading
                                                  
    int degreesTurnedSoFar = 0; // the degrees turned so far
    while (abs(degreesTurnedSoFar) < abs(targetDegrees)) // while we haven't reached the target
    { 
        car.update(); // update the car's state
        auto currentHeading = car.getHeading(); // get the current heading
        if (currentHeading < initialHeading) // if the current heading is less than the initial heading
        { 
            currentHeading += 360; // add 360 to the current heading
        }
        degreesTurnedSoFar = initialHeading - currentHeading; // calculate the degrees turned so far
    }
    car.setSpeed(0); // we have reached the target, so stop the car
}

// runs once at the start
void setup() {}

// runs in a loop over and over again
void loop() {
  turn(carSpeed); // turn the car 180 degrees

  car.setSpeed(carSpeed); // set the car's speed to go forward
  delay(1500); // go forward for 1.5 seconds
  car.setSpeed(0); // stop the car
}
