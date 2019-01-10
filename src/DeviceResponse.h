#ifndef DeviceResponse_h
#define DeviceResponse_h

#include "Arduino.h"
#include <ESP8266WiFi.h>

void printHeader(WiFiClient client);
void printBody(WiFiClient client, String body);
void printString(WiFiClient client, String string);

#endif