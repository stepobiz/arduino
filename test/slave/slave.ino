#include <Wire.h>

void setup() {
  Wire.begin(10);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);
}

void loop() {
  Serial.println(millis());
  delay(100);
}

void requestEvent() {
  Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master
}
