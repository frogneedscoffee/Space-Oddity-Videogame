#include <avr/wdt.h> //libreria del watchdog

//ULTRASONIDOS
#define EchoPin 2
#define TriggerPin 4

//MOTOR
int motor = 9;

//LED
int pinR=6;
int pinG=5;
int pinB=3;

//Variables
String Lectura= "0";
int numVida = 0;

void setup() {
  //ULTRASONIDOS
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  //MOTOR
  pinMode(motor, OUTPUT);
  digitalWrite(motor, HIGH);

  //LED
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Holi");
}

void loop() {
//ENCENDEMOS ULTRASONIDOS
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  int valorEntrada = pulseIn(EchoPin, HIGH);
  //delayMicroseconds(2);
  int distancia = valorEntrada/58.2; //valor en cm


   if(distancia>7 && distancia<25){
    Serial.println("PRESS");
   }
   delay(100);
   
  
//RECIBIR LECTURA
  if(Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }

//RECIBE PIERDE VIDA
  if(Lectura =="pierdeVida"){
    //VALOR numVida
    numVida++;
    Serial.print("numVida: ");
    Serial.println(numVida);

    //ENCENDEMOS MOTOR
    digitalWrite(motor, LOW);
    delay(1500);
    //analogWrite(motor, 0);
    digitalWrite(motor, HIGH);
    
    Lectura = "0";
  }

//CAMBIOS DE COLORES LED
    if(numVida== 0 || numVida == 1 || numVida == 2 || numVida == 3){
      analogWrite(pinG, 0);
      analogWrite(pinR, 255);
      analogWrite(pinB, 255);
    }

    if(numVida== 4 || numVida == 5){
      analogWrite(pinG, 0);
      analogWrite(pinR, 100);
      analogWrite(pinB, 255);
    }

    if(numVida== 6 || numVida == 7){
      analogWrite(pinG, 255);
      analogWrite(pinR, 0);
      analogWrite(pinB, 255);
    }

    if(numVida == 7 || Lectura=="muere"){
      analogWrite(pinG, 255);
      analogWrite(pinR, 0);
      analogWrite(pinB, 255);
      delay(500);
      analogWrite(pinG, 255);
      analogWrite(pinR, 255);
      analogWrite(pinB, 255);
      delay(500);
      analogWrite(pinG, 255);
      analogWrite(pinR, 0);
      analogWrite(pinB, 255);
      delay(500);
      analogWrite(pinG, 255);
      analogWrite(pinR, 255);
      analogWrite(pinB, 255);
      delay(500);
      analogWrite(pinG, 255);
      analogWrite(pinR, 0);
      analogWrite(pinB, 255);
      delay(2000);

      reset();
    }
}

void reset(){
  wdt_enable(WDTO_15MS);
  while(1){};
}
  
//1, 2, 3 VERDE
//4, 5 AMARILLO/NARANJA
//6, 7 ROJO
