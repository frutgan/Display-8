#include <Ultrasonic.h>

int echo=A5;
int trig=2;
int distancia;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Ultrasonic ultrasonic(trig,echo);
}

void loop() {
  // put your main code here, to run repeatedly:
distancia=ultrasonic.distanceRead();
Serial.println(distancia);
}
