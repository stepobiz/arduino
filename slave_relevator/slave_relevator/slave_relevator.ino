#include <Wire.h>

int pin_relevator_1   = 2;
int pin_relevator_2   = 3;
int pin_relevator_3   = 4;
int pin_relevator_4   = 5;
int pin_relevator_5   = 6;
int pin_relevator_6   = 7;
int pin_relevator_7   = 8;
int pin_relevator_8   = 9;

bool relevator_1;
bool relevator_2;
bool relevator_3;
bool relevator_4;
bool relevator_5;
bool relevator_6;
bool relevator_7;
bool relevator_8;

void setup() {
  Wire.begin(6);
  Wire.onRequest(statusRequest);
  
  pinMode(pin_relevator_1, INPUT);
  pinMode(pin_relevator_2, INPUT);
  pinMode(pin_relevator_3, INPUT);
  pinMode(pin_relevator_4, INPUT);
  pinMode(pin_relevator_5, INPUT);
  pinMode(pin_relevator_6, INPUT);
  pinMode(pin_relevator_7, INPUT);
  pinMode(pin_relevator_8, INPUT);
}

void loop() {
  relevator_1 = (bool) digitalRead(pin_relevator_1);
  relevator_2 = (bool) digitalRead(pin_relevator_2);
  relevator_3 = (bool) digitalRead(pin_relevator_3);
  relevator_4 = (bool) digitalRead(pin_relevator_4);
  relevator_5 = (bool) digitalRead(pin_relevator_5);
  relevator_6 = (bool) digitalRead(pin_relevator_6);
  relevator_7 = (bool) digitalRead(pin_relevator_7);
  relevator_8 = (bool) digitalRead(pin_relevator_8);
    
  delay(10);
}

void statusRequest(){
  Wire.write(relevator_1);
  Wire.write(relevator_2);
  Wire.write(relevator_3);
  Wire.write(relevator_4);
  Wire.write(relevator_5);
  Wire.write(relevator_6);
  Wire.write(relevator_7);
  Wire.write(relevator_8);
}
