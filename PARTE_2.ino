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
#include <Ticker.h>
#include <DallasTemperature.h>
#include <OneWire.h>

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
  accion_boton.start(); //inicia el ticker
  accion_temper.start(); //inicia el ticker
}

void loop() {
   accion_boton.update(); //actualiza el valor de ticker
  accion_temper.update(); //actualiza el valor de ticker
}

 void tempe(void){
 sens00r.requestTemperatures();
 float temperatura= sens00r.getTempCByIndex(0);  //consigue el valor de temperatura
 Serial.println(temperatura); //imprime el valor en el monitor serial
}

void bot00n(void){
  valor = digitalRead(boton1);
  if(valor==1 ){
   Serial.println("ABIERTO") ; //imprime la palabra abierto en el monitor serial  
  }
else{
  Serial.println("CERRADO"); //imprime la palabra cerrado en el monitor serial
}
}
