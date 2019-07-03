int sensor=3;
int LED=4;
void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  if(digitalRead(sensor)==HIGH){
    digitalWrite(LED,LOW);
    Serial.println("OBJETO BLANCO");
    delay(10);
    }
  if(digitalRead(sensor)==LOW){
    digitalWrite(LED,HIGH);
    Serial.println("OBJETO NEGRO");
    delay(10);
    }
  

}
