#ifndef LightControls_h
#define LightControls_h

#include "Arduino.h"

const int SERVER = 0;
const int DEVICE = 1;
const int LED_ON = 2;
const int LED_OFF = 3;

class LightControls
{
  public:
    LightControls(int pin);
    void handleType(int type);
    int indetifyInput(String input);
    void blink(bool on, int speed);
  private:
    int _pin;
    bool _blink;
};

#endif