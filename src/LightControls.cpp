#include "Arduino.h"
#include "LightControls.h"

LightControls::LightControls(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

int LightControls::indetifyInput(String input)
{
  Serial.print("Indetifying: ");
  Serial.println(input);

  if (input.indexOf("/LED=ON") != -1) {
    return LED_ON;
  } 
  
  if (input.indexOf("/LED=OFF") != -1) {
    return LED_OFF;
  }

  if (input.indexOf("/identify") != -1) {
    return SERVER;
  }

  return DEVICE;
}

void LightControls::handleType(int type)
{
  switch (type) {
    case LED_ON:
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case LED_OFF:
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case SERVER:
      return;
    default:
      Serial.print("Not defined to handle type: ");
      Serial.println(type);
  }
}