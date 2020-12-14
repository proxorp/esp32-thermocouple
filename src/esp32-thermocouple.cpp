//=====================================================================================
// ESP32 - Thermocouple Test 
//
// This tests the reading of the MAX31855 thermocouple chip via SPI interface.
// Results are shown on the serial output.
//
//=====================================================================================
#include <Arduino.h>
#include "pinout.h"
#include "utils.h"
#include "thermocouple.h"

// thermocouple tc( thermocouple::MAX81355, pinTempClock,pinTempCS0,pinTempData );
thermocouple tc(thermocouple::MAX6675, pinTempClock,pinTempCS0,pinTempData);

// Initialize 
void setup(void) {
  Serial.begin(9600);         // open the serial port at 9600 bps:  
  Serial.print("Serial connection established.\n");
  tc.begin();  // Enable the thermocouple pins
}


void loop(void) {
  char buffer[50];
  int tc_status;
  // Read the MAX chip
  if( !(tc_status=tc.read()) ){
    // MAX chip read successful, so print temp values.
    // Serial.print( (float)((int)tc_raw<<4),1);
    sprintf(buffer,"0x%4X|%i ",tc.getTempC(), tc.getTempC());  Serial.print(buffer);
  } else {
    // MAX chip read problem.  Print the error.
    Serial.print("Error! "); Serial.print(tc_status,DEC);
  }
  Serial.print(" ");
  delay(1000);
}
