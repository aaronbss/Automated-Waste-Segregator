#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 12; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}
void loop(){  
   Servo1.write(0); 
   delay(2000); 
   Servo1.write(90); 
   delay(2000); 

}
