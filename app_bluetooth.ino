#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Ticker.h>
#define led 3
//Variables
volatile static bool estado;
float temp;
char estadoL;
//Funciones
void isrTemp(void);
void accionled();


//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensorCR7(&ourWire); //Se declara una objeto para nuestro sensor
Ticker accionTemp(isrTemp, 10000);

void setup() {
  Serial.begin(9600);
  sensorCR7.begin();
  accionTemp.start();
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Serial.println("Inicia la interactividad");
}

void loop() {
accionTemp.update();
}

void accionled(){
   if (Serial.available() > 0)
  {
    estadoL = Serial.read(); //Voy a guardar en el char el caracter leido
  }

  if (estadoL == 1) { //Si el caracter es L, se apaga el led
    digitalWrite(led, LOW);
  }

  else if (estadoL == 2) { //Si el caracter es H, se enciende el led
    digitalWrite(led, HIGH);
  }
}
  
void isrTemp(void){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  temp= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("**** ");  
  Serial.print("La temperatura es: ");  
  Serial.print(temp);
  Serial.print(" C");  
  Serial.println(" ****");
  }
