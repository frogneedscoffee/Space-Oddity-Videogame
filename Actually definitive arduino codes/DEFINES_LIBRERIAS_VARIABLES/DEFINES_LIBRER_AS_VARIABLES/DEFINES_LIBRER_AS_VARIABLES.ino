//--------LIBRERÍAS--------
#include <avr/wdt.h> //libreria del watchdog
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <Adafruit_TFTLCD.h>
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//--------COLORES--------
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define VIOLET 0xB527E1

//--------PINES--------
//TFT
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

//ULTRASONIDOS
#define EchoPin 53
#define TriggerPin 51

//LED
#define pinR 49
#define pinG 47
#define pinB 45

//MOTOR
#define MOTOR 43

//--------VARIABLES--------
String currentPage;
String Lectura = "";
int numVida = 7;
