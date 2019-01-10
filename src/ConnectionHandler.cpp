#include "Arduino.h"
#include <ESP8266WiFi.h>
#include "LightControls.h"
#include "ConnectionHandler.h"
#include "DeviceResponse.h"

WiFiServer server(80);
LightControls lightControls(LED_BUILTIN);

ConnectionHandler::ConnectionHandler()
{
  server.begin();
  Serial.println("Server started");
  _externalControl = (LightControls*) malloc(sizeof(LightControls));
  _externalControl = new LightControls(LED_BUILTIN);
}

void ConnectionHandler::handle()
{
  WiFiClient client = server.available();
  if (!client) {
    lightControls.blink(true, 2000);
    return;
  }
  lightControls.blink(false, 0);

  Serial.println("new client");
  while(!client.available()){
    delay(500);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  int type = _externalControl->indetifyInput(request);
  client.flush();

  handleType(client, type);

  delay(100);
}

void ConnectionHandler::handleType(WiFiClient client, int type) {
  printHeader(client);
  lightControls.handleType(type);
  if (type == SERVER) {
    // printString(client, IP.toString());
  } else {
    printString(client, String(type));
  }
}


