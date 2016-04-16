// Demo code for Grove - Temperature Sensor V1.1/1.2
// Loovee @ 2015-8-26
 
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
 
const int B=4275;                 // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
 
void setup()
{
    Serial.begin(9600);
    
    int a = analogRead(pinTempSensor );
 
    float R = 1023.0/((float)a)-1.0;
    R = 100000.0*R;
 
    float temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15;//convert to temperature via datasheet ;

    float fTemp = convertCelsiusToFairenheit(temperature);
    Serial.print("temperature C = ");
    Serial.println(temperature);
    Serial.print("temperature F = ");
    Serial.println(fTemp);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("hello, world!");
 
    delay(100);
}

float convertCelsiusToFairenheit(float temp)
{
  return (((temp*9)/5) + 32);
}

void printTemperature(float temp)
{
  lcd.setCursor(1,0);
  lcd.print("Current Temperature:");
  lcd.setCursor(1,1);
  lcd.print(temp);
}
 
void loop()
{
    
}
