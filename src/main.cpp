#include <ESP8266WiFi.h>
#include "DeviceResponse.h"
#include "LightControls.h"

// const char* ssid = "SmartHome";
// const char* pass = "ReactN4t1v3";
const char* ssid = "Parohy_ajfon";
const char* pass = "asdfghjkl";

IPAddress IP;

WiFiServer server(80);
LightControls lightControls(LED_BUILTIN);

void printLocalIP() {
  IP = WiFi.localIP();
  Serial.print("Use this URL: ");
  Serial.print("http://");
  Serial.print(IP);
  Serial.println("/");
}

void handleType(WiFiClient client, int type) {
  printHeader(client);
  lightControls.handleType(type);
  if (type == SERVER) {
    printString(client, IP.toString());
  } else {
    printString(client, String(type));
  }
}

void setup() {
  lightControls.handleType(LED_OFF);
  Serial.begin(9600);
  
  delay(1000);
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");  
  }
  Serial.println("");
  
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  printLocalIP();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(500);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');

  int type = lightControls.indetifyInput(request);
  client.flush();

  handleType(client, type);

  delay(100);
}
 