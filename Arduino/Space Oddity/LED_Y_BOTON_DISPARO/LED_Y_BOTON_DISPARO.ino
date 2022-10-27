const int boton = 7;
int pinR = 3;
int pinG = 5;
int pinB = 6;

int obstaculo = LOW;

void setup() {
  pinMode (boton, INPUT_PULLUP);
   pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  Serial.begin (9600);

}

void loop() {
  obstaculo = digitalRead(boton);
  if(obstaculo == LOW){
    Serial.println ("shoot");
    analogWrite(pinR, 255);
    analogWrite (pinG, 0);
    analogWrite(pinB, 0);
    delay(100);
  }
  else {
    Serial.println ("wait");
    analogWrite(pinR, 0);
    analogWrite (pinG, 0);
    analogWrite(pinB, 0);
  }
  delay (100);

  
}
