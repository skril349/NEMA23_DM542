#ifndef Nema23_h
#define Nema23_h

#include "Arduino.h"

class Nema23 {
public:
  Nema23(int dirPin, int stepPin);
  void begin(int pulses_rev);
  void moveForward(float rounds);
  void moveBack(float rounds);
  void stop();
private:

  int _dirPin;
  int _stepPin;
  int _steps;
  float _rounds;
  int _pulses_rev;
};

#endif