// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 4
// Exercise 1
// Submission code: 892561

// Enum with interval in milliseconds
enum Interval {
    I64 = (1 << CS11) | (1 << CS10),    // 64ms
    I256 = 1 << CS12,                   // 256ms
    I1024 = (1 << CS12) | (1 << CS10)   // 1024ms
};

#define LED_AMT      5                       // defines the amount of leds
#define LED_TMP_CONV (LED_AMT - 1) / 328.0   // defines conversion number for temperature

byte leds[] = {6, 5, 4, 3, 2};   // defines the led pins

short tmps[] = {-40, -20, 0, 20, 40};   // defines the temperature thresholds

const enum Interval interval = I64;   // defines which interval to use
volatile bool flag = false;           // defines the flag modified in the ISR

// defines setup function which runs once
void setup() {
    TCCR1A = TCCR1B = TCNT1 = 0;   // resets settings for timer1
    OCR1A = 15999;                 // sets the compare value to 1ms
    TCCR1B |= (1 << WGM12);        // sets to CTC mode
    TCCR1B |= interval;            // sets chosen prescaler
    TIMSK1 |= (1 << OCIE1A);       // sets the interrupt on compare match

    for (byte i = 0; i < LED_AMT; i++)   // loops through the leds
        pinMode(leds[i], OUTPUT);        // sets the led pins to output

    Serial.begin(9600);   // starts the serial communication
}

// defines loop function which runs repeatedly
void loop() {
    if (flag) {      // if interrupt ran
        readTmp();   // reads the temperature and sets the leds

        flag = false;   // resets the flag
    }

    delay(10);   // waits 10ms for performance
}

// defines the interrupt service routine for timer1
ISR(TIMER1_COMPA_vect) {
    flag = true;   // sets the flag to true
}

// defines function to read the temperature and set the leds
void readTmp() {
    const short tmp = map(analogRead(A5), 0, 1023, 0, 5000);   // reads the temperature voltage
    const short celcius = (tmp - 500) / 10;                    // converts the voltage to celcius
    byte i;                                                    // defines index variable

    // loops through the temperature thresholds
    for (i = 0; (i < LED_AMT) && (celcius > tmps[i]); i++)
        digitalWrite(leds[i], HIGH);   // turns on led

    for (i++; i < LED_AMT; i++)       // loops through the rest of the leds
        digitalWrite(leds[i], LOW);   // turns off led
}
