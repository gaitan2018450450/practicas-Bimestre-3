#define led 5
#define pot A0

int luz;
void setup() {
pinMode(led,OUTPUT);
}

void loop() {
  luz = analogRead(pot)/4;
  analogRead(pot);
  analogWrite(led,luz);
}
