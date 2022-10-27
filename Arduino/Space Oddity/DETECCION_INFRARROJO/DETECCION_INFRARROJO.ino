const int pinDetecta = 7;

int obstaculo = HIGH;

void setup() {
  pinMode (pinDetecta, INPUT);
  Serial.begin (115200);

}

void loop() {
  obstaculo = digitalRead(pinDetecta);
  if(obstaculo == LOW){
    Serial.println ("shoot");
    delay (100);
  }
}
