#include "SevSeg.h"

SevSeg controller;
int increasePin = 12;
int decreasePin = 11;
int number = 0;

byte commonPins[] = {};
byte segmentPins[] = {2,3,4,5,6,7,8};

void setup() {
  controller.begin(COMMON_ANODE, 1, commonPins, segmentPins, 1);
  pinMode(increasePin, INPUT);
  pinMode(decreasePin, INPUT);
}

void loop() {

  if(digitalRead(increasePin) == HIGH){
    number = (positive(number) + 1) % 10;
    controller.setNumber(number);
    controller.refreshDisplay();
    delay(750);
  } else if(digitalRead(decreasePin) == HIGH){
    if(number != 0){
    number = (positive(number) - 1) % 10;
    } else {
      number = 9;
    }
    controller.setNumber(number);
    controller.refreshDisplay();
    delay(750);
  } else{
    controller.setNumber(number);
    controller.refreshDisplay();
  }


  // count down timer:
  // delay(1000);
  // for(int i = 9; i>=0; i--){
  //   controller.setNumber(i);
  //   controller.refreshDisplay();
  //   delay(1000);
  // }
}

int positive(int n){
  return n < 0 ? -1*n : n;
}
