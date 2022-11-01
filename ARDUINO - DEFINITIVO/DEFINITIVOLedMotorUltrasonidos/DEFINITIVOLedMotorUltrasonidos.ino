//ULTRASONIDOS
const int EchoPin = 5;
const int TriggerPin = 3;

//MOTOR
int motor = 9;

//LED
int pinR=3;
int pinG=5;
int pinB=6;

//Variables
String Lectura= "0";
int numVida = 0;

void setup() {
  //ULTRASONIDOS
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  //MOTOR
  pinMode(motor, OUTPUT);

  //LED
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
//RECIBIR LECTURA
  if(Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }

//ENCENDEMOS ULTRASONIDOS
  digitalWrite(TriggerPin, HIGH);
   delay(1);
   digitalWrite(TriggerPin, LOW);
   int valorEntrada = pulseIn(EchoPin, HIGH);
   int distancia = valorEntrada/58.2; //valor en cm

//ENVIAMOS "PRESS"
   if(distancia>7 && distancia<25){
    Serial.println("PRESS");
   }
   delay(100);

//RECIBE PIERDE VIDA
  if(Lectura =="pierdeVida"){
    //VALOR numVida
    numVida++;
    Serial.print("numVida: ");
    Serial.println(numVida);

    //ENCENDEMOS MOTOR
    analogWrite(motor, 255);
    delay(1500);
    analogWrite(motor, 0);
    delay(1500);
    
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
      analogWrite(pinR, 180);
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
    }
}
  
//1, 2, 3 VERDE
//4, 5 AMARILLO/NARANJA
//6, 7 ROJO
