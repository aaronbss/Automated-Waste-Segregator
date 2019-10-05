#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // SET I2C Address

void setup() {
  
  lcd.begin(16,2);  // Initialinze LCD.
  lcd.backlight(); // makes Backligh ON. 
  lcd.clear();     // Clears LCD
  lcd.home();      // Sets cursor at Column 0 and Line 0
  lcd.print("Hello, Beautiful!");  
  lcd.setCursor(0,1); // Sets cursor at Column 0 and Line 1
  lcd.print("How you doing?");
}


void loop()  
{
  // include your code. 
}
