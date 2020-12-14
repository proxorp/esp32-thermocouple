//============================================================================
// Thermocouple MAX31855 Access Library
//
// Reads the MAX chip using a bit-banged SPI method.
//
class thermocouple  {
private:
    int clk,cs,data;    //define the pins connected to the sensor.
    char sensor_type=0;        // Defines the type of sensor: 0-undef, 1-max81355, 2-max6675
    unsigned long raw;  //holds the last 32-bit value read from the MAX chip
    int tempC;
    int read_MAX81355();
    int read_MAX6675();
public:
    static const char MAX81355= 1;       // 
    static const char MAX6675 = 2;       // 
    thermocouple(char type, int clk, int cs, int data);  // Create the object using the pins passed.
    thermocouple(           int clk, int cs, int data); 
    void begin();   // Setup the pins to input/output configurations.
    void begin_max31855(); 
    void begin_max6675();     
    int read();     // Read the data from the MAX chip and save to later access.
                    // Return status:
                    // Bit:   Meaning
                    //    0   TC open circuit
                    //    1   TC Short to GND
                    //    2   TC Short to VCC
                    //    3   Always 0    
    int getTempC(); // Return the temp in Celcius that was last read.
    int getTempF(); // Return the temp in Farenheit that was last read.
};