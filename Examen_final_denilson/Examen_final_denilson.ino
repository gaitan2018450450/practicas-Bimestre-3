#include <SoftwareSerial.h>

const int mediO = 7;        
const int mediT = 6;      
int VALV;                
float VVolt;               

float Sensibilidad = 0.190;

const int pinnA = A0;   
const float cONc = 1000.0;

SoftwareSerial XDL(7, 6);

unsigned long ANT = 0;
const unsigned long INTm = 1000;

void setup() {
  pinMode(mediO, OUTPUT);  // Configura el pin positivo como salida
  pinMode(mediT, OUTPUT);  // ConfigurA el pin negativo como salida
  Serial.begin(9600);    
  XDL.begin(9600);
}

char recep;

void loop() {
  // Verifica si hay datos 
  if (XDL.available()) {
    recep = XDL.read();
    Serial.println(recep);

    // Procesar comandos según corresponda
    if (recep == 'A') {
      mV();
    }
    else if (recep == 'B') {
      mR();
    }
    else if (recep == 'C') {
     mC();
    }
  }

 
  unsigned long TIEMa = millis();
  if (TIEMa - ANT >= INTm) {
    ANT = TIEMa;
  }
}

void mV() {
  digitalWrite(mediO, HIGH);
  digitalWrite(mediT, HIGH);
  VALV = analogRead(A1);               // Realiza lectura
  VVolt = map(VALV, 0, 1023, 0, 250) / 10.0; 
  Serial.print("Voltaje: ");
  Serial.println(VVolt);          
  XDL.print(VVolt);
  XDL.print(";");
}

void mR() {
  digitalWrite(mediO, LOW);
  digitalWrite(mediT, LOW);
  int valorAnalogico = analogRead(pinnA);

  float tensionMedida = (float)valorAnalogico * (5.0 / 1023.0);

  // Calcula la CCTT 
  float CCTT = tensionMedida / cONc;

  // Calcula la resistencia desconocida
  float rdc = tensionMedida / CCTT;

  Serial.print("Resistencia: ");
  Serial.println(rdc);
  XDL.print(rdc);
  XDL.print(";");
}

voidmC() {
  float CCTT=calculo(500);
      Serial.print("CCTT: ");
      Serial.println(CCTT,3);
      XDL.print(CCTT,3);
      XDL.print(";");
}
float calculo(int NOM1)
{
float LEEEE = 0;
float inten = 0;
for(int i=0;i<NOM1;i++)
{
  LEEEE= analogRead(A2) * (5.0 / 1023.0);
  inten=inten+(LEEEE-2.5)/Sensibilidad;
}
inten=inten/NOM1;
return(inten);
}
