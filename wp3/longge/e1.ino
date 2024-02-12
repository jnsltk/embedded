const int led1 = 2;
const int led2 = 3;
const int button = 4;

int buttonState = 0;
unsigned long timeNow = 0;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(button, INPUT);

    timeNow = millis();

}

void loop()
{
    buttonState = digitalRead(button);

    if (buttonState == HIGH) {
        digitalWrite(led2, HIGH);
    } else {
        digitalWrite(led2, LOW);
    }

    if (timeNow + 1000 == millis()) {
        digitalWrite(led1, HIGH);
    }

    if (timeNow + 2000 == millis()) {
        digitalWrite(led1, LOW);
        timeNow = millis();
    }
}
