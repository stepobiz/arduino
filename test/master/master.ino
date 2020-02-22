#include <Wire.h>

void setup() {
  Wire.begin(1);
  Serial.begin(9600);
}
void loop() {
  Serial.print(millis());
  Serial.print("\t -"); 
  
  Wire.requestFrom(10, 6);
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  
  Serial.print("\n");
  delay(500);
}
