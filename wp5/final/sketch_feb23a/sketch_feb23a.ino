/* ----------------------------- Include section ---------------------------- */
#include "dht_nonblocking.h"

/* ----------------------------- Define section ----------------------------- */
#define DHT_SENSOR_TYPE DHT_TYPE_11                            // define the sensor type
static const int DHT_SENSOR_PIN = 7;                           // define the sensor pin
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);   // configure the sensor

#define LED_1  2    // define the lED_1 pin
#define LED_2  3    // define the lED_2 pin
#define LED_3  4    // define the lED_3 pin
#define LED_4  5    // define the lED_4 pin
#define LED_5  6    // define the lED_5 pin
#define TEMP   A0   // define the temperature sensor pin
#define TEMP_1 22   // define a constant temperature value
#define TEMP_2 24   // define a constant temperature value
#define TEMP_3 26   // define a constant temperature value
#define TEMP_4 28   // define a constant temperature value
#define TEMP_5 30   // define a constant temperature value

// This function sets up the program
void setup() {
    pinMode(LED_1, OUTPUT);   // configure the led
    pinMode(LED_2, OUTPUT);   // configure the led
    pinMode(LED_3, OUTPUT);   // configure the led
    pinMode(LED_4, OUTPUT);   // configure the led
    pinMode(LED_5, OUTPUT);   // configure the led
    Serial.begin(9600);       // create serial communication
    Serial.println("horse");
}

// This function runs in loop
void loop() {
    delay(500);                    // add 500ms delay
    float temperature, humidity;   // declare variables to store temperature and humidity values
    dht_sensor.measure(&temperature, &humidity);   // convert the values
    lightLed((int) temperature);

    Serial.println(String((int) temperature) + "°C");
}

void lightLed(int temp) {
    if (temp < TEMP_2 && temp >= TEMP_1) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, LOW);
        digitalWrite(LED_5, LOW);
    } else if (temp < TEMP_3 && temp >= TEMP_2) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, LOW);
        digitalWrite(LED_5, LOW);
    } else if (temp < TEMP_4 && temp >= TEMP_3) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
        digitalWrite(LED_4, LOW);
        digitalWrite(LED_5, LOW);
    } else if (temp < TEMP_5 && temp >= TEMP_4) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
        digitalWrite(LED_4, HIGH);
        digitalWrite(LED_5, LOW);
    } else if (temp >= TEMP_4) {
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);
        digitalWrite(LED_3, HIGH);
        digitalWrite(LED_4, HIGH);
        digitalWrite(LED_5, HIGH);
    } else {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, LOW);
        digitalWrite(LED_5, LOW);
    }
}