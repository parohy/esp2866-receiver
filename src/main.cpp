#include <ESP8266WiFi.h>
#include "DeviceResponse.h"
#include "LightControls.h"
#include "ConnectionHandler.h"

WiFiServer server(80);
LightControls lightControls(LED_BUILTIN);
ConnectionHandler connectionHandler;

void handleType(WiFiClient client, int type) {
  printHeader(client);
  lightControls.handleType(type);
  if (type == SERVER) {
    // printString(client, IP.toString());
  } else {
    printString(client, String(type));
  }
}

void setup() {
  lightControls.handleType(LED_OFF);
  Serial.begin(9600);

  delay(1000);

  // server.begin();
  // Serial.println("Server started");
 
  // Print the IP address
  // printLocalIP();
}

void loop() 
{
  connectionHandler.handle();
}
 