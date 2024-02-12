
void setup()
{
  Serial.begin(9600);
}

void loop()
{  
  const int tmpRead = analogRead(A0);
  const int tmpVol = map(tmpRead, 0, 1023, 0, 5000);
  const int tmp = (tmpVol - 500) / 10;

  Serial.println(tmp);

  delay(500);
}