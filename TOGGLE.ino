
int D7=1;
byte a=0;
void setup() {
    pinMode(D7, OUTPUT);
    digitalRead(2);
}
void loop() {
  if((digitalRead(2)==HIGH)&&(a==0)){                         //pregunta si se presionó el botón en el pin B0 y está apagado el LED
  digitalWrite(D7,HIGH);                                 //enciende el pin D0 donde está el LED o el logicstate
  a=1; 
  while(digitalRead(2)==HIGH){}
  }
 if((digitalRead(2)==HIGH) && (a==1)){
  digitalWrite(D7,LOW);
  a=0;
  while(digitalRead(2)==HIGH){}
  }
}
