#include <dht.h>
// Define the pins for the LEDs and the temperature sensor
#define LED1_PIN 7
#define LED2_PIN 6
#define LED3_PIN 5
#define LED4_PIN 4
#define LED5_PIN 3
#define TEMP_PIN 2

// Define temperatures where the LEDs will turn on
#define 1_LED_TEMP 0
#define 2_LED_TEMP 10
#define 3_LED_TEMP 20
#define 4_LED_TEMP 30
#define 5_LED_TEMP 40

dht DHT;

void setup() {
    // Set the LED pins as outputs
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
    pinMode(LED4_PIN, OUTPUT);
    pinMode(LED5_PIN, OUTPUT);

    // Set the temperature sensor pin as input
    pinMode(TEMP_PIN, INPUT);

    Serial.begin(9600);
}

void loop() {
    int chk = DHT.read11(TEMP_PIN);

    Serial.println(DHT.temperature);
    delay(1000);
}

void isr() {
    
}
