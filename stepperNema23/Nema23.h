#ifndef Nema23_h
#define Nema23_h

#include "Arduino.h"

class Nema23 {
public:
  Nema23(int dirPin, int stepPin);
  void begin();
  void moveForward(int rounds);
  void moveBack(int rounds);
  void stop();
private:

  int _dirPin;
  int _stepPin;
  int _steps;
  int _rounds;
};

#endif