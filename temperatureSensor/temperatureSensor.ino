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

    float fTemp = convertCelsiusToFahrenheit(temperature);
    Serial.print("temperature C = ");
    Serial.println(temperature);
    Serial.print("temperature F = ");
    Serial.println(fTemp);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    // Print a message to the LCD.
    printTemp(fTemp);
}

float convertCelsiusToFahrenheit(float temp)
{
  return (((temp*9)/5) + 32);
}

/* selects the LCD Display color based on temperature in Fahrenheit*/
void selectRGBbyTemp(float temp)
{
  if(temp <= 32)
    lcd.setRGB(100,100,255);        // light blue
  else if(temp < 50)
    lcd.setRGB(0,0,255);            // blue
    else if(temp < 65)
      lcd.setRGB(25,100,25);        // green
      else if(temp < 75)
        lcd.setRGB(255,50,0);       // orange
        else if(temp < 90)
          lcd.setRGB(255,25,25);    // pink
          else lcd.setRGB(255,0,0); // red
}

void printTemp(float temp)
{
  selectRGBbyTemp(temp);
  lcd.setCursor(1,0);
  lcd.print("Current Temp:");
  lcd.setCursor(1,1);
  lcd.print(temp);
}
 
void loop()
{
    
}
