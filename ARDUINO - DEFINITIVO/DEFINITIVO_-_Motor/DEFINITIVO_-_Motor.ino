int motor = 6;

String lectura = "0";

void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }

  if (Lectura=="pierdeVida"){
    analogWrite(motor, 255);
    delay(1500);
    analogWrite(motor, 0);
    delay(1500);
    Lectura="0"
  }
}
