#include <SoftwareSerial.h>
#include <Wire.h>
#include <Command.h>
#include <CommandReader.h>

SoftwareSerial BTserial(2, 3);
CommandReader* sertialCommandReader;
CommandReader* btCommandReader;
Command* command;
String previousRilevation;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  BTserial.begin(9600);
  
  sertialCommandReader = new CommandReader();
  btCommandReader = new CommandReader();
  
  previousRilevation = "";
}
void loop() {
  int incomingByte = 0;
  
  if(Serial.available()){
    incomingByte = Serial.read();
    command = sertialCommandReader->getCommand(incomingByte);
    if(command->executionReady){
      if(command->action == "o"){
        pushButton(command->device.toInt());
      }
      sertialCommandReader->ackExecution();
    }
  }
  if(BTserial.available()){
    incomingByte = BTserial.read();
    command = btCommandReader->getCommand(incomingByte);
    if(command->executionReady){
      if(command->action == "o"){
        pushButton(command->device.toInt());
      }
      btCommandReader->ackExecution();
    }
  }
  
  // Messo questo if per performance di esecuzione comandi
  if(!Serial.available() && !BTserial.available()) {
    String rilevation = getRilevator();
    if(rilevation != previousRilevation) {
      Serial.println(rilevation);
      BTserial.println(rilevation);
      previousRilevation = rilevation;
    }
  }
}

bool pushButton(int button){
  Wire.beginTransmission(7);
  Wire.write(button);
  Wire.endTransmission();
  
  Wire.requestFrom(7, 1);
  return Wire.read();
}

String getRilevator(){  
  int id=1;
  String result = "";
  result += "{\"status\":{";
  Wire.requestFrom(6, 8);
  while (Wire.available()) {
    if(id != 1){
      result += ",";
    }
    bool state = Wire.read();
    {
      result += "\"";
      result += id;
      result += "\":";
      result += state;
    }
    id++;
  }
  result += "}}";
  return result;
}
