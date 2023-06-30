 SoftwareSerial bluetooth (10,11);
 #include led 12
void setup() {
Serial.begin(9600);
bluetooth.begin(38400)
pinMode (12,OUTPUT);
}
char recepcion;
void loop() {
 if(bluetooth.available()){
  //Serial.write(bluetooth.read());
 recepcion=bluetooth.read();
 Serial.println (recepcion);
 if(recepcion==1);{
  Serial.println("encender") 
  digitalWrite(12, HIGH);
  
 }

 if(recepcion==2);{
  Serial.println("apagar") 
  digitalWrite(12, LOW);
 }
 if(Serial.available()){
  bluetooth.write (Serial.read());
 }
}
