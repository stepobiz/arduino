#include <Wire.h>
#include <RelayAsButton.h>

RelayAsButton* button_1;
RelayAsButton* button_2;
RelayAsButton* button_3;
RelayAsButton* button_4;
RelayAsButton* button_5;
RelayAsButton* button_6;
RelayAsButton* button_7;
RelayAsButton* button_8;

bool pushResult;

void setup() {
  Wire.begin(7);
  Wire.onReceive(pushButton);
  Wire.onRequest(pushResultRequest);

  int relayTime = 300;

  button_1 = new RelayAsButton(2, relayTime);
  button_2 = new RelayAsButton(3, relayTime);
  button_3 = new RelayAsButton(4, relayTime);
  button_4 = new RelayAsButton(5, relayTime);
  button_5 = new RelayAsButton(6, relayTime);
  button_6 = new RelayAsButton(7, relayTime);
  button_7 = new RelayAsButton(8, relayTime);
  button_8 = new RelayAsButton(9, relayTime);

  pushResult = false;
}

void loop() {
  button_1->check();
  button_2->check();
  button_3->check();
  button_4->check();
  button_5->check();
  button_6->check();
  button_7->check();
  button_8->check();

  delay(10);
}

void pushButton(int bytes){
  int button = Wire.read();
  switch (button) {
    case 1:
      pushResult = button_1->push();
      break;
    case 2:
      pushResult = button_2->push();
      break;
    case 3:
      pushResult = button_3->push();
      break;
    case 4:
      pushResult = button_4->push();
      break;
    case 5:
      pushResult = button_5->push();
      break;
    case 6:
      pushResult = button_6->push();
      break;
    case 7:
      pushResult = button_7->push();
      break;
    case 8:
      pushResult = button_8->push();
      break;
  }
}

void pushResultRequest(){
  Wire.write(pushResult);
}
