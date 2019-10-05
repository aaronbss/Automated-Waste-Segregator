int sensor_pin = A0;
int output_val;
float moisture_percentage;
void setup() {
Serial.begin(9600);

}

void loop() {
 output_val = analogRead(sensor_pin);
 moisture_percentage = (100 -( (output_val/1023.00 * 100) ));
 Serial.print(moisture_percentage);
 Serial.print("%\n\n");
 delay(2000);
}
 
 
