/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Eliezer Denilson Gaitán Corado
 * Carnet: 2018450
 * Proyecto: Uso de interrupciones externas- Bimestre III
*/

//librerias a utilizar
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>

//definicion de pines
#define boton1 3

int valor = 0; 
int estado = 0;

void bot00n(void);
void tempe(void);

volatile static bool estado_boton;
OneWire ourWire(4);
DallasTemperature sens00r(&ourWire);
Ticker accion_boton(bot00n, 6000); //cada 6 seg. mostrar si el boton esta cerrado/abierto
Ticker accion_temper(tempe, 3000); //mostrara la temperatura cada 3seg.

void setup() {
  Serial.begin(19200);
  pinMode(boton1, INPUT_PULLUP); //es la configuración del boton  
  digitalWrite(boton1, HIGH);
  sens00r.begin();
  accion_boton.start();
  accion_temper.start();
}

void loop() {
   accion_boton.update();
  accion_temper.update();
}

 void tempe(void){
 sens00r.requestTemperatures();
 float temperatura= sens00r.getTempCByIndex(0);
 Serial.println(temperatura);
}

void bot00n(void){
  valor = digitalRead(boton1);
  if(valor==1 ){
   Serial.println("ABIERTO") ;   
  }
else{
  Serial.println("CERRADO");
}
}
