/*
Adafruit Arduino - Lesson 7. RGB Fader
*/
 
int redLEDPin = 11;
int greenLEDPin = 10;
int blueLEDPin = 9;
 
int redSwitchPin = 7;
int greenSwitchPin = 6;
int blueSwitchPin = 5;
 
int red = 255;
int blue = 0;
int green = 0;
 
void setup()
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Hello world!"); 
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);  
  pinMode(redSwitchPin, INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin, INPUT_PULLUP);
}
 
void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red ++;
    if (red > 255) red = 0;
    Serial.println("red");
  }
  if (digitalRead(greenSwitchPin) == LOW)
  {
    green ++;
    if (green > 255) green = 0;
    Serial.println("green");
    Serial.println("Hello world!"); 

  }
  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue ++;
    if (blue > 255) blue = 0;
    Serial.println("blue");
  }
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);  
  delay(10);
}
