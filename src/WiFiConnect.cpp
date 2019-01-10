#include <ESP8266WiFi.h>
#include "Arduino.h"
#include "WiFiConnect.h"

WiFiConnect::WiFiConnect(char* ssid, char* pswd)
{
  _ssid = ssid;
  _pswd = pswd;
}

//private
void WiFiConnect::printLocalIP()
{
  Serial.print("Use this URL: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

//public
IPAddress WiFiConnect::getIP()
{
  return WiFi.localIP();
}

bool WiFiConnect::connect()
{
  Serial.print("Connecting to WiFi");
  WiFi.begin(_ssid, _pswd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  printLocalIP();
  return true;
}

void WiFiConnect::print()
{
  Serial.println(_ssid);
  Serial.println(_pswd);
}