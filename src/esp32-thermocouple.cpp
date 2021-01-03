//=====================================================================================
// ESP32 - Thermocouple Test 
//
// This tests the reading of the MAX31855 thermocouple chip via SPI interface.
// Results are shown on the serial output.
//
//=====================================================================================
#include <Arduino.h>
#include "pinout.h"
// #include "utils.h"
#include <thermocouple.h>   // my own thermocouple lib, see lib_extr_dirs in platformio.ini

//--------------------------------------------------
// Uncomment to disable serial output
// #define USE_SERIAL

//---------------------------------------------------
// Comment out the folowing to remove LCD support
#define USE_LCD
//
#ifdef USE_LCD
#include <U8g2lib.h>
  uint8_t fontMode=0;
  uint8_t drawMode=1;

// Create the LCD object 
// U8G2_ST7920_128X64_F_SW_SPI lcd(U8G2_R0, LCD_PIN_CLK, LCD_PIN_DATA, LCD_PIN_RS, U8X8_PIN_NONE);
U8G2_ST7920_128X64_F_HW_SPI lcd(U8G2_R0, LCD_PIN_RS);
#endif


thermocouple tc0( thermocouple::MAX81355, pinTempClock,pinTempCS0,pinTempData );
thermocouple tc1( thermocouple::MAX81355, pinTempClock,pinTempCS1,pinTempData );
// thermocouple tc(thermocouple::MAX6675, pinTempClock,pinTempCS0,pinTempData);
// 
// Initialize 


void setup(void) {

//   pinMode(pinTempClock, INPUT_PULLUP);       //
//   pinMode(pinTempCS0, INPUT_PULLUP);   
//   pinMode(pinTempCS1, INPUT_PULLUP);   
//   // pinMode(data, INPUT_PULLUP);  //
//   pinMode(pinTempData, INPUT_PULLUP);  //  
// while(1);
  tc0.begin();  // Enable the thermocouple pins
  tc1.begin();  // Enable the thermocouple pins
  #ifdef USE_SERIAL
  Serial.begin(9600);         // open the serial port at 9600 bps:  
  Serial.print("\nSerial connection established.\n");
  Serial.printf("Sensor Type:  %i\n",tc.getSensorType() );
  #endif

  #ifdef USE_LCD
  lcd.begin();
  lcd.setFontMode(fontMode);
  lcd.setDrawColor(drawMode);     
  lcd.clearBuffer();
  // lcd.setFont(u8g2_font_6x10_mf);  
  lcd.setFont(u8g2_font_5x7_mf);    
  // lcd.setFont(u8g2_font_u8glib_4_tf);
  lcd.clear();
  #endif


}


void loop(void) {
  char buffer[50];
  int tc_status0, tc_status1;
  int16_t tempC0, tempF0, intC0;
  int16_t tempC1, tempF1, intC1;
  tc_status0=tc0.read();
  tc_status1=tc1.read();  

  tempC0=tc0.getTempC(); tempF0=tc0.getTempF(); intC0=tc0.getInternalC();
  tempC1=tc1.getTempC(); tempF1=tc1.getTempF(); intC1=tc1.getInternalC();    

  // // Read the MAX chip
  // if( !(tc_status=tc.read()) ){
  //   // MAX chip read successful, so print temp values.
  //   // Serial.print( (float)((int)tc_raw<<4),1);

  //   tempC0=tc0.getTempC(); tempF0=tc0.getTempF(); intC0=tc0.getInternalC();
  //   tempC1=tc1.getTempC(); tempF1=tc1.getTempF(); intC1=tc1.getInternalC();    
  //   #ifdef USE_SERIAL    
  //   Serial.printf("[%iF / %iC] -- Raw: % 8lX Err: %1X InternalC: 0x%X|%i TempC: 0x%X|%i TempF: %i       \r",
  //       tempF,tempC,        
  //       tc.getRaw(),tc.getErr(), 
  //       tc.getInternalC(), tc.getInternalC(),tc.getTempC(), tc.getTempC(), tc.getTempF() );
  //   #endif
  // } else {
  //   #ifdef USE_SERIAL
  //   // MAX chip read problem.  Print the error.
  //   Serial.print("Error! "); Serial.print(tc_status,DEC);  Serial.flush();
  //   #endif    
  // }
  // Serial.print(" ");

  #ifdef USE_LCD
  int8_t height=lcd.getMaxCharHeight();
  int8_t row=1;
  lcd.setCursor(0,row++*height); lcd.printf("ID# :     0 |   1 ");
  lcd.setCursor(0,row++*height); lcd.printf("TempF: % 4iF|% 4iF"  ,tempF0,tempF1 );
  lcd.setCursor(0,row++*height); lcd.printf("TempC: % 4iC|% 4iC  ",tempC0,tempC1 );  
  lcd.setCursor(0,row++*height); lcd.printf("IntT:  % 4iC|% 4iC  ", intC0, intC1 );    
  lcd.setCursor(0,row++*height); lcd.printf("Stat:     %1x |   %1x ", tc0.getErr(),tc1.getErr()  );      
  lcd.setCursor(0,64-height);    lcd.printf("IntT:   % 4X|% 4X  ", intC0, intC1 );    
  lcd.setCursor(0,64);           lcd.printf("RAW:%8X|% 8X", tc0.getRaw(), tc1.getRaw()  );      
  lcd.sendBuffer();  
  #endif


  delay(1000);
}