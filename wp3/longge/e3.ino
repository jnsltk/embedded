#define DELAY 500
#define TEMP_PIN A0

int t = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    t = map(((analogRead(TEMP_PIN) - 20) * 3.04), 0, 1023, -40, 125);
    Serial.println(t);

    delay(DELAY);
}
