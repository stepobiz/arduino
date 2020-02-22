class Command {
  public:
    String action;
    String param;
    String device;
    bool executionReady = false;
};
class CommandReader {
  private:
    String commandPartBuffer;
    Command* commandBuffer;
    Command* command;
   
    void reset(){
      commandPartBuffer = "";
      delete commandBuffer;
      commandBuffer = new Command();
    }
    void resetCommand(){
      delete command;
      command = new Command();
    }
  public:
    CommandReader(){
      command = new Command();
      commandBuffer = new Command();
    }
    void ackExecution(){
      resetCommand();
    }
    Command* getCommand(){
      int incomingByte = 0;
      if (Serial.available() > 0) {
        incomingByte = Serial.read();
        if(incomingByte == 45 || incomingByte == 124 || incomingByte == 10){
          if(commandBuffer->action == NULL){
            if(commandPartBuffer == NULL){
              commandPartBuffer = "!";
            }
            commandBuffer->action = commandPartBuffer;
          }
          else if(commandBuffer->param == NULL){
            if(commandPartBuffer == NULL){
              commandPartBuffer = "!";
            }
            commandBuffer->param = commandPartBuffer;
          }
          else {
            if(commandPartBuffer != NULL){
              commandBuffer->device = commandPartBuffer;
           
              command->action = commandBuffer->action;
              command->param = commandBuffer->param;
              command->device = commandBuffer->device;
              command->executionReady = true;
            }
          }
          commandPartBuffer = "";
        } else {
          char incomingByteChar = incomingByte;
          commandPartBuffer += incomingByteChar;
        }
       
        // New Comand and New Line
        if(incomingByte == 124 || incomingByte == 10){
          reset();
        }
      }
      return command;
    }
};




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
