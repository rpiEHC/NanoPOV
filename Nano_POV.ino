#define LENGTH 7


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
String displayString;

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
  
  
  // while this is not the most effecient way to write this program it is the most configurable
  // it could all be created without using any ram and the conversion statement could be done compleetely as
  // a switch statement in flash. However that would require the letters to be compiled beforehand, that might be ok
  
  // if every ascii value is set using 
  
  // the length is 256 so it can be stored in a char and edited in one byte
  //displayString = (char **) malloc (256 * sizeof(char **));
  
  //set all of the ascii values
  loadAlphabet(alphabet);
  
  displayString = "GO RED    ";
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
  delay(0);
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

void displayString (String words, char RED, char GREEN, char BLUE) {
  for (int i = 0; i < displayString.length(); i++) {
    displayLetter(displayString[i],0xFF,0,0xFF);
  }
}

void loop() {
  
}
