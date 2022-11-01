const int EchoPin = 5;
const int TriggerPin = 3;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
void loop() {
   digitalWrite(TriggerPin, HIGH);
   delay(1);
   digitalWrite(TriggerPin, LOW);
   int valorEntrada = pulseIn(EchoPin, HIGH);
   int distancia = valorEntrada/58.2; //valor en cm

   if(distancia>7 && distancia<25){
    Serial.println("PRESS");
   }
   delay(100);
   
}
