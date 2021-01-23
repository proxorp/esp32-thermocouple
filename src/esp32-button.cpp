//=====================================================================================
// ESP32 - Button Test 
//
// This tests the Button class for reading hardware buttons (switches).
//
//=====================================================================================
#include <Arduino.h>
#include "pinout.h"
// #include "utils.h"
#include <Button.h>   // my own thermocouple lib, see lib_extr_dirs in platformio.ini

Button btnObj(encBtn,0);
Button killObj(KILL_PIN,0);


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



void setup(void) {

  // Enable sensing of the kill pin as a pause button.
  // pinMode(KILL_PIN, INPUT_PULLUP);       //



  #ifdef USE_LCD
  lcd.begin();
  lcd.setFontMode(fontMode);
  lcd.setDrawColor(drawMode);     
  lcd.clearBuffer();
  // lcd.setFont(u8g2_font_6x10_mf);  
  lcd.setFont(u8g2_font_5x7_mf);    
  // lcd.setFont(u8g2_font_u8glib_4_tf);
  lcd.clear();
  lcd.sendBuffer();
  #endif
}


int loopcount=0;

void loop(void) {
  loopcount%=10;
  lcd.clearBuffer();  
  btnObj.readState();
  killObj.readState();

  #ifdef USE_LCD
  int8_t height=lcd.getMaxCharHeight();
  int8_t row=1;
  lcd.setCursor(0,row++*height); lcd.printf("Btn : V | S | T | D | L |");
  lcd.setCursor(0,row++*height); lcd.printf("Rbtn: %1i | %1i | %1i | %1i | %1i |"  ,
      btnObj.getValue(),btnObj.getState(),btnObj.getToggleState(),btnObj.getMultiState(),btnObj.getLongState() );  
  lcd.setCursor(0,row++*height); lcd.printf("Kbtn: %1i | %1i | %1i | %1i | %1i |"  ,
      killObj.getValue(),killObj.getState(),killObj.getToggleState(), killObj.getMultiState(), killObj.getLongState() );
  lcd.setCursor(0,row++*height); lcd.printf("Rbtn: %1X Kbtn: %1X",btnObj.getStates(), killObj.getStates() );  
  // lcd.setCursor(0,row++*height); lcd.printf("IntT:  % 4iC|% 4iC  ", intC0, intC1 );       
  // lcd.setCursor(0,64-height);    lcd.printf("IntT:   % 4X|% 4X  ", intC0, intC1 );       
  lcd.setCursor(120,lcd.getMaxCharHeight()); lcd.printf("%1i",loopcount++);  lcd.sendBuffer();  
  lcd.sendBuffer();  
  #endif

  // delay(250);
}