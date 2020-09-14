#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "I2CIO.h"

#define I2C_LCDA 0x27
#define I2C_LCDB 0x23
#define Rs_pin 0
#define Rw_pin 1
#define En_pin 2
#define BACKLIGHT_PIN 3
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcdA(I2C_LCDA, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
LiquidCrystal_I2C lcdB(I2C_LCDB, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

char AL0[20];
char AL1[20];
char AL2[20];
char AL3[20];
char BL0[20];
char BL1[20];
char BL2[20];
char BL3[20];


void setup() {
  Serial.begin(9600);
  Serial.print("ON");
  
  lcdA.begin(20, 4); // 20 characters by 4 rows
  lcdA.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcdA.setBacklight(HIGH);

  lcdA.home();

  lcdB.begin(20, 4); // 20 characters by 4 rows
  lcdB.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcdB.setBacklight(HIGH);

  lcdB.home();
}

void blankLCD(char lcd) {
  if (lcd == 'A' || lcd == '2') {
    lcdA.setCursor(0, 0);
    for (int i = 0; i < 5; i++) {
      lcdA.print("                    ");
    }
  }
  if (lcd == 'B' || lcd == '2') {
    lcdB.setCursor(0, 0);
    for (int i = 0; i < 5; i++) {
      lcdB.print("                    ");
    }
  }
}

void printToLCDA(char L0[20], char L1[20], char L2[20], char L3[20], int cntr) {
  blankLCD('A');
  lcdA.setCursor(0, 0);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L0)) / 2; i++) {
      lcdA.print(" ");
    }
  }
  lcdA.print(L0);
  lcdA.setCursor(0, 1);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L1)) / 2; i++) {
      lcdA.print(" ");
    }
  }
  lcdA.print(L1);
  lcdA.setCursor(0, 2);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L2)) / 2; i++) {
      lcdA.print(" ");
    }
  }
  lcdA.print(L2);
  lcdA.setCursor(0, 3);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L3)) / 2; i++) {
      lcdA.print(" ");
    }
  }
  lcdA.print(L3);
}

void printToLCDB(char L0[20], char L1[20], char L2[20], char L3[20], int cntr) {
  blankLCD('B');
  lcdB.setCursor(0, 0);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L0)) / 2; i++) {
      lcdB.print(" ");
    }
  }
  lcdB.print(L0);
  lcdB.setCursor(0, 1);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L1)) / 2; i++) {
      lcdB.print(" ");
    }
  }
  lcdB.print(L1);
  lcdB.setCursor(0, 2);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L2)) / 2; i++) {
      lcdB.print(" ");
    }
  }
  lcdB.print(L2);
  lcdB.setCursor(0, 3);
  if (cntr == 1) {
    for (int i = 0; i < (20 - strlen(L3)) / 2; i++) {
      lcdB.print(" ");
    }
  }
  lcdB.print(L3);
}

void pause() {
  lcdB.setCursor(0, 3);
    for (int i = 5; i >= 0; i--) {
      char buffer[2];
      snprintf(buffer, 2, "%d", i);
      lcdB.setCursor(0, 3);
	  for (int i = 0; i < 19; i++) {
		lcdB.print(" ");  
	  }
      lcdB.print(buffer);
      delay(1000);
      if (Serial.available()) { break; }
    }
}

void cycleLCDB(char L0[20], char L1[20], char L2[20], char L3[20], char L4[20], char L5[20], char L6[20], char L7[20], char L8[20], char L9[20], char L10[20], char L11[20], char L12[20], char L13[20], char L14[20], char L15[20], int cntr) {
	while (!Serial.available()) {
		printToLCDB(L0, L1, L2, L3, cntr);
		pause();
		if (Serial.available()) { break; }
		printToLCDB(L4, L5, L6, L7, cntr);
		pause();
		if (Serial.available()) { break; }
		printToLCDB(L8, L9, L10, L11, cntr);
		pause();
		if (Serial.available()) { break; }
		printToLCDB(L12, L13, L14, L15, cntr);
		pause();
		if (Serial.available()) { break; }
	}
}

void loop() {
  printToLCDA("Test", " ", " ", "0x27", 0);
  cycleLCDB("L0", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "L10", "L11", "L12", "L13", "L14", "L15", 0);
}
















