void setup() {
  Serial.begin(9600);
  
  //TFT
  tft.begin(0x9486);
  tft.setRotation(1);

  //ULTRASONIDOS
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  //LED
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);

  //MOTOR
  oinMode(MOTOR, OUTPUT);

  drawHomeScreen();
  currentPage = "home";
}

void loop(){
  //--------INPUT--------
  //VEMOS SI HAY UNA MANO FRENTE AL SENSOR DE ULTRASONIDOS
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  int valorEntrada = pulseIn(EchoPin, HIGH);
  int distancia = valorEntrada/58.2; //valor en cm

  unsigned long static int tiempoanterior = 0;
  unsigned long int tiempo;


  if(distancia>7 && distancia<25){
    Serial.println("PRESS");
  }
  else{
   Serial.println("NOT PRESS");
  }
  delay(100);

  //--------OUTPUT--------
  lecturaSerie(); //leemos lo que nos llega de Unity

  if(Lectura=="yesStart"){
    Lectura="";
    currentPage = "game";
    drawInGameScreen();
  }

  if(Lectura=="victory"){
    Lectura="";
    drawVictoryScreen();
  }
    
  if(Lectura=="muere"){
    Lectura="";
    drawGameOverScreen();
  }

  if (Lectura=="pierdeVida"){
    
    tiempo = millis(); // mide el tiempo que pasó desde que empezó a correr el programa
    
    Serial.print("ENTROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    Lectura = "";
    numVida--;
    Serial.print("numVida: ");
    Serial.println(numVida);

    if (tiempo - tiempoanterior > 8000){
      Serial.println("millis: " +String (tiempo-tiempoanterior));
      //Serial.println("anterior: " +String (tiempoanterior));

      drawDamageScreen();
      tiempoanterior = tiempo;
    }
    
    drawInGameScreen();
  }

  if(numVida== 7 || numVida == 6 || numVida == 5 || numVida == 4){
    analogWrite(pinG, 0);
    analogWrite(pinR, 255);
    analogWrite(pinB, 255);
  }

  if(numVida== 3 || numVida == 2){
    analogWrite(pinG, 0);
    analogWrite(pinR, 100);
    analogWrite(pinB, 255);
  }

  if(numVida== 1){
    analogWrite(pinG, 255);
    analogWrite(pinR, 0);
    analogWrite(pinB, 255);
  }

  if (numVida == 0 || Lectura=="muere"){
      for (int i = 0; i < 3; i++){
        analogWrite(pinG, 255);
        analogWrite(pinR, 255);
        analogWrite(pinB, 255);
        delay(500);
        analogWrite(pinG, 255);
        analogWrite(pinR, 0);
        analogWrite(pinB, 255);
        delay(500);
      }

      //MOTOR
      /*
      digitalWrite(motor, LOW);
      delay(2000);
      digitalWrite(motor, HIGH);
      */
      
      delay(2000);

      reset();
    }
    
}
