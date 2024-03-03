#include <Smartcar.h>
const int GYROSCOPE_OFFSET = 37;

const int TRIGGER_PIN = 5; //D6

const int ECHO_PIN = 18; //D7

const int BUZZER = 19;

const int leds[] = {
    2,4,23,32
};

const unsigned int MAX_DISTANCE = 200;

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);
GY50 gyroscope(arduinoRuntime, GYROSCOPE_OFFSET);
HeadingCar car(control, gyroscope);

int carSpeed = 30;

SR04 front(arduinoRuntime, TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(32, OUTPUT);
}

void loop() {
  int dist = getDistance();
  if (dist < 150) {
    car.setSpeed(-(map(dist, 20, 150, 10, carSpeed)));
  }
  
  if (dist < 20) {
    car.setSpeed(0);
  }

  sound(dist);
  light(dist);

  delay(50);
}    

int getDistance() { return front.getDistance(); }

void sound(int dist) {
  long vol = map(dist, 20, 150, 255, 0);
  if (vol <= 0) {
    analogWrite(BUZZER, 0);
  } else  {
    analogWrite(BUZZER, vol);
  }
}

void light(int dist) {
  long i, vol = map(dist, 20, 150, 4, 0);
  for(i = 0; i < vol; i++)
    digitalWrite(leds[i], HIGH);

  for(; i < 4; i++)
    digitalWrite(leds[i], LOW);

}