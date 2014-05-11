#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 200

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int sensorPin = 0;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.begin (16,2); //  <<----- My LCD was 16x2
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
}

void loop() {
 unsigned int cm = DistanceSensor.ping_cm();
 Serial.print("Distance: ");
 Serial.print(cm);
 Serial.println("cm");
 lcd.clear();
 lcd.home();
 lcd.print("Dystans:");
 lcd.setCursor(0,1);
 lcd.print(cm);
 lcd.print("cm");
 delay(1000);
}
