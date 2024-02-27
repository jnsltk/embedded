// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 3
// Submission code: 662248

/* ------------------------------ Define macros ----------------------------- */
#include "dht_nonblocking.h" // include DHT library for temp sensor
#define DHT_SENSOR_TYPE DHT_TYPE_11 // Define dht sensor type
static const int DHT_SENSOR_PIN = 7; // Define temp sensor pin
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE ); // Create dht_sensor object from library
#define LIGHT_SENSOR A0   // defines light sensor pin

#define YELLOWLED    4    // defines yellow led pin
#define GREENLED     5    // dewfdines green led pin
#define REDLED       6    // defines red led pin

// Define temperature ranges
#define TEMP_1 -12 // -12
#define TEMP_2 0 // 0
#define TEMP_3 1 // 1
#define TEMP_4 20 // 20
#define TEMP_5 21 // 21
#define TEMP_6 60 // 60
#define TEMP_7 61 // 61
#define TEMP_8 100 // 100

// defines setuo function which runs once when program start
void setup() {
  pinMode(GREENLED, OUTPUT);    // configure the green LED
  pinMode(YELLOWLED, OUTPUT);   // configure the yellow LED
  pinMode(REDLED, OUTPUT);      // configure the red LED
  Serial.begin(9600); // Initialize serial connection
}

// defines loop function which runs continuously
void loop() {
    float temperature, humidity; // define variables for temperature and humidity
    dht_sensor.measure( &temperature, &humidity ); // measure temperature and humidity

    // retrieve the value of the light sensor
    double lightValue = analogRead(LIGHT_SENSOR);
    // map the read in values in percentage
    double lightIntensity = map(lightValue, 1023, 0, 0, 100);
    // light up the LED
    indicate_led(temperature, lightIntensity);

    Serial.print("Temp:");
    Serial.println(String((int)temperature)+ "°C" );
    Serial.print("Light:");
    Serial.print(lightIntensity);
    Serial.println("%");
    delay(1000);   // Wait for 1000 millisecond(s)
}

// This function compare the values of the temperature sensor and light sensor, and light up the LED
void indicate_led(double temperature, double lightIntensity) {
    // indicate the normal dependency
    if ((temperature < TEMP_1 && lightIntensity == TEMP_2) ||
        (temperature >= TEMP_1 && temperature <= TEMP_2 && lightIntensity >= TEMP_3 && lightIntensity <= TEMP_4) ||
        (temperature >= TEMP_2 && temperature <= TEMP_4 && lightIntensity >= TEMP_5 && lightIntensity <= TEMP_6) ||
        (temperature >= TEMP_5 && lightIntensity >= TEMP_7 && lightIntensity <= TEMP_8)) {
        digitalWrite(GREENLED, HIGH);   // turn on green
        digitalWrite(YELLOWLED, LOW);   // turn off yellow
        digitalWrite(REDLED, LOW);      // turn off red
    }                                   // deviation when the temperature is higher
    else if ((temperature >= TEMP_1 && lightIntensity == TEMP_2) ||
             (temperature > TEMP_2 && lightIntensity >= TEMP_3 && lightIntensity <= TEMP_4) ||
             (temperature > TEMP_4 && lightIntensity >= TEMP_5 && lightIntensity <= TEMP_6)) {
        digitalWrite(REDLED, HIGH);     // turn on red
        digitalWrite(YELLOWLED, LOW);   // turn off yellow
        digitalWrite(GREENLED, LOW);    // turn off green
    }   //  deviation when the temperature is lower than it should be
    else if ((temperature < TEMP_1 && temperature <= TEMP_2 && lightIntensity >= TEMP_3 &&
              lightIntensity <= TEMP_4) ||
             (temperature < TEMP_2 && lightIntensity >= TEMP_5 && lightIntensity <= TEMP_6) ||
             (temperature < TEMP_5 && lightIntensity <= TEMP_8)) {
        digitalWrite(YELLOWLED, HIGH);   // turn on yellow
        digitalWrite(REDLED, LOW);       // turn off red
        digitalWrite(GREENLED, LOW);     // turn off green
    }
}
