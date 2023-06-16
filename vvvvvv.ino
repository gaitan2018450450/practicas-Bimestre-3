#include <Servo.h>
Servo myservo;

int Infrarojo = 2;
int IN1 = 8;      // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 9;      // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 10;     // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 11;     // pin digital 11 de Arduino a IN4 de modulo controlador
int demora = 10;      // demora entre pasos, no debe ser menor a 10 ms.

#define ch_LDR    A0  //pin A0 del arduino, a este conectaremos el punto medio del divisor de tension entre LDR y una resistencia de 33K
#define led_Azul  3   //led azul conectado al pin 3
#define led_Verde 4   //led verde conectado al pin 4
#define led_Rojo  6   //led rojo conectado al pin 5

//Variables
//Valores analogicos de la intensidad de cada color
int resultado_azul, resultado_rojo, resultado_verde;
//Valores analogicos leidos por la LDR
int resultado;

//Valor de umbral para los colores
int tol = 8; //este valor lo podremos cambiar segun los valores leidos por nuestra LDR

// Resultados de colores
// Verde
int resultado_azul2 = 0;
int resultado_rojo2 = 0;
int resultado_verde2 = 0;
// Rojo
int resultado_azul3 = 0;
int resultado_rojo3 = 0;
int resultado_verde3 = 0;
// Azul
int resultado_azul4 = 0;
int resultado_rojo4 = 0;
int resultado_verde4 = 0;

bool deteccion1 = 0;
bool servo = false;
void setup() {
  Serial.begin(9600);
  myservo.attach(7);
  pinMode(Infrarojo, INPUT);
  pinMode(IN1, OUTPUT);   // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Configuracion de I/O
  pinMode(ch_LDR, INPUT); //pin A0 como entrada
  pinMode(led_Azul, OUTPUT); //pin 3 como salida
  pinMode(led_Verde, OUTPUT); //pin 4 como salida
  pinMode(led_Rojo, OUTPUT);  //pin 5 como salida

  //Los leds inician en un estado de bajo
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
  myservo.write(0);
}

void loop() {
  arranque_stepper();
  if (digitalRead(Infrarojo) == LOW && deteccion1 == 0) {
    paro_stepper();
    //Enviendo el led rojo
    digitalWrite(led_Rojo, HIGH);
    //espero 150 milisegundos
    delay(150);

    //Leo el valor captado por la LDR
    resultado = analogRead(ch_LDR);
    resultado_rojo = map(resultado, 0, 1023, 0, 255); //lo linealizo
    //Lo muestro por medio del monitor serial
    Serial.print("Rojo = ");
    Serial.println(resultado_rojo);
    digitalWrite(led_Rojo, LOW);
    delay(150);

    //Enviendo el led verde
    digitalWrite(led_Verde, HIGH);
    //espero 150 milisegundos
    delay(150);

    //Leo el valor captado por la LDR
    resultado = analogRead(ch_LDR);
    resultado_verde = map(resultado, 0, 1023, 0, 255); //lo linealizo
    //Lo muestro por medio del monitor serial
    Serial.print("Green = ");
    Serial.println(resultado_verde);
    digitalWrite(led_Verde, LOW);
    delay(150);

    //Enviendo el led azul
    digitalWrite(led_Azul, HIGH);
    //espero 150 milisegundos
    delay(150);

    //Leo el valor captado por la LDR
    resultado = analogRead(ch_LDR);
    resultado_azul = map(resultado, 0, 1023, 0, 255); //lo linealizo
    //Lo muestro por medio del monitor serial
    Serial.print("Blue = ");
    Serial.println(resultado_azul);
    digitalWrite(led_Azul, LOW);
    delay(150);
    if (resultado_rojo == resultado_rojo2 && resultado_azul == resultado_azul2 && resultado_verde == resultado_verde2) {
      Serial.println("Color verde detectado");
      servo = true;
    }
    else if (resultado_rojo == resultado_rojo3 && resultado_azul == resultado_azul3 && resultado_verde == resultado_verde3) {
      Serial.println("Color rojo detectado");
      servo = false;
    }
    else if (resultado_rojo == resultado_rojo4 && resultado_azul == resultado_azul4 && resultado_verde == resultado_verde4) {
      Serial.println("Color azul detectado");
      servo = false;
    }
    deteccion1 = 1;
  }
  else if (digitalRead(Infrarojo) == HIGH && deteccion1 == 1) {
    deteccion1 = 0;
    if (servo == true) {
      myservo.write(90);
      Serial.println("Separado");
      delay(200);
    }
  }
  else if (digitalRead(Infrarojo) == HIGH && deteccion1 == 0) {
    myservo.write(0);
    servo = false;
  }
}

void arranque_stepper() {
  digitalWrite(IN1, HIGH);  // paso 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); // paso 2
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); // paso 3
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW); // paso 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);
}

void paro_stepper() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
