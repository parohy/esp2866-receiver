#include "Arduino.h"
#include "DeviceResponse.h"

void printHeader(WiFiClient client) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
}

void printBody(WiFiClient client, String body) {
  Serial.println(body);
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(body);
  client.println("</html>");
}

void printString(WiFiClient client, String string) {
  Serial.println(string);
  client.println(string);
}