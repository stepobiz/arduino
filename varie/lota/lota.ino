void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(millis());
  Serial.print("\t");
  Serial.print("OK\t");
  delay(200);
}
