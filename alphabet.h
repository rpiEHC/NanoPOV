#include "Arduino.h"

#define LENGTH 7

char * stringToByte(char * L1, char * L2, char * L3, char * L4, char * L5, char * L6, char * L7, char * L8) {
  char * returnValue = (char *) malloc (LENGTH*sizeof(char));
  for (int i = 0; i < LENGTH; i++) {
    returnValue[i] = ((L1[i]==' '?0:1) << 0 |
                      (L2[i]==' '?0:1) << 1 |
                      (L3[i]==' '?0:1) << 2 |
                      (L4[i]==' '?0:1) << 3 |
                      (L5[i]==' '?0:1) << 4 |
                      (L6[i]==' '?0:1) << 5 |
                      (L7[i]==' '?0:1) << 6 |
                      (L8[i]==' '?0:1) << 7);

  }
  return returnValue;
}

void loadAlphabet(char ** &letters) {
  letters = (char **) malloc (128 * sizeof(char **) );
  
  
  
  letters['#'] = stringToByte("#######",
                              "#######",
                              "#######",
                              "#######",
                              "#######",
                              "#######",
                              "#######",
                              "#######");
  
  letters[' '] = stringToByte("       ",
                              "       ",
                              "       ",
                              "       ",
                              "       ",
                              "       ",
                              "       ",
                              "       ");
  
  letters['A'] = stringToByte("   #   ",
                              "  ###  ",
                              " #   # ",
                              "#     #",
                              "#######",
                              "#     #",
                              "#     #",
                              "#     #");
                              
  letters['B'] = stringToByte("#####  ",
                              "#    # ",
                              "#    # ",
                              "#####  ",
                              "#    # ",
                              "#     #",
                              "#     #",
                              "###### ");
                              
  letters['C'] = stringToByte("  #####",
                              " #     ",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#      ",
                              " #     ",
                              "  #####");
                              
  letters['D'] = stringToByte("#####  ",
                              "#    # ",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#    # ",
                              "#####  ");
                              
  letters['E'] = stringToByte("#######",
                              "#      ",
                              "#      ",
                              "#######",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#######");
                              
  letters['F'] = stringToByte("#######",
                              "#      ",
                              "#      ",
                              "#######",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#      ");
                              
  letters['G'] = stringToByte("  #####",
                              " #     ",
                              "#      ",
                              "#      ",
                              "#   ###",
                              "#     #",
                              " #    #",
                              "  #####");
                              
  letters['H'] = stringToByte("#     #",
                              "#     #",
                              "#     #",
                              "#######",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #");
                              
  letters['I'] = stringToByte("#######",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "#######");
                              
  letters['J'] = stringToByte("#######",
                              "     # ",
                              "     # ",
                              "     # ",
                              "     # ",
                              "#    # ",
                              " #   # ",
                              "  ###  ");
                              
  letters['K'] = stringToByte("#    # ",
                              "#   #  ",
                              "#  #   ",
                              "# #    ",
                              "#  #   ",
                              "#   #  ",
                              "#    # ",
                              "#     #");
                              
  letters['L'] = stringToByte("#      ",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#      ",
                              "#######");
                              
  letters['M'] = stringToByte("#     #",
                              "##   ##",
                              "# # # #",
                              "#  #  #",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #");
                              
  letters['N'] = stringToByte("#     #",
                              "##    #",
                              "# #   #",
                              "#  #  #",
                              "#  #  #",
                              "#   # #",
                              "#    ##",
                              "#     #");
                              
  letters['O'] = stringToByte("  ###  ",
                              " #   # ",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              " #   # ",
                              "  ###  ");
                              
  letters['P'] = stringToByte("#####  ",
                              "#    # ",
                              "#     #",
                              "#    # ",
                              "####   ",
                              "#      ",
                              "#      ",
                              "#      ");
                              
  letters['Q'] = stringToByte("  ###  ",
                              " #   # ",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              " #   # ",
                              "  ### #");
                              
  letters['R'] = stringToByte("#####  ",
                              "#    # ",
                              "#     #",
                              "#    # ",
                              "####   ",
                              "#   #  ",
                              "#    # ",
                              "#     #");
                              
  letters['S'] = stringToByte("  #####",
                              " #     " ,
                              "#      ",
                              " ####  ",
                              "     # ",
                              "      #",
                              "     # ",
                              "#####  ");
                              
  letters['T'] = stringToByte("#######",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ");
                            
  letters['U'] = stringToByte("#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              "#     #",
                              " #   # ",
                              "  ###  ");
                              
  letters['V'] = stringToByte("#     #",
                              "#     #",
                              " #   # ",
                              " #   #",
                              "  # #  ",
                              "  # #  ",
                              "   #   ",
                              "   #   ");
                              
  letters['W'] = stringToByte("#     #",
                              "#  #  #",
                              "#  #  #",
                              "#  #  #",
                              "#  #  #",
                              "#  #  #",
                              "# # # #",
                              " #   # ");
                              
  letters['X'] = stringToByte("#     #",
                              " #   # ",
                              "  # #  ",
                              "   #   ",
                              "   #   ",
                              "  # #  ",
                              " #   # ",
                              "#     #");
                              
  letters['Y'] = stringToByte("#     #",
                              " #   # ",
                              "  # #  ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ",
                              "   #   ");
                              
  letters['Z'] = stringToByte("#######",
                              "     ##",
                              "    ## ",
                              "   ##  ",
                              "  ##   ",
                              " ##    ",
                              "##     ",
                              "#######");
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
}
