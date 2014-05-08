/*
Adafruit Arduino - Lesson 10. Pseudo Thermin
*/
 
int speakerPin = 3;
int photocellPin = 0;
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  int reading = analogRead(photocellPin);
  int pitch = 200 + reading / 4;
  Serial.println(reading);
  tone(speakerPin, pitch);
}
