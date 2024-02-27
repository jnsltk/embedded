#define RED_LED 4
#define YELLOW_LED 3
#define SWITCH 2

bool y_led_on = false;

void isr();

void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(SWITCH, INPUT);

    attachInterrupt(digitalPinToInterrupt(SWITCH), isr, CHANGE);
}

void loop() {
    digitalWrite(RED_LED, HIGH);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    delay(1000);
}

void isr() {
    if (y_led_on) {
        digitalWrite(YELLOW_LED, LOW);
        y_led_on = false;
    } else {
        digitalWrite(YELLOW_LED, HIGH);
        y_led_on = true;
    }
}
