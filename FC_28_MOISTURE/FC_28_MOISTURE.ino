int sensor_pin = A0;
int output_pin = 8;
int output_val;
void setup() {
  pinMode(output_pin,OUTPUT);

}

void loop() {
 output_val = analogRead(sensor_pin);
 if(output_val>=250)   //for a value of 250 above the buzzer beeped and anyvalue below 250 buzzer didnt beep 
 {
   digitalWrite(output_pin,HIGH);
   delay(2000);
   digitalWrite(output_pin,LOW);
   delay(5000);
 }

}
