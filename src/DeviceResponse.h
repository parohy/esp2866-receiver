#ifndef DeviceResponse_h
#define DeviceResponse_h

#include <ESP8266WiFi.h>
#include "Arduino.h"

void printHeader(WiFiClient client);
void printBody(WiFiClient client, String body);
void printString(WiFiClient client, String string);

#endif