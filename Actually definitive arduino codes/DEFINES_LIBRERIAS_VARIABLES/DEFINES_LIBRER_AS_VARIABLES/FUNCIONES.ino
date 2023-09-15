//--------FUNCIONES--------
void lecturaSerie(){
  if(Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
  }
}

void reset(){
  wdt_enable(WDTO_15MS);
  while(1){};
}

void drawHomeScreen (){
  tft.fillScreen(BLACK);
  
  //TÍTULO
  tft.setTextColor(MAGENTA);
  tft.setTextSize(11);
  tft.setCursor(80, 60);
  tft.print("SPACE");
  tft.setCursor(50, 160);
  tft.print("ODDITY");
  delay(250);

  //STARS
  tft.fillRect(20, 100, 7, 7, YELLOW);
  tft.fillRect(400, 100, 7, 7, WHITE);
  tft.fillRect(200, 30, 7, 7, WHITE);
  tft.fillRect(150, 300, 7, 7, YELLOW);
  tft.fillRect(80, 30, 7, 7, WHITE);
  tft.fillRect(450, 30, 7, 7, WHITE);
  tft.fillRect(20, 240, 7, 7, WHITE);
  tft.fillRect(35, 300, 7, 7, WHITE);
  tft.fillRect(250, 210, 7, 7, WHITE);
  tft.fillRect(450, 210, 7, 7, YELLOW);
  tft.fillRect(390, 290, 7, 7, WHITE);
  tft.fillRect(450, 300, 7, 7, WHITE);
  tft.fillRect(300, 280, 7, 7, WHITE);
}

void drawInGameScreen(){
  tft.fillScreen(BLACK);

  //STARS
  tft.fillRect(20, 20, 7, 7, YELLOW);
  tft.fillRect(200, 15, 7, 7, WHITE);
  tft.fillRect(400, 100, 7, 7, WHITE);
  tft.fillRect(200, 30, 7, 7, WHITE);
  tft.fillRect(150, 300, 7, 7, YELLOW);
  tft.fillRect(80, 30, 7, 7, WHITE);
  tft.fillRect(450, 30, 7, 7, WHITE);
  tft.fillRect(20, 240, 7, 7, WHITE);
  tft.fillRect(35, 300, 7, 7, WHITE);
  tft.fillRect(250, 210, 7, 7, WHITE);
  tft.fillRect(450, 210, 7, 7, YELLOW);
  tft.fillRect(390, 290, 7, 7, WHITE);
  tft.fillRect(450, 300, 7, 7, WHITE);
  tft.fillRect(300, 280, 7, 7, WHITE);

  //RECTÁNGULO DE FONDO
  tft.fillRoundRect(30, 30, 420, 260, 30, MAGENTA);

  //VIDAS
  tft.setTextColor(BLACK);
  tft.setTextSize(5);
  tft.setCursor(118, 200);
  tft.print("Vidas: ");

  tft.setTextColor(BLACK);
  tft.setTextSize(5);
  tft.setCursor(295, 200);
  tft.print("x");

  tft.setTextColor(BLACK);
  tft.setTextSize(5);
  tft.setCursor(330, 200);
  tft.print(numVida);

  //PLAY
  tft.setTextColor(GREEN);
  tft.setTextSize(12);
  tft.setCursor(80, 80);
  tft.print("PLAY!");
}

void drawDamageScreen(){
  tft.fillScreen(BLACK);

  for (int i = 0; i < 2; i++){
    //PARPADEO DAMAGE
    analogWrite(pinG, 255);
    analogWrite(pinR, 0);
    analogWrite(pinB, 255);

    digitalWrite(MOTOR, HIGH);
  
    tft.fillRect(0, 100, 480, 100, RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(8);
    tft.setCursor(95, 120);
    tft.print("DAMAGE");
  
    delay(500);
      
    tft.fillScreen(BLACK);
  
    analogWrite(pinG, 255);
    analogWrite(pinR, 255);
    analogWrite(pinB, 255);

    digitalWrite(MOTOR, LOW);
    
    delay(500);
  }
}

void drawGameOverScreen(){
  tft.fillScreen(BLACK);

  digitalWrite(MOTOR, HIGH);
  
  for (int i = 0; i < 2; i++){
    analogWrite(pinG, 255);
    analogWrite(pinR, 0);
    analogWrite(pinB, 255);
    
    tft.fillRect(0, 100, 480, 100, RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(7);
    tft.setCursor(45, 120);
    tft.print("Game Over!");
    
    delay(500);
    
    tft.fillScreen(BLACK);

    analogWrite(pinG, 255);
    analogWrite(pinR, 255);
    analogWrite(pinB, 255);
    
    delay(500);
  }

  digitalWrite(MOTOR, LOW);

  reset();
}

void drawVictoryScreen(){
  tft.fillScreen(BLACK);
  tft.fillRect(0, 100, 480, 100, GREEN);
  tft.setTextColor(WHITE);
  tft.setTextSize(7);
  tft.setCursor(95, 120);
  tft.print("VICTORY");
  delay(2000);

  reset();
}
