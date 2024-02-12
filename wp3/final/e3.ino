
// defines setuo function which runs once when program start
void setup()
{
  // initialises the serial communication at 9600 bits per second
  Serial.begin(9600); 
}

// defines loop function which runs continuously
void loop()
{  
  const int tmpRead = analogRead(A0); // reads the value from the temperature sensor
  const int tmpVol = map(tmpRead, 0, 1023, 0, 5000); // converts the value to voltage
  const int tmp = (tmpVol - 500) / 10; // converts the voltage to temperature in Celsius

  Serial.println(tmp); // prints the temperature to the serial monitor

  delay(500); // delays for 0.5 seconds
}