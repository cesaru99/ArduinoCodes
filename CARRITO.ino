#include <AFMotor.h>
AF_DCMotor motor1(4);
AF_DCMotor motor2(3);
int sensor1 = 22;
int sensor2 = 24;
//int boton1 = 26;
//int A=0;
//int salida2=27;
//int salida7=28;
//int salida10=29;
//int salida15=30;


void setup() {
  //Serial.begin(9600);
  //Serial.println("Profe no encontre el modulo de motores para simularlo en proteus,la unica forma que encontre fue mostrandolo en el serial");
  motor1.setSpeed(74);
  motor2.setSpeed(78);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  //pinMode(boton1,INPUT);
  //pinMode(salida2,OUTPUT);
  //pinMode(salida7,OUTPUT);
  //pinMode(salida10,OUTPUT);
  //pinMode(salida15,OUTPUT);
  delay(5000);
}

void loop(){
if((digitalRead(sensor1)==LOW) && (digitalRead(sensor2)==LOW)){
  //Serial.println("Los 2 motores estan Encendidos");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  //digitalWrite(salida2,HIGH);
  //digitalWrite(salida10,HIGH);
  //digitalWrite(salida7,LOW);
  //digitalWrite(salida15,LOW);
  
  
  
}
  if((digitalRead(sensor1)==HIGH) && (digitalRead(sensor2)==LOW)){
   // Serial.println("Motor 1 reversa, Motor 2 delante");
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    //digitalWrite(salida2,LOW);
    //digitalWrite(salida7,HIGH);
    //digitalWrite(salida10,HIGH);
    
    
    }
  if((digitalRead(sensor2)==HIGH) && (digitalRead(sensor1)==LOW)){
    //Serial.println("Motor 1 deleante, motor 2 reversa");
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    //digitalWrite(salida2,HIGH);
    //digitalWrite(salida7,LOW);
    //digitalWrite(salida10,LOW);
    //digitalWrite(salida15,HIGH);
    
    
    }
   if((digitalRead(sensor1)==HIGH) && (digitalRead(sensor2)==HIGH)){
    //Serial.println("Ambos motores se detienen");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    //digitalWrite(salida2,LOW);
    //digitalWrite(salida7,LOW);
    //digitalWrite(salida10,LOW);
    //digitalWrite(salida15,LOW);
    
    }
    
    }

    
