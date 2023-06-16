#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define resistencia  A0
int val = 0;
int Vin = 5.83;
float voltajee = 0;
float R2 = 10000;
float R1 = 0;
float resistenciah = 0;

LiquidCrystal_I2C lcd_ni(0x27,16,2);
void setup()
{
Serial.begin(9600);
lcd_ni.init();
lcd_ni.backlight(); 
}

void loop()
{
val = analogRead(resistencia);
  if(val){
    resistenciah = val * Vin;
    voltajee = (resistenciah)/1000.0;
    resistenciah = (Vin/voltajee) - 1;
    R1= R2 * resistenciah;
    lcd_ni.setCursor(0,1),
    lcd_ni.print("Voltage s: ");
    lcd_ni.setCursor(10,1);
    lcd_ni.print(voltajee);
    lcd_ni.print("v");
    lcd_ni.setCursor(0,0);
    lcd_ni.print("R1: ");
    lcd_ni.setCursor(3,0);
    lcd_ni.print(R1);
    lcd_ni.print(" OHMS");
    delay(1000);
} 
}
