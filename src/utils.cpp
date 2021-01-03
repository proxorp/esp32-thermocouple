#include <Arduino.h>
#include "utils.h"

float Celcius2Farenheit(float tempC) {
  return( (tempC*1.8)+32);
}


void binprint(unsigned long value, int bits) {
  // Serial.println();  
  // Serial.println(value,HEX);
  // Serial.println();  
  for(int i=bits;i>0;i--) {
    Serial.print( ((value >> ((i-1)) ) & 0x1) );
  }
}

// Print the full nibbles of a hex value
void hexprint(unsigned long value, int nibbles) {
  // Serial.println();  
  // Serial.println(value,HEX);
  // Serial.println();  
  for(int i=nibbles;i>0;i--) {
    Serial.print( (value >> ((i-1)*4) ) & 0xF,HEX );
  }
}

int digitCount(int value) {
  int total=0;
  while (value!=0) {
    total++;
    value=value/10;
  }
  return total;
}