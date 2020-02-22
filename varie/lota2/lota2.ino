#include <Command.h>
#include <CommandReader.h>

CommandReader* commandReader;
Command* command;

void setup() {
  Serial.begin(9600);
  Serial.println("PARTITO");
 
  commandReader = new CommandReader();
}

void loop() {
  command = commandReader->getCommand();
  if(command->executionReady){
        Serial.print("Action: ");
        Serial.print(command->action);
        Serial.print(" Params: ");
        Serial.print(command->param);
        Serial.print(" Device: ");
        Serial.print(command->device);
        Serial.println();
        commandReader->ackExecution();
  }
  delay(10);
}
