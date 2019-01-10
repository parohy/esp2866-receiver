#ifndef ConnectionHandler_h
#define ConnectionHandler_h

#include "Arduino.h"
#include "LightControls.h"
#include "DeviceResponse.h"
#include <ESP8266WiFi.h>

class ConnectionHandler
{
  public:
    ConnectionHandler();
    void handle();
  private:
    void handleType(WiFiClient client, int type);
    LightControls* _externalControl;
};

#endif