#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3);

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);

}

String incoming;
void loop() {
  incoming = "";
  if (Serial.available() > 0) {
    incoming = Serial.readString();
    BTserial.println(incoming);
  }
  incoming = "";
  if (BTserial.available() > 0) {
    incoming = BTserial.readString();
    Serial.println(incoming);
  }

}
