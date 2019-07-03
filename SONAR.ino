#include <LiquidCrystal.h>
LiquidCrystal lcd(0, 1, 2, 3, 4, 5, 6); // (rs, enable, d4, d5, d6, d7)
const int trigPin = 7;
const int echoPin = 8;
const int LED = 9;
long tiempo;
int distanciacm;

void setup() {
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
}
void loop() { 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
tiempo = pulseIn(echoPin, HIGH);
distanciacm= tiempo*0.034/2; // v=d/t entonces sabemos que la velocidad del sonido es de 343,2 m/s y dividi el tiempo entre 2 porque conto en ir y venir la onda, y solo queremos la mitad que seria cuando la onda choca en pared.
lcd.setCursor(0,0);
lcd.print("Distancia: ");
lcd.print(distanciacm);
lcd.print("  cm");
delay(10);
if(distanciacm>=20){
  digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
    }
}
