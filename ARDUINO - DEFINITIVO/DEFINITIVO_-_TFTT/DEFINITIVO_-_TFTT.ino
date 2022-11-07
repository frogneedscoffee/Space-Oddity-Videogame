//LIBRERÍAS
#include <avr/wdt.h> //libreria del watchdog

#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//#include <Adafruit_TFTLCD.h>
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//PINES
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

//COLORES
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define VIOLET 0xB527E1

//VARIABLES
int currentPage;
String Lectura = "0";
int sigue;
int numVida = 7;

void setup() {
  tft.begin(0x9486);
  Serial.begin(9600);
  tft.setRotation(1);
  drawHomeScreen();
  currentPage = 0;
}

void loop() {
    //RECIBIR LECTURA
    if(currentPage == 0 && Serial.available() > 0){
    Lectura = Serial.readStringUntil('\n');
    Lectura = Lectura.substring(0, Lectura.length());
    Serial.println(Lectura);
    }

   //"HIPERVÍNCULOS"
    else if(Lectura=="YesStart"){
      drawInGameScreen();
      Lectura="0";
    }

    else if(Lectura=="victory"){
      drawVictoryScreen();g
      Lectura="0";
    }
    
    else if(Lectura=="muere"){
      drawGameOverScreen();
      Lectura="0";
    }

    else if (Lectura=="pierdeVida"){
      drawDamageScreen();
      numVida--;
      drawInGameScreen();
      Lectura = "";
    }
}

//480 (ancho x) x320 (alto y)
void drawHomeScreen (){
  //TÍTULO
  tft.fillScreen(BLACK);
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
    //PLAY
    tft.fillScreen(BLACK);
    tft.setTextColor(GREEN);
    tft.setTextSize(8);
    tft.setCursor(28, 80);
    tft.print("PLAY!");

    //VIDAS
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(28, 185);
    tft.print("Vidas: ");

    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(310, 185);
    tft.print("x");

    if(numVida==7){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("7");}
    
    else if(numVida==6){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("6");}

    else if(numVida==5){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("5");}

    else if(numVida==4){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("4");}

    else if(numVida==3){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("3");}

    else if(numVida==2){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("2");}

    else if(numVida==1){
    tft.setTextColor(MAGENTA);
    tft.setTextSize(8);
    tft.setCursor(370, 185);
    tft.print("1");}
    
}
void drawDamageScreen(){
      //PARPADEO DAMAGE
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, RED);
      tft.setTextColor(WHITE);
      tft.setTextSize(8);
      tft.setCursor(95, 120);
      tft.print("DAMAGE");
      delay(500);
      tft.fillScreen(BLACK);
      delay(500);
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, RED);
      tft.setTextColor(WHITE);
      tft.setTextSize(8);
      tft.setCursor(95, 120);
      tft.print("DAMAGE");
      delay(500);

      drawInGameScreen();
}

void drawGameOverScreen(){
      //GAME OVER
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, RED);
      tft.setTextColor(WHITE);
      tft.setTextSize(7);
      tft.setCursor(45, 120);
      tft.print("Game Over!");
      delay(500);
      tft.fillScreen(BLACK);
      delay(500);
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, RED);
      tft.setTextColor(WHITE);
      tft.setTextSize(7);
      tft.setCursor(45, 120);
      tft.print("Game Over!");
      delay(500);
      tft.fillScreen(BLACK);
      delay(500);
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, RED);
      tft.setTextColor(WHITE);
      tft.setTextSize(7);
      tft.setCursor(45, 120);
      tft.print("Game Over!");
      delay(500);

      reset();
    }

void drawVictoryScreen(){
      tft.fillScreen(BLACK);
      tft.fillRect(0, 100, 480, 100, GREEN);
      tft.setTextColor(WHITE);
      tft.setTextSize(7);
      tft.setCursor(70, 120);
      tft.print("VICTORY");
      delay(2000);

      reset();
    }

void reset(){
  wdt_enable(WDTO_15MS);
  while(1){};
}
