#include <SparkFun_ADXL345.h>
#include <SPI.h>
#include <Wire.h>
#include <LedControl.h>

#define entradaaa   12   //pin 12 conectado al pin de datos del max7219.
#define clockoo 11   //pin 11 conectado al pin de clock del max7219.
#define cs  10   //pin 10 conectado al pin de carga del max7219.

LedControl matrizzl = LedControl(entradaaa,clockoo,cs,1);
ADXL345 acelerometrooo = ADXL345();

byte circuloo1[8]= {        // array que contiene todos los elementos de las
  B11111111,
  B11111111,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B11111111,
  B11111111
};
byte circuloo2[8]= {       // array que contiene todos los elementos de las
  B11111111,
  B11111111,
  B00000000,
  B11000000,
  B11000000,
  B00000000,
  B11111111,
  B11111111
};

byte circuloo3[8]= {       // array que contiene todos los elementos de las
  B11111111,
  B11111111,
  B00000000,
  B00000011,
  B00000011,
  B00000000,
  B11111111,
  B11111111
};

byte circuloo4[8]={B11111111,
  B00000000,
  B00000000,
  B00000110,
  B00000110,
  B00000000,
  B00000000,
  B11111111};

byte circuloo5[8]={
  B11111111,
  B11111111,
  B00000000,
  B01100000,
  B01100000,
  B00000000,
  B11111111,
  B11111111
};

unsigned long delayyy = 20;

void setup() {
  Serial.begin(9600);
  Serial.println("iniciar");
  Serial.println();
  acelerometrooo.powerOn();
  acelerometrooo.setRangeSetting(8);
  matrizzl.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  matrizzl.setIntensity(0,15);  //Brilo a la mitad 
  matrizzl.clearDisplay(0); 
}

void loop() {
cosito();
}


void cosito(){
int x,y,z;
acelerometrooo.readAccel(&x,&y,&z);
Serial.print("X:");
Serial.print(x);
Serial.print("; ");
Serial.print("y:");
Serial.print(y);
Serial.println("z");
Serial.println(z);
delay(80);
if(x==-4 && y>=-8 && y<=-7){
  for(int i=0; i<8;i++)
      {
        matrizzl.setRow(0,i,circuloo1[i]);
      }  
} 
delay(delayyy);
if(x>=-30 && y>=3 && x<=-4 && y<=14){
  for(int i=0; i<8;i++)
      {
        matrizzl.setRow(0,i,circuloo3[i]);
      }  
}
delay(delayyy); 
if(x<=-2 && y==4 &&x>=-3){
  for(int i=0; i<8;i++)
      {
        matrizzl.setRow(0,i,circuloo4[i]);
      }  
} 
delay(delayyy);
if(x>=2 && y>=-63 && x<=031 && y<=61){
  for(int i=0; i<8;i++)
      {
        matrizzl.setRow(0,i,circuloo2[i]);
      }  
} 
delay(delayyy);
if(x>=2 && y>=4 && x<=4 && y<=5){
  for(int i=0; i<8;i++)
      {
        matrizzl.setRow(0,i,circuloo2[i]);
      }  
} 
delay(delayyy);
}
