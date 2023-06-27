#include "Arduino.h"
#include "Nema23.h"

Nema23::Nema23(int dirPin, int stepPin) {
  _dirPin = dirPin;
  _stepPin = stepPin;
}

void Nema23::begin() {
  pinMode(_dirPin, OUTPUT);
  pinMode(_stepPin, OUTPUT);
}

void Nema23::moveForward(int rounds) {
  _rounds = rounds;
  _steps = _rounds * 400;

  for (int i = 0; i < _steps; i++) {
    digitalWrite(_dirPin, 1);
    digitalWrite(_stepPin, HIGH);
    delay(1);
    //delayMicroseconds(200);
    digitalWrite(_stepPin, LOW);
    delay(1);
    //delayMicroseconds(200);
  }
}

void Nema23::stop(){
  digitalWrite(_dirPin, LOW);
  digitalWrite(_stepPin, LOW);
}
void Nema23::moveBack(int rounds) {
  _rounds = rounds;
  _steps = _rounds * 400;
  for (int i = 0; i < _steps; i++) {
    digitalWrite(_dirPin, 0);
    digitalWrite(_stepPin, HIGH);
    delay(1);
    digitalWrite(_stepPin, LOW);
    delay(1);
  }
}