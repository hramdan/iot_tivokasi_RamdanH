#include <Arduino.h>  // Wajib untuk PlatformIO + ESP32
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C 0x27 dan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Deklarasi pin LED
int lampu = 32;
int lampu2 = 25;
int lampu3 = 14;
int lampu4 = 19;
int lampu5 = 18;
 

void setup() {
    lcd.init();         
    lcd.backlight(); 
    pinMode(lampu, OUTPUT);
    pinMode(lampu2, OUTPUT);
    pinMode(lampu3, OUTPUT);
    pinMode(lampu4, OUTPUT);
    pinMode(lampu5, OUTPUT);
}

void countdown(int seconds, const char* status) {
    for (int i = seconds; i > 0; i--) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(status);
        lcd.setCursor(0, 1);
        lcd.print(i);
        delay(1000);
    }
}

void loop() {
   
    digitalWrite(lampu, HIGH);
    digitalWrite(lampu2, LOW);
    digitalWrite(lampu3, LOW);
    digitalWrite(lampu4, LOW);
    digitalWrite(lampu5, HIGH);
    countdown(60, "Merah - Stop");

    digitalWrite(lampu, LOW);
    digitalWrite(lampu2, HIGH);
    digitalWrite(lampu3, LOW);
    digitalWrite(lampu4, LOW);
    digitalWrite(lampu5, LOW);
    countdown(3, "Kuning - Siap");

   
    digitalWrite(lampu, LOW);
    digitalWrite(lampu2, LOW);
    digitalWrite(lampu3, HIGH);
     digitalWrite(lampu4, HIGH);
    digitalWrite(lampu5, LOW);
    countdown(60, "Hijau - Jalan");
}