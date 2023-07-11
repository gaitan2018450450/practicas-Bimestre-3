/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: javier ricardo vivar sanchez
 * Nombre:  Eliezer Denilson Gsitán Corado
 * 
  */
//Librerias
#include <SoftwareSerial.h>
#include <PCF8574.h>
#include <Wire.h>


//Directivas
#define PHIGH LOW  
#define PLOW HIGH  
#define buzz 2
#define rx 3
#define tx 4
#define altaV 5
#define bajaV 6
#define chimaltenango 7
#define chiquimula 8
#define guatemala 9
#define elprogreso 10
#define escuintla 11
#define huehuetenango 12
#define izabal 13
#define jalapa  A0
#define jutiapa A1
#define peten A2
#define quetzaltenango A3
#define quiche A4
#define retalhuleu A5
#define sacatepequez A6
#define sanmarcos A7
#define santarosa 2
#define solola 3
#define suchitepequez 4
#define totonicapan 5
#define zacapa 6

  #define Do 262
  #define Dosos 277
  #define Re 294
  #define Resos 311
  #define Mi 330
  #define Fa 349
  #define Fasos 370
  #define Sol 392
  #define Solsos 415
  #define La 440
  #define Lasos 466
  #define Si 494
  
//Constructores
SoftwareSerial bt(rx, tx);
PCF8574 expansor(0x27);

//Variables
bool iniciar = false;
String respuesta;
int aleatorio;


//Funciones
void fallaa();
void pregunton();
void pines();
void apagaral();
void respuestaE();

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  Wire.begin();
  expansor.begin();
  pines();
  Serial.println("Para iniciar Escriba (Iniciar) ");
  delay(500);     
}

void loop() {
  if(Serial.available()>0){
    String empezar = Serial.readStringUntil('\n');
  if ( empezar == String("Iniciar")){
  Serial.println("Primera pregunta");   
  iniciar = true;
    delay(500);
  }
  }
  
  if (iniciar == true){
  aleatorio = random(0, 21);
  pregunton();
  delay(500);
  Serial.println("Siguiente pregunta");   
  }
 
}

void pregunton(){
   if(aleatorio == 0){
    Serial.println("Cabecera departamental de Petén");
    respuestaE();
      if(respuesta == String("Flores")){    //Respuesta correcta
        apagaral();        
        digitalWrite(peten, HIGH);  
       Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
       }
      }
           
      if(aleatorio == 1){
    Serial.println("Cabecera departamental de Izabal");
    respuestaE();
      if(respuesta == String("Puerto Barrios")){    //Respuesta correcta
        apagaral();
        digitalWrite(izabal, HIGH); 
         Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
       }
      }
      
      else if(aleatorio == 2){
    Serial.println("Cabecera departamental de Alta Verapaz");
    respuestaE();
      if(respuesta == String("Coban")){    //Respuesta correcta
        apagaral();  
        digitalWrite(altaV, HIGH); 
        Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 3){
    Serial.println("Cabecera departamental de Quiché");
    respuestaE();
      if(respuesta == String("Santa Cruz del Quiche")){   //Respuesta correcta
         apagaral();  
         digitalWrite(quiche, HIGH);   
           Serial.println("Respuesta correcta"); 
      }
      else{
        fallaa();
              Serial.println("Respuesta incorrecta");
       }
      }
      
       else if(aleatorio == 4){
    Serial.println("Cabecera departamental de Huehuetenango");
    respuestaE();
      if(respuesta == String("Huehuetenango")){  //Resuesta Correcta
              apagaral();  
        digitalWrite(huehuetenango, HIGH);
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
      else if(aleatorio == 5){
    Serial.println("Cabecera departamental de Escuintla");
    respuestaE();
      if(respuesta == String("Escuintla")){
              apagaral();  
        digitalWrite(escuintla, HIGH);
         Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
      else if(aleatorio == 6 ){
    Serial.println("Cabecera departamental de San Marcos");
    respuestaE();
      if(respuesta == String("San Marcos")){
              apagaral();  
        digitalWrite(sanmarcos, HIGH);  
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 7 ){
    Serial.println("Cabecera departamental de Jutiapa");
    respuestaE();
      if(respuesta == String("Jutiapa")){
              apagaral();  
        digitalWrite(jutiapa, HIGH); 
 Serial.println("Respuesta correcta"); 
      }
      else{
      fallaa();
            Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 8 ){
    Serial.println("Cabecera departamental de Baja Verapaz");
    respuestaE();
      if(respuesta == String("Salama")){
             apagaral();  
        digitalWrite(bajaV, HIGH); 
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else  if(aleatorio == 9 ){
    Serial.println("Cabecera departamental de Santa Rosa");
    respuestaE();
      if(respuesta == String("Cuilapa")){
             apagaral();  
        expansor.write(santarosa, HIGH);
          Serial.println("Respuesta correcta");    
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 10 ){
    Serial.println("Cabecera departamental de Zacapa");
    respuestaE();
      if(respuesta == String("Zacapa")){
              apagaral();  
        expansor.write(zacapa, HIGH);   
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 11 ){
    Serial.println("Cabecera departamental de Suchitepéquez");
    respuestaE();
      if(respuesta == String("Mazatenango")){
              apagaral();  
        expansor.write(suchitepequez, HIGH);
         Serial.println("Respuesta correcta");          
      }
      else{
        fallaa();
              Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 12 ){
    Serial.println("Cabecera departamental de Chiquimula");
    respuestaE();
      if(respuesta == String("Chiquimula")){
              apagaral();  
        digitalWrite(chiquimula, HIGH);   
    Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 13 ){
    Serial.println("Cabecera departamental de Guatemala");
    respuestaE();
      if(respuesta == String("Guatemala")){
              apagaral();  
        digitalWrite(guatemala, HIGH); 
        Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
       Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 14 ){
    Serial.println("Cabecera departamental de Jalapa");
    respuestaE();
      if(respuesta == String("Jalapa")){
             apagaral();  
        digitalWrite(jutiapa, HIGH);  
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 15 ){
    Serial.println("Cabecera departamental de Chimaltenango");
    respuestaE();
      if(respuesta == String("Chimaltenango")){
             apagaral();  
        digitalWrite(chimaltenango, HIGH);  
         Serial.println("Respuesta correcta");  
      }
      else{
        fallaa();
              Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 16 ){
    Serial.println("Cabecera departamental de Quetzaltenango");
    respuestaE();
      if(respuesta == String("Quetzaltenango")){
             apagaral();  
        digitalWrite(quetzaltenango, HIGH); 
         Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 17 ){
    Serial.println("Cabecera departamental de El progreso");
    respuestaE();
      if(respuesta == String("Guastatoya")){
             apagaral();  
        digitalWrite(elprogreso, HIGH);  
          Serial.println("Respuesta correcta"); 
      }
      else{
     fallaa();
           Serial.println("Respuesta incorrecta");
       }
      }
      
      else if(aleatorio == 18 ){
    Serial.println("Cabecera departamental de Retalhuleu");
    respuestaE();
      if(respuesta == String("Retalhuleu")){
              apagaral();  
        digitalWrite(retalhuleu, HIGH);
        Serial.println("Respuesta correcta");  
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 19 ){
    Serial.println("Cabecera departamental de Sololá");
    respuestaE();
      if(respuesta == String("Solola")){
             apagaral();  
        expansor.write(solola, HIGH); 
         Serial.println("Respuesta correcta");         
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
     else if(aleatorio == 20 ){
    Serial.println("Cabecera departamental de Totonicapán");
    respuestaE();
      if(respuesta == String("Totonicapan")){
             apagaral();  
        expansor.write(totonicapan, HIGH);  
          Serial.println("Respuesta correcta"); 
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
      else if(aleatorio == 21 ){
    Serial.println("Cabecera departamental de Sacatepéquez");
    respuestaE();
      if(respuesta == String("La antigua guatemala")){
              apagaral();  
        digitalWrite(sacatepequez, HIGH);
          Serial.println("Respuesta correcta");  
      }
      else{
       fallaa();
             Serial.println("Respuesta incorrecta");
       }
      }
      
      if(respuesta == String("Fin")){
       iniciar = false;
       Serial.print("Game Over");
    }
  }
  
void fallaa(){
        Serial.println("Respuesta incorrecta");
  }
  
void apagaral(){
       digitalWrite(peten, LOW); 
       digitalWrite(izabal, LOW);   
       digitalWrite(altaV, LOW); 
       digitalWrite(quiche, LOW); 
       digitalWrite(huehuetenango, LOW); 
       digitalWrite(escuintla, LOW);   
       digitalWrite(sanmarcos, LOW); 
       digitalWrite(jutiapa, LOW);
       digitalWrite(bajaV, LOW); 
       expansor.write(santarosa, LOW);   
       expansor.write(zacapa, LOW); 
       expansor.write(suchitepequez, LOW); 
       digitalWrite(chiquimula, LOW); 
       digitalWrite(guatemala, LOW);   
       digitalWrite(jalapa, LOW); 
       digitalWrite(chimaltenango, LOW);
       digitalWrite(quetzaltenango, LOW); 
       digitalWrite(elprogreso, LOW);   
       digitalWrite(retalhuleu, LOW); 
       expansor.write(solola, LOW); 
       expansor.write(totonicapan, LOW); 
       digitalWrite(sacatepequez, LOW);   
  }
  
void pines(){
       pinMode(buzz, OUTPUT); 
       pinMode(peten, OUTPUT); 
       pinMode(izabal, OUTPUT);   
       pinMode(altaV, OUTPUT); 
       pinMode(quiche, OUTPUT); 
       pinMode(huehuetenango, OUTPUT); 
       pinMode(escuintla, OUTPUT);   
       pinMode(sanmarcos, OUTPUT); 
       pinMode(jutiapa, OUTPUT);
       pinMode(bajaV, OUTPUT);   
       pinMode(chiquimula, OUTPUT); 
       pinMode(guatemala, OUTPUT);   
       pinMode(jalapa, OUTPUT); 
       pinMode(chimaltenango, OUTPUT);
       pinMode(quetzaltenango, OUTPUT); 
       pinMode(elprogreso, OUTPUT);   
       pinMode(retalhuleu, OUTPUT); 
       pinMode(sacatepequez, OUTPUT);   
  }

  void respuestaE(){
  int tiempoM = 10;
  bool tiempoA = false;
  while (!Serial.available() && tiempoA == false){
  tiempoM --;
  delay(1000);
if(tiempoM < 0){
  tiempoA = true; 
} 
}
respuesta = Serial.readStringUntil('\n');
}
