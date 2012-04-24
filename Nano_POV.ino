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
char ** displayString;

#define COMMON_VALUE 0x00
#define UNIQUE_VALUE 0xFF
//0xFF is used instead of HIGH (0x01) to provide a speedup when displaying

void testLeds () {
  digitalWrite(center_common, UNIQUE_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  
  digitalWrite(center_common, COMMON_VALUE);
  
  digitalWrite(blue1, UNIQUE_VALUE );
  delay(0);
  digitalWrite(blue1, COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green1, COMMON_VALUE);
  digitalWrite(red1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red1, COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
  
  digitalWrite(outer_center_common, COMMON_VALUE);
  digitalWrite(blue1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue1, COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green1, COMMON_VALUE); 
  digitalWrite(red1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red1, COMMON_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(blue1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue1, COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green1, COMMON_VALUE);
  digitalWrite(red1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red1, COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(blue1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue1, COMMON_VALUE);
  digitalWrite(green1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green1, COMMON_VALUE);
  digitalWrite(red1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red1, COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  
  
  
  
  
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_center_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green2, COMMON_VALUE); 
  digitalWrite(red2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(center_common, COMMON_VALUE);
  digitalWrite(blue2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(blue2, COMMON_VALUE);
  digitalWrite(green2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(green2, COMMON_VALUE);
  digitalWrite(red2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(red2, COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
}

int color1 = red1;
int color2 = red2;
int backup1 = blue1;
int backup2 = blue2;

void testLeds2 () {
  if (analogRead(0)>500 && analogRead(1) < 500) {
    color1 = red1;
    color2 = red2;
  }
  else if (analogRead(0)>500 && analogRead(1) > 500) {
    color1 = green1;
    color2 = green2;
  }
  else {
    color1 = blue1;
    color2 = blue2;
  }
  
  
  digitalWrite(center_common, UNIQUE_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  
  digitalWrite(center_common, COMMON_VALUE);
  digitalWrite(color1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color1, COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
  
  digitalWrite(outer_center_common, COMMON_VALUE);
  digitalWrite(color1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color1, COMMON_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(color1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color1, COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(color1, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color1, COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);  
  
  digitalWrite(outer_common, COMMON_VALUE);
  digitalWrite(color2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color2, COMMON_VALUE);
  digitalWrite(outer_common, UNIQUE_VALUE);
  
  digitalWrite(inner_outer_common, COMMON_VALUE);
  digitalWrite(color2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color2, COMMON_VALUE);
  digitalWrite(inner_outer_common, UNIQUE_VALUE);
  
  digitalWrite(outer_center_common, COMMON_VALUE); 
  digitalWrite(color2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color2, COMMON_VALUE);
  digitalWrite(outer_center_common, UNIQUE_VALUE);
  
  digitalWrite(center_common, COMMON_VALUE);
  digitalWrite(color2, UNIQUE_VALUE);
  delay(0);
  digitalWrite(color2, COMMON_VALUE);
  digitalWrite(center_common, UNIQUE_VALUE);
}


void setup () {
  Serial.begin(19200);
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
  displayString = (char **) malloc (256 * sizeof(char **));
  
  // 128 
  //set all of the ascii values
  loadAlphabet(alphabet);
  Serial.begin(9600);
  Serial.println((int) alphabet['#'][0]);
}

void displayLetter(char letter) {
  displayByte (alphabet[letter][0],alphabet[letter][0],alphabet[letter][0]);
  displayByte (alphabet[letter][1],alphabet[letter][1],alphabet[letter][1]);
  displayByte (alphabet[letter][2],alphabet[letter][2],alphabet[letter][2]);
  displayByte (alphabet[letter][3],alphabet[letter][3],alphabet[letter][3]);
  displayByte (alphabet[letter][4],alphabet[letter][4],alphabet[letter][4]);
  displayByte (alphabet[letter][5],alphabet[letter][5],alphabet[letter][5]);
  displayByte (alphabet[letter][6],alphabet[letter][6],alphabet[letter][6]);
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

void loop() {
  // begin from the middle
  //testLeds();
  displayLetter(' ');
  displayLetter(' ');
  displayLetter('K');
  displayLetter('E');
  displayLetter('V');
  displayLetter('I');
  displayLetter('N');
  
  /*Serial.print(LOW);
  Serial.print(" - ");
  Serial.println(analogRead(1));/**/
  
  // normal is 0 = >500   1 < 500
}
