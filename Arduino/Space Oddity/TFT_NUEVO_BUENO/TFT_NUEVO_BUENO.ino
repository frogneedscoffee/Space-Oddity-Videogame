//NUEVO CÓDIGO BIEN TFT

#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//#include <Adafruit_TFTLCD.h>
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define PLAY 1
#define DAMAGE 2
#define GAMEOVER 3

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define VIOLET 0xB527E1

int currentPage;
String Lectura = "NADA";
int InGame = 1;

int sigue1 = 1;
int sigue2 = 1;
int veces = 0;

void setup() {
  tft.begin(0x9486);
  Serial.begin(9600);
  tft.setRotation(3);
  drawHomeScreen();
  currentPage = 0;
}

void loop() {
  if(currentPage == 0 && Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }
    if(Lectura=="YesStart"){
      drawInGameScreen(); 
    }
       

}

void drawHomeScreen (){
  tft.fillScreen(BLACK);
  tft.setTextColor(MAGENTA);
  tft.setTextSize(6);
  tft.setCursor(28, 60),
  tft.print("Space Oddity");
  delay(250);
  tft.drawRoundRect(160, 120, 160, 160, 6, MAGENTA);    //draw rounded box (x, y, width, height, radius, color
}

void drawInGameScreen (){
  switch(InGame){
    case PLAY:
    if(sigue1==1){
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN);
    tft.setTextSize(8);
    tft.setCursor(28, 80),
    tft.print("PLAY!");
    delay(250);
    sigue1=0;
    }
    break;

    case DAMAGE:
    if(sigue2==1 && veces<8){
      tft.fillScreen(BLACK);
      tft.setTextColor(BLUE);
      tft.setTextSize(8);
      tft.setCursor(60, 80),
      tft.print("DAMAGE");
      delay(250);
      sigue2=0;
      veces++;
    } else if (sigue2==0 && veces<8){
        tft.fillScreen(BLACK);
        delay(250);
        sigue2=1;
        veces++;
    } else if(veces=8){
        InGame=PLAY;
    }
    break;

    case GAMEOVER:
    tft.fillScreen(BLACK);
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(28, 80),
    tft.print("Game Over");
    delay(250);
    break;
  }

  if(Lectura=="YesStart"){
    InGame=PLAY;
  }
  else if(Lectura=="YesDamage"){
    InGame=DAMAGE;
  }
  else if(Lectura=="GameOver"){
    InGame=GAMEOVER;
  }
  
}
