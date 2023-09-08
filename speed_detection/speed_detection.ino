#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int sensor = 2;
unsigned long start_time;
unsigned long speed_time;
unsigned long output_time;
float speed_time_sec;
int count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(sensor, INPUT_PULLUP);
  lcd.setCursor(0,0);
  lcd.print("Movement");
  lcd.setCursor(0,1);
  lcd.print("Ready");
}

void loop() {
  int output_sensor = digitalRead(sensor);
  if(output_sensor == 1){
    start_time = millis();
    while(output_sensor == 1){
      output_sensor = digitalRead(sensor);
      count = 1;
    }
    if(count == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Movement");
      speed_time = millis() - start_time;
      speed_time_sec = speed_time/1000;
      lcd.setCursor(0,1);
      lcd.print(speed_time);
      lcd.print(" ms");
      Serial.print("Waktu kecepatan gerak: ");
      Serial.print(speed_time);
      Serial.println(" ms"); 
      stop(); 
    }
  }
  count = 0;
  delay(100);
}

void stop() {
  while(true){
    
  }
}
