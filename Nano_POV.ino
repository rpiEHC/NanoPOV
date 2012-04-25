/******************************************************************************\
|                                     ,,                                       |
|                    db             `7MM                                       |
|                   ;MM:              MM                                       |
|                  ,V^MM.    ,pP"Ybd  MMpMMMb.  .gP"Ya `7Mb,od8                |
|                 ,M  `MM    8I   `"  MM    MM ,M'   Yb  MM' "'                |
|                 AbmmmqMA   `YMMMa.  MM    MM 8M""""""  MM                    |
|                A'     VML  L.   I8  MM    MM YM.    ,  MM                    |
|              .AMA.   .AMMA.M9mmmP'.JMML  JMML.`Mbmmd'.JMML.                  |
|                                                                              |
|                                                                              |
|                                ,,    ,,                                      |
|                     .g8"""bgd `7MM    db        `7MM                         |
|                   .dP'     `M   MM                MM                         |
|                   dM'       `   MM  `7MM  ,p6"bo  MM  ,MP'                   |
|                   MM            MM    MM 6M'  OO  MM ;Y                      |
|                   MM.    `7MMF' MM    MM 8M       MM;Mm                      |
|                   `Mb.     MM   MM    MM YM.    , MM `Mb.                    |
|                     `"bmmmdPY .JMML..JMML.YMbmd'.JMML. YA.                   |
|                                                                              |
\******************************************************************************/
/******************************************************************************\
| Copyright (c) 2012, Asher Glick                                              |
| All rights reserved.                                                         |
|                                                                              |
| Redistribution and use in source and binary forms, with or without           |
| modification, are permitted provided that the following conditions are met:  |
|                                                                              |
| * Redistributions of source code must retain the above copyright notice,     |
|   this list of conditions and the following disclaimer.                      |
| * Redistributions in binary form must reproduce the above copyright notice,  |
|   this list of conditions and the following disclaimer in the documentation  |
|   and/or other materials provided with the distribution.                     |
|                                                                              |
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  |
| AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    |
| IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   |
| ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    |
| LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          |
| CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         |
| SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     |
| INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      |
| CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      |
| ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   |
| POSSIBILITY OF SUCH DAMAGE.                                                  |
\******************************************************************************/
#define blue1 3
#define green1 4
#define red1 5

//#define center_common 6
#define INNER_CENTER_COMMON_PIN 6

//#define outer_center_common 7
#define OUTER_CENTER_COMMON_PIN 7

//#define inner_outer_common 8
#define INNER_EDGE_COMMON_PIN 8

//#define outer_common 9
#define OUTER_EDGE_COMMON_PIN 9

#define red2 10
#define green2 11
#define blue2 12

#include "alphabet.h"

char ** alphabet;

//#define COMMON_VALUE 0x00

#define COMMON_ON 0x00
#define COMMON_OFF 0xFF

//#define UNIQUE_VALUE 0xFF
#define COLOR_ON 0xFF
#define COLOR_OFF 0x00
//0xFF is used instead of HIGH (0x01) to provide a speedup when displaying

#define ON 0xff
#define OFF 0x00

#define LED_ON_TIME 250

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
  
  digitalWrite(INNER_CENTER_COMMON_PIN, COMMON_OFF);
  digitalWrite(OUTER_CENTER_COMMON_PIN, COMMON_OFF);
  digitalWrite(INNER_EDGE_COMMON_PIN,   COMMON_OFF);
  digitalWrite(OUTER_EDGE_COMMON_PIN,   COMMON_OFF);
  
  
  digitalWrite (INNER_CENTER_COMMON_PIN, COMMON_ON);
  digitalWrite (blue1 , COLOR_ON & blue  & 0x08);
  digitalWrite (green1, COLOR_ON & green & 0x08);
  digitalWrite (red1,   COLOR_ON & red   & 0x08);
  digitalWrite (blue2,  COLOR_ON & blue & 0x10);
  digitalWrite (green2, COLOR_ON & green & 0x10);
  digitalWrite (red2,   COLOR_ON & red & 0x10);
  delayMicroseconds(LED_ON_TIME);
  digitalWrite (blue1 , COLOR_OFF);
  digitalWrite (green1, COLOR_OFF);
  digitalWrite (red1,   COLOR_OFF);
  digitalWrite (blue2,  COLOR_OFF);
  digitalWrite (green2, COLOR_OFF);
  digitalWrite (red2,   COLOR_OFF);
  digitalWrite (INNER_CENTER_COMMON_PIN, COMMON_OFF);
  
  digitalWrite (OUTER_CENTER_COMMON_PIN, COMMON_ON);
  digitalWrite (blue1,  COLOR_ON & blue  & 0x04);
  digitalWrite (green1, COLOR_ON & green & 0x04);
  digitalWrite (red1,   COLOR_ON & red   & 0x04);
  digitalWrite(blue2,  COLOR_ON & blue & 0x20);
  digitalWrite(green2, COLOR_ON & green & 0x20);
  digitalWrite(red2,   COLOR_ON & red & 0x20);
  delayMicroseconds(LED_ON_TIME);
  digitalWrite (blue1,  COLOR_OFF);
  digitalWrite (green1, COLOR_OFF);  
  digitalWrite (red1,   COLOR_OFF);
  digitalWrite(blue2,  COLOR_OFF);
  digitalWrite(green2, COLOR_OFF); 
  digitalWrite(red2,   COLOR_OFF);
  digitalWrite (OUTER_CENTER_COMMON_PIN, COMMON_OFF);
  
  digitalWrite(INNER_EDGE_COMMON_PIN, COMMON_ON);
  digitalWrite(blue1,  COLOR_ON & blue & 0x02);
  digitalWrite(green1, COLOR_ON & green & 0x02);
  digitalWrite(red1,   COLOR_ON & red & 0x02);
  digitalWrite(blue2,  COLOR_ON & blue & 0x40);
  digitalWrite(green2, COLOR_ON & green & 0x40);
  digitalWrite(red2,   COLOR_ON & red & 0x40);
  delayMicroseconds(LED_ON_TIME);
  digitalWrite(blue1,  COLOR_OFF);
  digitalWrite(green1, COLOR_OFF);
  digitalWrite(red1,   COLOR_OFF);
  digitalWrite(blue2,  COLOR_OFF);
  digitalWrite(green2, COLOR_OFF);
  digitalWrite(red2,   COLOR_OFF);
  digitalWrite(INNER_EDGE_COMMON_PIN, COMMON_OFF);
  
  digitalWrite(OUTER_EDGE_COMMON_PIN, COMMON_ON);
  digitalWrite(blue1, COLOR_ON & blue & 0x01);
  digitalWrite(green1, COLOR_ON & green & 0x01);
  digitalWrite(red1, COLOR_ON & red & 0x01);
  digitalWrite(blue2,  COLOR_ON & blue & 0x80);
  digitalWrite(green2, COLOR_ON & green & 0x80);
  digitalWrite(red2,   COLOR_ON & red & 0x80);
  delayMicroseconds(LED_ON_TIME);
  digitalWrite(blue1, COLOR_OFF);
  digitalWrite(green1, COLOR_OFF);
  digitalWrite(red1, COLOR_OFF);
  digitalWrite(blue2,  COLOR_OFF);
  digitalWrite(green2, COLOR_OFF);
  digitalWrite(red2,   COLOR_OFF);
  digitalWrite(OUTER_EDGE_COMMON_PIN, COMMON_OFF);
}

void displayString (String displayString, char RED, char GREEN, char BLUE) {
  for (int i = 0; i < displayString.length(); i++) {
    displayLetter(displayString[i],RED,GREEN,BLUE);
  }
}
