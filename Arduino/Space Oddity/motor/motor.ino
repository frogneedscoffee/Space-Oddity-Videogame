int motor = 11;

String inputString = "";
bool stringComplete = false;

void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  if(stringComplete){
    Serial.print("CMD recieved: ");
    Serial.println(inputString);
    inputString.trim();
    processCmd(inputString);
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
    if(inChar == '\n'){
      stringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
}

void processCmd(String cmd){
  if(cmd.equals("pierdeVida")){
    analogWrite(motor, 255);
    delay(1000);
    analogWrite(motor, 0);
  }
}
