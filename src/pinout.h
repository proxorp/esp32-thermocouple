#define TARGET_BOARD ESP32DEVKIT1
// #define TARGET_BOARD MEGA2560



#if TARGET_BOARD == ESP32DEVKIT1


// ESP32-DEVKIT1 ESP-32S Board Pin Definitions				
// LEFT SIDE PINS				
#define	VP	36	                          //[ VP ]   ,GPIO36,ADC0,	
#define	VN	39	                          //[ VN ]   ,GPIO39,ADC3,	
#define	D34	34	                          //[ D34 ]   ,GPIO34,ADC6,	
#define	D35	35	                          //[ D35 ]   ,GPIO35,ADC7,	
#define	D32	32	                          //[ D32 ]   ,GPIO32,ADC4,TOUCH9	
#define	D33	33	                          //[ D33 ]   ,GPIO33,ADC5,TOUCH8	
#define	D25	25	                          //[ D25 ]   ,GPIO25,ADC18,DAC1	
#define	D26	26	                          //[ D26 ]   ,GPIO26,ADC19,DAC2	
#define	D27	27	                          //[ D27 ]   ,GPIO27,ADC17,TOUCH7	
#define	D14	14	                          //[ D14 ]   ,GPIO14,ADC16,TOUCH6	
#define	D12	12	                          //[ D12 ]   ,GPIO12,ADC15,TOUCH5	
#define	D13	13	                          //[ D13 ]   ,GPIO13,ADC14,TOUCH4	
// RIGHT SIDE PINS				
#define	D23	23	                          //[ D23 ] ,GPIO23,VSPI MOSI,	
#define	D22	22	                          //[ D22 ] ,GPIO22,I2C SCL,	
#define	TX0	1	                          //[ TX0 ] ,GPIO1,TX0,	
#define	D1	1	                          //[ TX0 ] ,GPIO1,TX0,	
#define	RX0	3	                          //[ RX0 ] ,GPIO3,RX0,	
#define	D3	3	                          //[ RX0 ] ,GPIO3,RX0,	
#define	D21	21	                          //[ D21 ] ,GPIO21,I2CSDA,	
#define	D19	19	                          //[ D19 ] ,GPIO19,VSPI MISO,	
#define	D18	18	                          //[ D18 ] ,GPIO18,VSPI SCK,	
#define	D5	5	                          //[ D5 ] ,GPIO5,VSPI CS,	
#define	TX2	17	                          //[ TX2 ] ,GPIO17,TX2,	
#define	D17	17	                          //[ TX2 ] ,GPIO17,TX2,	
#define	D16	16	                          //[ RX2 ] ,GPIO16,RX2,	
#define	RX2	16	                          //[ RX2 ] ,GPIO16,RX2,	
#define	D4	4	                          //[ D4 ] ,GPIO4,ADC10,TOUCH0	
#define	D2	2	                          //[ D2 ] ,GPIO2,ADC12,TOUCH2	
#define	D15	15	                          //[ D15 ] ,GPIO15,ADC13,TOUCH3	
#define	BOOT	0		     //Boot Button / TOUCH1 / etc…

#define LCD_PIN_RS                 D26   //D19    // Reg Select - LCDRS
#define LCD_PIN_DATA               D13  // D5    // Data      - LCDE
#define LCD_PIN_CLK                D14    // Clock     - LCD4

// These defines match the Smart LCD Schematic pin names (legacy)
#define LCD_PINS_D4     LCD_PIN_CLK
#define LCD_PINS_ENABLE LCD_PIN_DATA
#define LCD_PINS_RS     LCD_PIN_RS

#define pinTempClock   D12    //Which level shifter pin is the signal attached
#define pinTempData    D15
#define pinTempCS0     D13
#define pinTempCS1     D14

#define LEDPIN LED_BUILTIN

// rotary encoder pins
#define encA        D35 //VP  //D4
#define encB        D34 //VN  //RX2
#define encBtn      VN  //D15
#define KILL_PIN    VP    // kill button pin
#define BEEPER_PIN                    D17   // Ramps uses this pin for speaker control



// #define SD_DETECT_PIN                 49    // sd card detect pin


#define FAN_PWM_PIN                   D32    //ramps uses pins 8,9,10 for pwm out

#define BTN_EN1                       encA
#define BTN_EN2                       encB
#define BTN_ENC                       encBtn

#elif TARGET_BOARD == MEGA2560



#define FAN_PWM_PIN                   10    //ramps uses pins 8,9,10 for pwm out

#define LCD_PINS_RS                   16    // Reg Select
#define LCD_PINS_ENABLE               17    // Data
#define LCD_PINS_D4                   23    // Clock

#define BEEPER_PIN                    37    // Ramps uses this pin for speaker control

#define BTN_EN1                       65   // moved to this pin to support PCINT
#define BTN_EN2                       66   // moved to this pin to support PCINT
#define BTN_ENC                       35

#define SD_DETECT_PIN                 49    // sd card detect pin
#define KILL_PIN                      41    // kill button pin

//-------------------------------------------------------
// SPI Pin Definition
#define TLS2  42
#define TLS3  44
#define TLS4  40
#define TLS5  63  // error, this is connected to GND need to fix hw.
#define TLS6  64
#define TLS7  58
#define pinTempClock  TLS2    //Which level shifter pin is the signal attached
#define pinTempCS     TLS3
#define pinTempData   TLS4

#define LEDPIN LED_BUILTIN

// rotary encoder pins
#define encA    BTN_EN1
#define encB    BTN_EN2
#define encBtn  BTN_ENC

#elif TARGET_BOARD == NODEMCU



//NodeMCU Pins:  D0-D10, A0

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

static const uint8_t LED_BUILTIN = 16;
static const uint8_t BUILTIN_LED = 16;

static const uint8_t D0   = 16;     // LED / Wake
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;      // Flash, don't use
static const uint8_t D4   = 2;      //TXD1
static const uint8_t D5   = 14;     //HSCLK
static const uint8_t D6   = 12;     //HMISO
static const uint8_t D7   = 13;     //RXD2 / HMOSI
static const uint8_t D8   = 15;     //TXD0 / HCS
static const uint8_t D9   = 3;      //RXD0
static const uint8_t D10 = 1;       //SDD3



#define FAN_PWM_PIN                   D1    //ramps uses pins 8,9,10 for pwm out

#define LCD_PINS_RS                   D2    // Reg Select
#define LCD_PINS_ENABLE               D7    // Data
#define LCD_PINS_D4                   D5    // Clock

#define BEEPER_PIN                    D4    // Ramps uses this pin for speaker control

#define BTN_EN1                       65   // moved to this pin to support PCINT
#define BTN_EN2                       66   // moved to this pin to support PCINT
#define BTN_ENC                       35

#define SD_DETECT_PIN                 49    // sd card detect pin
#define KILL_PIN                      41    // kill button pin

//-------------------------------------------------------
// SPI Pin Definition
#define TLS2  42
#define TLS3  44
#define TLS4  40
#define TLS5  63  // error, this is connected to GND need to fix hw.
#define TLS6  64
#define TLS7  58
#define pinTempClock  TLS2    //Which level shifter pin is the signal attached
#define pinTempCS     TLS3
#define pinTempData   TLS4

#define LEDPIN LED_BUILTIN

// rotary encoder pins
#define encA    BTN_EN1
#define encB    BTN_EN2
#define encBtn  BTN_ENC

#endif