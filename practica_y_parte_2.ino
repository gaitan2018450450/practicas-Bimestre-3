/*Fundacion Kinal
 * Centredo educativo tecnico laboral kinal
 * Quinto perito
 * Quinto electronica
 * Codigo Tecnico:  EB5AM
 * Curso: taller de electredonica digital
 * Proyecto:CONTROL DE UNA SECUENCIA DE COLORES RGB                                                                
 * Dev: Eliezer Denilson gaitán Corado 
 * fecha: 09/06/2023 
*/

#define poten A0
#define red 3
#define green 5
#define blue 4
int m;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(poten, INPUT);

}

void loop() {
  m = map(analogRead(POT), 0, 1023, 100, 1000);

//analogWrite pondra valores  a los leds
  analogWrite(red, 174);
  analogWrite(green, 92);
  analogWrite(blue, 230);
  delay(m); // m son los limites de los valores 
  
  //analogWrite pondra valores  a los leds
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(m); // m son los limites de los valores
  
  //analogWrite pondra valores  a los leds
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(green, 255);
  delay(m);  // m son los limites de los valores
  
  //analogWrite pondra valores  a los leds
    analogWrite(red, 174);
  analogWrite(green, 92);
  analogWrite(blue, 230);
  delay(m);  // m son los limites de los valores
  
  //analogWrite pondra valores  a los leds
  analogWrite(red, 255);
  analogWrite(green, 87);
  analogWrite(blue, 35);
  delay(m);  // m son los limites de los valores 
}
