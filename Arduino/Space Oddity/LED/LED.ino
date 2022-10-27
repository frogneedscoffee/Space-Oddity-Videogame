int pinR = 3;
int pinG = 5;
int pinB = 6;
 
void setup() {
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
}
 
void loop() {
  delay(100);
  analogWrite(pinR, 255);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
  delay(1000);
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
  delay(100);
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 255);
  delay(1000);
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);
  delay(100);
  analogWrite(pinR, 255);
  analogWrite(pinG, 0);
  analogWrite(pinB, 255);
  delay(1000);
}
