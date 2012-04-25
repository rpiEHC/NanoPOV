#define blue1 3
#define green1 4
#define red1 5
#define center_common 6
#define outer_center_common 7
#define inner_outer_common 8
#define outer_common 9
#define red2 10
#define green2 11
#define blue2 12

#include "alphabet.h"

char ** alphabet;

#define COMMON_VALUE 0x00
#define UNIQUE_VALUE 0xFF
//0xFF is used instead of HIGH (0x01) to provide a speedup when displaying

#define ON 0xff
#define OFF 0x00


void setup () {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
  //set all of the ascii values
  loadAlphabet(alphabet);
}

void loop() {
  displayString("GO ",ON,ON,ON);
  displayString("RED  ",ON,OFF,OFF);
}

void displayLetter(char letter, char RED, char GREEN, char BLUE) {
  for (int i = 0; i < 7; i ++) {
    displayByte (alphabet[letter][i] & RED, alphabet[letter][i] & BLUE, alphabet[letter][i] & GREEN);
  }
  displayByte (0,0,0);
}

void displayByte(char red, char blue, char green) {
  
  digitalWrite(center_common, UNIQUE_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  
  digitalWrite (center_common, COMMON_VALUE);
  digitalWrite (blue1 , UNIQUE_VALUE & blue  & 0x08);
  delay(0);
  digitalWrite (blue1 , COMMON_VALUE);
  digitalWrite (green1, UNIQUE_VALUE & green & 0x08);
  delay(0);
  digitalWrite (green1, COMMON_VALUE);
  digitalWrite (red1,   UNIQUE_VALUE & red   & 0x08);
  delay(0);
  digitalWrite (red1,   COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
  
  digitalWrite (outer_center_common, COMMON_VALUE);
  digitalWrite (blue1,  UNIQUE_VALUE & blue  & 0x04);
  delay(0);
  digitalWrite (blue1,  COMMON_VALUE);
  digitalWrite (green1, UNIQUE_VALUE & green & 0x04);
  delay(0);
  digitalWrite (green1, COMMON_VALUE); 
  digitalWrite (red1,   UNIQUE_VALUE & red   & 0x04);
  
  digitalWrite (red1,   COMMON_VALUE);
  digitalWrite (outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(blue1,  UNIQUE_VALUE & blue & 0x02);
  delay(0);
  digitalWrite(blue1,  COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE & green & 0x02);
  delay(0);
  digitalWrite(green1, COMMON_VALUE);
  digitalWrite(red1,   UNIQUE_VALUE & red & 0x02);
  delay(0);
  digitalWrite(red1,   COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(blue1, UNIQUE_VALUE & blue & 0x01);
  delay(0);
  digitalWrite(blue1, COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE & green & 0x01);
  delay(0);
  digitalWrite(green1, COMMON_VALUE);
  digitalWrite(red1, UNIQUE_VALUE & red & 0x01);
  delay(0);
  digitalWrite(red1, COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
    
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(blue2,  UNIQUE_VALUE & blue & 0x80);
  delay(0);
  digitalWrite(blue2,  COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE & green & 0x80);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2,   UNIQUE_VALUE & red & 0x80);
  delay(0);
  digitalWrite(red2,   COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(blue2,  UNIQUE_VALUE & blue & 0x40);
  delay(0);
  digitalWrite(blue2,  COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE & green & 0x40);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2,   UNIQUE_VALUE & red & 0x40);
  delay(0);
  digitalWrite(red2,   COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_center_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE & blue & 0x20);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE & green & 0x20);
  delay(0);
  digitalWrite(green2, COMMON_VALUE); 
  digitalWrite(red2, UNIQUE_VALUE & red & 0x20);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(center_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE & blue & 0x10);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE & green & 0x10);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2, UNIQUE_VALUE & red & 0x10);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
}

void displayString (String displayString, char RED, char GREEN, char BLUE) {
  for (int i = 0; i < displayString.length(); i++) {
    displayLetter(displayString[i],RED,GREEN,BLUE);
  }
}
