#include "Arduino.h"
#include "Nema23.h"

Nema23::Nema23(int dirPin, int stepPin) {
  _dirPin = dirPin;
  _stepPin = stepPin;
}

void Nema23::begin(int pulses_rev) {
  pinMode(_dirPin, OUTPUT);
  pinMode(_stepPin, OUTPUT);
  _pulses_rev=pulses_rev;

}

void Nema23::moveForward(float rounds) {
  _rounds = rounds;
  _steps = _rounds * _pulses_rev;

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
void Nema23::moveBack(float rounds) {
  _rounds = rounds;
  _steps = _rounds * _pulses_rev;
  for (int i = 0; i < _steps; i++) {
    digitalWrite(_dirPin, 0);
    digitalWrite(_stepPin, HIGH);
    delay(1);
    digitalWrite(_stepPin, LOW);
    delay(1);
  }
}