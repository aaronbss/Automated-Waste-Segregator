#include <Servo.h> 
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
const int trigPin = 9;
const int echoPin = 10;
const int trigPin1 = 5;
const int echoPin1 = 6;
const int buzz = 3;
long duration;
int distance;
long duration1;
int distance1;
int sensor_pin = A0;
int sensor_pin1 = A1;
float moisture_percentage;
float output_val;
int output_val1;
int servoPin = 12;
int servoPin2 =13;
Servo Servo1; 
Servo Servo2;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzz, OUTPUT);
Servo1.attach(servoPin);// We need to attach the servo to the used pin number
Serial.begin(9600);
Servo2.attach(servoPin2);


lcd.begin(16,2);  // Initialinze LCD.
lcd.backlight(); // makes Backligh ON. 
lcd.clear();     // Clears LCD
lcd.home();      // Sets cursor at Column 0 and Line 0
lcd.print("Hello, Welcome!");  
delay(2000);
lcd.setCursor(0,1); // Sets cursor at Column 0 and Line 1
lcd.print("Its sorting time");
delay(2000);

 
}

void loop() {
  
lcd.clear();     
lcd.home();      
lcd.print("Place the waste into the orifice");
delay(2000);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

if(distance<=3)
{
    lcd.clear();     
    lcd.home();      
    lcd.print("Sorting Process has begun");
    digitalWrite(buzz,HIGH);
    delay(1000);

   output_val = analogRead(sensor_pin);
   output_val1 = analogRead(sensor_pin1);
   output_val= (output_val+output_val1)/2.0;
   moisture_percentage = (100 -( (output_val/1023.00 * 100) ));
   moisture_percentage = moisture_percentage - 12.00;
 Serial.println(moisture_percentage);
 delay(2000);
 if(moisture_percentage<=20.00)    
 {
   Servo1.write(180); 
  delay(3000); 
   Servo1.write(90); 
   delay(1000); 
   lcd.clear();     
   lcd.home();      
   lcd.print("DRY WASTE");
   delay(2000);
   lcd.clear();     
   lcd.home(); 
   lcd.print(moisture_percentage);
   delay(2000);
 }
else 
{
  Servo2.write(90); 
  delay(3000); 
   Servo2.write(0); 
   delay(1000);
   digitalWrite(buzz,LOW);
   delay(1000);
   lcd.clear();     
   lcd.home();      
   lcd.print("WET WASTE");
   delay(2000);
   lcd.clear();     
   lcd.home();
   lcd.print(moisture_percentage);
   delay(2000);

}
}
}

