#include <Servo.h>
Servo servo1;
Servo servo2;
// ANALOGICOS
int joyX=A0;
int joyY=A1;
byte joyVal;
void setup() {
  Serial.begin(9600);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  servo1.attach(3);
  servo2.attach(4);
}
void loop() {
  joyVal = analogRead(joyX);
  Serial.println(joyX)/4;
 // joyVal = map(joyVal, 0, 1023, 0, 180);
  servo1.write(joyVal);

  
}
