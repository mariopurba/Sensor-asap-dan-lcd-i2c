#include <MQ2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

int pinSensor = A0;
int asap, lpg, co;

MQ2 mq2(pinSensor);

void setup() {
  lcd.begin(0x27,20,4);
  mq2.begin();
  lcd.backlight();
}
void loop() {
  float* values = mq2.read(true);
  asap = mq2.readSmoke();
  lpg = mq2.readLPG();
  co = mq2.readCO();

  lcd.setCursor(0, 0);
  lcd.print("Asap: ");
  lcd.print(asap);
  lcd.print(" PPM");
  lcd.print(" LPQ: ");
  lcd.print(lpg);
  lcd.setCursor(0, 1);
  lcd.print("CO: ");
  lcd.print(co);
  delay(1000);
}
