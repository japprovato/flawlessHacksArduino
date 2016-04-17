#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int LIGHT_SENSOR = A0;
int LIT_THRESHOLD = 700;
int BUTTON = 3;

void setup() {
  lcd.begin(16,2);

  // beginning prompt
  lcd.print("Press Button 2 c");
  lcd.setCursor(1,1);
  lcd.print("if u r #lit...");
}

/* returns true if light sensor value is greater than the threshold of litness*/
/* aka if you are literally lit */
bool areYouLit(int sensorValue)
{
  if(sensorValue < LIT_THRESHOLD)
    return false;
  return true;
}

void scrollResult()
{
    // pause to display result text before beginning to scroll
    delay(1000);
    
    // move it offscreen to the left
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }
    
    // move it offscreen to the right
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
        // scroll one position right:
        lcd.scrollDisplayRight();
        // wait a bit:
        delay(150);
    }

    // move it back to the center
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }

    // delay at the end
    delay(1000);
}

void loop() {

  // reads in button press
  if(digitalRead(BUTTON) == 1)
  {
    //gets value from light sensor
    int sensorValue = analogRead(LIGHT_SENSOR);
    lcd.clear();
    if(areYouLit(sensorValue))
    {
      lcd.setRGB(255,25,25);
      lcd.print("Congrats!!");
      lcd.setCursor(1,1);
      lcd.print("U R LIT!!");
      scrollResult();
    }
    else
    {
      lcd.setRGB(0,50,200);
      lcd.print("Sorry, nerd!");
      lcd.setCursor(1,1);
      lcd.print("U R NOT LIT!");
      scrollResult();
    }
  }
}
