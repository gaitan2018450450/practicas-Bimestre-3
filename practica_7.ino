/*
 * Fundacion Kinal
 * centro educativo laboral kinal
 * Electronica
 * Quinto
 * A
 * taller de electronica digital reparacion en computadoras 
 * javier ricardo vivar sanchez
 * Eliezer Corado 
 * 2019585
 * 2018
 * Practica 7
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <MFRC522.h>
#include <SPI.h>
#include <RTClib.h>


#define LCD_DNIJV 0x26
#define fls 2
#define cols 16
#define verdeed 5
#define redd 4
#define RSTP 9
#define SSP 10


float sensibili=0.185;
int sens = A1;

LiquidCrystal_I2C LCD(LCD_DNIJV, cols, fls);
MFRC522 RFID(SSP, RSTP);
RTC_DS3231 rtc;


void valLCD(void);
void Usuario(void);
void Persona_incorrecta(void);

void setup() {
Serial.begin(9600);
LCD.init();
LCD.backlight();
Wire.begin();
rtc.begin(); 
SPI.begin();
RFID.PCD_Init();// Activa el MFRC522
Serial.println("Ingrese su Identificación");
Serial.println();
Serial.println("- - - - - - - - - - - - - - - - - -");
pinMode(verdeed,OUTPUT);
pinMode(redd,OUTPUT);

// 1 de Agosto del 2023, 12:59 pm 
rtc.adjust(DateTime(2023, 8, 1, 12, 59, 30));   
}

void loop() {
LCD.setCursor(0,0);
LCD.print("  Income_Kinal  ");
LCD.setCursor(0,1);
LCD.print("  Entrada:   ");
digitalWrite(redd, LOW); // El led inicia apagado
digitalWrite(verdeed,LOW); // El led inicia apagado

 // Acceso para nuevas tarjeras
  if ( ! RFID.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Selecciona una de las tarjetas
  if ( ! RFID.PICC_ReadCardSerial()) 
  {
    return;
  }
  // Muestra el UID sobre el Monitor Serial
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < RFID.uid.size; i++) 
  {
     Serial.print(RFID.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(RFID.uid.uidByte[i], HEX);
     content.concat(String(RFID.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(RFID.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.println("- - - - - - - - - - - - - - - - - -");
  Serial.print("Mensaje: ");
  content.toUpperCase();
  if (content.substring(1) == "C3 01 2D 0E") // si el No. de tarjeta es el correcto, realiza lo siguiente:
  {
  Serial.println("Acceso Permitido");
  Serial.println("- - - - - - - - - - - - - - - - - -");
  digitalWrite(verdeed, HIGH);
  digitalWrite(redd,LOW);
  Usuario(); // funcion que contiene las instrucciones para confirmar que el usuario es correcto
  delay(2000); // se mantiene el mensaje por 2 segundos
  valLCD(); // muestra en la LCD los valores 
  delay(6000); // se mantiene el mensaje por 6 segundos
  }
  else if (content.substring(1) != "C3 01 2D 0E"){  
    Serial.println("Acceso Denegado");
    Serial.println("- - - - - - - - - - - - - - - - - -");
  digitalWrite(redd, HIGH);
  digitalWrite(verdeed,LOW);
 Persona_incorrecta(); //funcion que indica que es el usuario incorrecto
  delay(1500);
  }
}

void valLCD(void){ // funcion que muestra los valores de V, C, P

// Valores de voltaje
float voltaje =  (float)25*analogRead(A1)/1023;//operacion para sacar el valor de voltaje

// Valores de corriente
float corriente = get_corriente(200);  
  
// Valores de potencia
 float potencia = corriente * voltaje;

LCD.clear();
LCD.setCursor(0,0);  
LCD.print("  Income - Kinal  ");
LCD.setCursor(0,1);  
LCD.print(voltaje,1);
LCD.setCursor(4,1);
LCD.print("V");
LCD.setCursor(6,1);  
LCD.print(corriente, 1);
LCD.setCursor(9,1);
LCD.print("A");
LCD.setCursor(11,1);  
LCD.print(potencia, 1); 
LCD.setCursor(15,1);
LCD.print("W");
} 

void Usuario(){ // funcion que confirma si el usuario registrado es correcto
DateTime now = rtc.now();
LCD.clear();
LCD.setCursor(0,0);  
LCD.print("User Registrado");
LCD.setCursor(0,1);  
LCD.print("Time:");
LCD.setCursor(5,1);
LCD.print(" ");
LCD.print(now.hour(), DEC);
LCD.print(':');
LCD.print(now.minute(), DEC);
LCD.print(':');
LCD.print(now.second(), DEC);
}

void Persona_incorrecta(){ // funcion que confirma si el usuario registrado es incorrecto
LCD.clear();
LCD.setCursor(0,0);  
LCD.print("  EEGSA - Kinal  ");
LCD.setCursor(0,1);  
LCD.print("Usuario_invalido");  
}

float get_corriente(int n_muestras) // funcion que acompana la formula para obtener el valor de corriente
{
  float voltajeSensor;
  float CURRENT=0;
  for(int i=0;i<n_muestras;i++)
  {
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);//lectura del sensor
    CURRENT=CURRENT+(voltajeSensor-2.5)/sensibili; //Ecuación  para obtener la corriente
  }
  CURRENT=CURRENT/n_muestras;
  return(CURRENT);
}
