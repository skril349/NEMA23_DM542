#include "Nema23.h"
int state = 0;
int BUTTON_PIN = 4;
int led_pin = 7;
float numberTurns = 30;
Nema23 nema23(9, 6);

void setup() {
  nema23.begin(400);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  int value = digitalRead(BUTTON_PIN);

  switch (state) {
    case 0:
      digitalWrite(led_pin, 1);
      value = digitalRead(BUTTON_PIN);
      if (value == 1) {
        Serial.println("state == 1");
        state = 1;
      }
      break;
    case 1:
      nema23.moveForward(numberTurns);
      Serial.println("state == 2");
      state = 2;
      break;
    case 2:
      digitalWrite(led_pin, 0);
      nema23.stop();
      Serial.println("state == 3");
      state = 3;
      break;
    case 3:
     value = digitalRead(BUTTON_PIN);
     // Serial.println(value);
      //delay(500);
      if (value == 0) {
        //nema23.moveBack(numberTurns);
        //Serial.println("case = 4");
        state = 4;
      }
      
      state = 4;
      break;
    case 4:
      nema23.stop();
      Serial.println("state == 0");
      state = 0;
      break;
  }
}
