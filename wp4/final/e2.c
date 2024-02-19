#include <Servo.h>   // includes servo library

#define SEC_IN_MILL 1000   // defines amount of milliseconds in a second (used for testing)

volatile bool flag = false;   // defines the flag modified in the ISR
unsigned long oldTime = 0;    // defines the old measured time

Servo servoS, servoM;   // defines the servo objects

// defines setup function which runs once
void setup() {
    servoS.attach(2, 500, 2500);   // attaches the seconds servo to pin 2
    servoM.attach(3, 500, 2500);   // attaches the minutes servo to pin 3
    delay(1100);                   // waits for the servos to initialize

    servoS.write(0);   // sets the seconds servo to 0 degrees
    servoM.write(0);   // sets the minutes servo to 0 degrees
    delay(1000);       // waits for the servos to finish moving

    cli();                             // disables interrupts to avoid trouble
    TCCR2A = TCCR2B = TCNT2 = 0;       // resets settings for timer2
    OCR2A = 255;                       // sets the compare interval to as slow as possible
    TCCR2A |= (1 << WGM21);            // sets to CTC mode
    TCCR2B = (TCCR2B & 0xF8) | 0x07;   // sets prescaler to 1024
    TIMSK2 |= (1 << OCIE2A);           // sets the interrupt on compare match
    sei();                             // enables interrupts

    Serial.begin(9600);   // begins serial communication
}

// defines loop function which runs repeatedly
void loop() {
    static byte s = 0, m = 0;   // defines the seconds and minutes variables

    if (!flag)      // if interrupt did not trigger
        return;     // skips the rest of the function
    flag = false;   // resets the flag

    if (s == 59) {             // if has been a minute
        m = (m + 1) % 60;      // increments the minutes
        servoM.write(m * 3);   // sets the minutes servo to the next position
    }

    s = (s + 1) % 60;   // increments the seconds

    servoS.write(s * 3);   // sets the seconds servo to the next position
    printTime(m, s);       // prints the time

    delay(10);   // waits 10ms for performance
}

// defines function to print the time
void printTime(byte m, byte s) {
    char time[6] = {'0', '0', ':', '0', '0', '\0'};   // defines the time string

    time[0] = (m / 10) + '0';   // sets the tens of minutes
    time[1] = (m % 10) + '0';   // sets the ones of minutes
    time[3] = (s / 10) + '0';   // sets the tens of seconds
    time[4] = (s % 10) + '0';   // sets the ones of seconds

    Serial.println(time);   // prints the time
}

// defines the interrupt service routine for timer2
ISR(TIMER2_COMPA_vect) {
    if (millis() - oldTime >= SEC_IN_MILL) {   // if has been a second
        oldTime = millis();                    // saves the new time
        flag = true;                           // sets the flag to true
    }
}