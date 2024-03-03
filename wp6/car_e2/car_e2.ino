#include <Smartcar.h>

const int carSpeed         = 30; // 30% of the max speed
const int GYROSCOPE_OFFSET = 37;

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

GY50 gyroscope(arduinoRuntime, GYROSCOPE_OFFSET);

HeadingCar car(control, gyroscope);

void turn(int speed)
{
    int targetDegrees = 180;
    speed = smartcarlib::utils::getAbsolute(speed); // make sure speed is positive
    car.overrideMotorSpeed(speed,
            -1); // left motors spin forward, right motors spin backward

    const auto initialHeading = car.getHeading(); // the initial heading we'll use as offset to
                                                  // calculate the absolute displacement
    int degreesTurnedSoFar
        = 0; // this variable will hold the absolute displacement from the beginning of the rotation
    while (abs(degreesTurnedSoFar) < abs(targetDegrees))
    { // while absolute displacement hasn't reached the (absolute) target, keep turning
        car.update(); // update to integrate the latest heading sensor readings
        auto currentHeading = car.getHeading(); // in the scale of 0 to 360
        if (currentHeading < initialHeading)
        { // if we are turning right and the heading is smaller than the
            // initial one (e.g. started at 350 degrees and now we are at 20), so to get a signed
            // displacement (+30)
            currentHeading += 360;
        }
        degreesTurnedSoFar
            = initialHeading - currentHeading; // degrees turned so far is initial heading minus
                                               // current (initial heading
        // is at least 0 and at most 360. To handle the "edge" cases we substracted or added 360 to
        // currentHeading)
    }
    car.setSpeed(0); // we have reached the target, so stop the car
}

void setup() {}

void loop() {
  turn(carSpeed); // rotate clockwise 90 degrees on spot

  car.setSpeed(carSpeed);
  delay(1500);
  car.setSpeed(0);

  turn(carSpeed);

  car.setSpeed(carSpeed);
  delay(1500);
  car.setSpeed(0);
}
