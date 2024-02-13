// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 023513

/* ------------------------------ Define macros ----------------------------- */
#define TEMP         A0
#define LIGHT_SENSOR A1
#define YELLOWLED    2
#define REDLED       3
#define GREENLED     4

// defines setuo function which runs once when program start
void setup() {
    pinMode(GREENLED, OUTPUT);    // configure the green LED
    pinMode(YELLOWLED, OUTPUT);   // configure the yellow LED
    pinMode(REDLED, OUTPUT);      // configure the red LED
    Serial.begin(9600);           // initialize the serial communication
}

// defines loop function which runs continuously
void loop() {
    double tempValue = analogRead(TEMP);   // retrieve the value from temperature sensor
    // map the read in values to the actual temperature values in farenheight
    double temperature = map(tempValue, 20, 358, -40, 125);
    // retrieve the value of the light sensor
    double lightValue = analogRead(LIGHT_SENSOR);
    // map the read in values in percentage
    double lightIntensity = map(lightValue, 0, 13, 0, 100);
    // light up the LED
    indicate_led(temperature, lightIntensity);

    Serial.print("Temp:");
    Serial.print(temperature);
    Serial.print("C\t");
    Serial.print("Light:");
    Serial.print(lightIntensity);
    Serial.println("%");
    delay(1000);   // Wait for 1000 millisecond(s)
}

// This function compare the values of the temperature sensor and light sensor, and light up the LED
void indicate_led(double temperature, double lightIntensity) {
    // indicate the normal dependency
    if ((temperature < -12 && lightIntensity == 0) ||
        (temperature >= -12 && temperature <= 0 && lightIntensity >= 1 && lightIntensity <= 20) ||
        (temperature >= 0 && temperature <= 20 && lightIntensity >= 21 && lightIntensity <= 60) ||
        (temperature >= 21 && lightIntensity >= 61 && lightIntensity <= 100)) {
        digitalWrite(GREENLED, HIGH);   // turn on green
        digitalWrite(YELLOWLED, LOW);   // turn off yellow
        digitalWrite(REDLED, LOW);      // turn off red
    }                                   // deviation when the temperature is higher
    else if ((temperature >= -12 && lightIntensity == 0) ||
             (temperature > 0 && lightIntensity >= 1 && lightIntensity <= 20) ||
             (temperature > 20 && lightIntensity >= 21 && lightIntensity <= 60)) {
        digitalWrite(REDLED, HIGH);     // turn on red
        digitalWrite(YELLOWLED, LOW);   // turn off yellow
        digitalWrite(GREENLED, LOW);    // turn off green
    }   //  deviation when the temperature is lower than it should be
    else if ((temperature < -12 && temperature <= 0 && lightIntensity >= 1 &&
              lightIntensity <= 20) ||
             (temperature < 0 && lightIntensity >= 21 && lightIntensity <= 60) ||
             (temperature < 21 && lightIntensity <= 100)) {
        digitalWrite(YELLOWLED, HIGH);   // turn on yellow
        digitalWrite(REDLED, LOW);       // turn off red
        digitalWrite(GREENLED, LOW);     // turn off green
    }
}