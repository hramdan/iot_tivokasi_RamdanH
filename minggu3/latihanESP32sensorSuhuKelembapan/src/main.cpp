#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 33     
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    lcd.init();         
    lcd.backlight();
    lcd.setCursor (0,0);
  lcd.print("Iniliasisasi");
  
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pengukur Suhu");
  lcd.setCursor (0,1);
  lcd.print ("kelembapan");
  delay(3000);
  dht.begin();
}

void loop() {

  delay(500);

  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);

lcd.setCursor(0,0);
lcd.print( "suhu      :");
lcd.print (c);

lcd.setCursor(0,1);
lcd.print ("kelembapan:");
lcd.print (h);
}
