#include <LiquidCrystal.h>
#include <Password.h>
#include <Keypad.h>
#include <Servo.h>
LiquidCrystal lcd(0,1,2,3,4,5,6); // (rs,rw,enable,d4,d5,d6,d7)
// Contrasena
Password password = Password("1029");
// Declarar pines componentes
int LEDRED = 7;
int LEDGREEN = 8;
int LEDAMARILLO = 9;
Servo SERVO;
byte error=0;
byte contador=0;
const byte ROWS = 4;//filas de la matriz de botones
const byte COLS = 4;//columnas
// Definimos el Keymap

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 10,11,12,13 };// Conectar los keypads ROW1, ROW2, ROW3 y ROW4 a esos Pines de Arduino.
byte colPins[COLS] = { 14,15,16,17, };// Conectar los keypads COL1, COL2, COL3 y COL4 a esos Pines de Arduino.
// Creamos el Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  SERVO.attach(18);
  lcd.begin(16,2);
  SERVO.write(0);
  keypad.addEventListener(keypadEvent);
  pinMode(LEDRED, OUTPUT);  
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
  digitalWrite(LEDRED, HIGH);  
  digitalWrite(LEDGREEN, LOW);
  digitalWrite(LEDAMARILLO, LOW);
  lcd.clear();
  lcd.print("CLAVE: ");
  contador=0;
}
void loop() {
  keypad.getKey();
}
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
  lcd.clear();
  lcd.print("CLAVE:");
  contador++;
  if(contador==1){
    lcd.print("*");
    }
  if(contador==2){
    lcd.print("**");
    }
    if(contador==3){
    lcd.print("***");
    }
    if(contador==4){
    lcd.print("****");
    contador=0;
    }
    if(contador>4){
    lcd.print("****");
    contador=0;
    }
    
  //lcd.print(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    case '#': password.reset(); 
              SERVO.write(0);
              digitalWrite(LEDRED, HIGH);  
              digitalWrite(LEDGREEN, LOW);
              digitalWrite(LEDAMARILLO, LOW);
              lcd.clear();
              lcd.print("CERRANDO");
              delay(1000);
              lcd.clear();
              lcd.print("CLAVE:");
              break;
              
    default: password.append(eKey);
     }
  }
}
void checkPassword(){
  if (password.evaluate()){
    lcd.clear();
    lcd.print("BIENVENIDO");
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDAMARILLO, LOW);
    contador=0;
    SERVO.write(90);
    error=0;
    delay(1500);// MODIFIQUE EL TIEMPO PARA VER EN PROTEUS
    
  }else{
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDAMARILLO, LOW);
    lcd.clear();
    lcd.print("CLAVE ERRONEA");
    password.reset();
    delay(2000); // TIEMPO
    lcd.clear();
    lcd.print("CLAVE: ");
    SERVO.write(0);
    error++;
    contador=0;
    
  }
  if(error==2){
    lcd.clear();
    lcd.print("TIENES");
    lcd.setCursor(0,1);
    lcd.print("1 OPORTUNIDAD");
    password.reset();
    delay(3000);
    lcd.clear();
    lcd.print("CLAVE: ");
    SERVO.write(0);
    
  }
  if(error==3){
    lcd.clear();
    lcd.print("ACCESO");
    lcd.setCursor(0,1);
    lcd.print("DENEGADO");
    delay(2000);
    lcd.clear();
    lcd.print("ESPERA 10s");
    digitalWrite(LEDRED,LOW);
    for(int i=0; i<=10; i++){
      digitalWrite(LEDAMARILLO, HIGH);
      delay(500);
      digitalWrite(LEDAMARILLO, LOW);
      delay(500);
      lcd.setCursor(i,2);
      lcd.print("#");
      }
      digitalWrite(LEDRED, HIGH);  
      digitalWrite(LEDGREEN, LOW);
      digitalWrite(LEDAMARILLO, LOW);
      password.reset();
      lcd.clear();
      lcd.print("CLAVE: ");
      error=0;
      contador=0;
      
    }
  }
  
