#ifndef WiFiConnect_h
#define WiFiConnect_h

#include <ESP8266WiFi.h>
#include "Arduino.h"

class WiFiConnect
{
  public:
    WiFiConnect(char* ssid, char* pswd);
    bool connect();
    void print();
    IPAddress getIP();
  private:
    void printLocalIP();
    char* _ssid;
    char* _pswd;
};

#endif