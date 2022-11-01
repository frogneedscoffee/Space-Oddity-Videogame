int pinR=3;
int pinG=5;
int pinB=6;
String Lectura= "0";
int numVida = 0;

void setup() {
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }

  if(Lectura =="pierdeVida"){
    numVida++;
    Serial.print("numVida: ");
    Serial.println(numVida);
    Lectura = "0";
  }

    if(numVida== 0 || numVida == 1 || numVida == 2 || numVida == 3){
      analogWrite(pinG, 0);
      analogWrite(pinR, 255);
      analogWrite(pinB, 255);
    }

    if(numVida== 4 || numVida == 5){
      analogWrite(pinG, 0);
      analogWrite(pinR, 0);
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
