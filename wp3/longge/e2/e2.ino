const int periodicity = 1;
const int blueLed = 2;
const int greenLed = 3;
const int redLed = 4;

int sensorValue = 0;
int lightIntensity = 0;
int celsius = 0;

void setup()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    Serial.begin(9600);

    pinMode(blueLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
}

void loop()
{
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);

    celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    sensorValue = analogRead(A1);
    lightIntensity = map(sensorValue, 11, 816, 0, 100);
    Serial.println(lightIntensity);

    if (lightIntensity == 0) {
        if (celsius < -12) {
            digitalWrite(greenLed, HIGH);
        } else {
            digitalWrite(redLed, HIGH);
        }
    } else if (lightIntensity > 0 && lightIntensity < 21) {
        if (celsius < -12) {
            digitalWrite(blueLed, HIGH);
        } if (celsius >= -12 && celsius <= 0) {
            digitalWrite(greenLed, HIGH);
        } else {
            digitalWrite(redLed, HIGH);
        }
    } else if (lightIntensity > 22 && lightIntensity < 61) {
        if (celsius < 0) {
            digitalWrite(blueLed, HIGH);
        } if (celsius >= 0 && celsius <= 20) {
            digitalWrite(greenLed, HIGH);
        } else {
            digitalWrite(redLed, HIGH);
        }
    } else {
        if (celsius > 20) {
            digitalWrite(greenLed, HIGH);
        } else {
            digitalWrite(blueLed, HIGH);
        }
    }

    delay(periodicity * 1000);
}
