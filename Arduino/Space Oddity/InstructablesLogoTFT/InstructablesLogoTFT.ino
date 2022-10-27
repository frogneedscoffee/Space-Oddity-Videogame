// CreaTechWeb : Displaying an image on a TFT screen with arduino

// https://createchweb.com/displaying-an-image-on-a-tft-screen-with-arduino/

// include the necessary libraries
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

// pin definition for the Uno
#define sd_cs  10
#define lcd_cs A3
#define dc     4
#define rst    A4
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define id "0x9486"

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1

TFT TFTscreen = TFT(lcd_cs, dc, rst);

// this variable represents the image to be drawn on screen
PImage logo;


void setup() {
  // initialize the GLCD and show a message
  // asking the user to open the serial line
  tft.begin(id);
  tft.setRotation(3);
  TFTscreen.background(255, 255, 255);

  TFTscreen.stroke(0, 0, 255);
  TFTscreen.println();
  TFTscreen.println(F("Arduino TFT Bitmap Example"));
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.println(F("Open serial monitor"));
  TFTscreen.println(F("to run the sketch"));

  // initialize the serial port: it will be used to
  // print some diagnostic info
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }

  // clear the GLCD screen before starting
  TFTscreen.background(255, 255, 255);

  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(sd_cs)) {
    Serial.println(F("failed!"));
    return;
  }
  Serial.println(F("OK!"));

  // initialize and clear the GLCD screen
  TFTscreen.begin(0x9486);
  TFTscreen.background(255, 255, 255);

  // now that the SD card can be access, try to load the
  // image file.
  logo = TFTscreen.loadImage("Logo Space Oddity.bmp");
  if (!logo.isValid()) {
    Serial.println(F("error while loading arduino.bmp"));
  }
}

void loop() {
  // don't do anything if the image wasn't loaded correctly.
  if (logo.isValid() == false) {
    return;
  }

  Serial.println(F("drawing image"));

  // get a random location where to draw the image.
  // To avoid the image to be draw outside the screen,
  // take into account the image size.
  int x = random(TFTscreen.width() - logo.width());
  int y = random(TFTscreen.height() - logo.height());

  // draw the image to the screen
  TFTscreen.image(logo, x, y);

  // wait a little bit before drawing again
  delay(1500);
}
