#include <Arduino.h>
#include "thermocouple.h"

thermocouple::thermocouple(char type, int clk_pin, int cs_pin, int data_pin) {
    sensor_type=type;
    clk=clk_pin;
    cs=cs_pin;
    data=data_pin;  
}

thermocouple::thermocouple(int clk_pin, int cs_pin, int data_pin) {
    clk=clk_pin;
    cs=cs_pin;
    data=data_pin;  
}


void thermocouple::begin(){
  pinMode(clk, OUTPUT);       //
  pinMode(cs, OUTPUT);   
  pinMode(data, INPUT_PULLUP);  //
}

void thermocouple::begin_max31855(){
  sensor_type=MAX81355;
  begin();
}

void thermocouple::begin_max6675(){
  sensor_type=MAX6675;
  begin();
}

//---------------------------------------------------------------
// Return status:
//
// Bit:   Meaning
//    0   TC open circuit
//    1   TC Short to GND
//    2   TC Short to VCC
//    3   Always 0
//
int thermocouple::read_MAX81355(){
  const int delayms = 1;
  const int bitcnt = 32;
  bool bit_in;
  raw=0;
  digitalWrite(cs,LOW);
  delay(delayms);
  for (int i=0;i<bitcnt;i++){
    digitalWrite(clk,HIGH);
    delay(delayms);
    digitalWrite(clk,LOW);    
    delay(delayms);
    raw<<=1;
    bit_in=digitalRead(data)&1;
    raw|=bit_in;
  }
  digitalWrite(cs,HIGH);
  delay(delayms);

  // Return status:
  // Bit:   Meaning
  //    0   TC open circuit
  //    1   TC Short to GND
  //    2   TC Short to VCC
  //    3   Always 0
  tempC>>=20;
  return (raw & 0xf);
}

int thermocouple::read_MAX6675(){
  const int delayms = 5;
  const int bitcnt = 16;
  bool bit_in;
  raw=0;
  digitalWrite(cs,LOW);
  delay(delayms);
  for (int i=0;i<bitcnt;i++){
    digitalWrite(clk,HIGH);
    delay(delayms);
    digitalWrite(clk,LOW);    
    delay(delayms);
    raw<<=1;
    bit_in=digitalRead(data)&1;
    raw|=bit_in;
  }
  digitalWrite(cs,HIGH);
  delay(delayms);

  // Return status:
  // Bit:   Meaning
  //    0   TC open circuit
  //    1   TC Short to GND
  //    2   TC Short to VCC
  //    3   Always 0
  // raw<<=17;
  tempC=raw>>5; //>>3;
  raw= (raw & 0xfff4)<<13;    // shift to match MAX81355
  return (0);
}

int thermocouple::read() {
  if (sensor_type == MAX81355 ) {
    return read_MAX81355();
  } else {
    return read_MAX6675();
  }
}

int thermocouple::getTempC(){
  int value=0;
  value=raw>>20;
  if( value&0x800 ) {
     value |= 0xfffff000;
  };
  return tempC;
}


int thermocouple::getTempF(){
return (getTempC()*1.8)+32;
}