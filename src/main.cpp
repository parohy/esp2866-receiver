#include <ESP8266WiFi.h>
#include "DeviceResponse.h"

// const char* ssid = "SmartHome";
// const char* pass = "ReactN4t1v3";
const char* ssid = "Parohy_ajfon";
const char* pass = "asdfghjkl";



const int SERVER = 0;
const int DEVICE = 1;
const int LED_ON = 2;
const int LED_OFF = 3;

IPAddress IP;

WiFiServer server(80);

void printLocalIP() {
  IP = WiFi.localIP();
  Serial.print("Use this URL: ");
  Serial.print("http://");
  Serial.print(IP);
  Serial.println("/");
}

int indetifyRequest(String input) {
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

void handleType(WiFiClient client, int type) {
  printHeader(client);
  switch (type) {
    case LED_ON:
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case LED_OFF:
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case SERVER:
      printString(client, IP.toString());
      return;
    default:
      Serial.print("Not defined to handle type: ");
      Serial.println(type);
  }
  printString(client, String(type));
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, HIGH);
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

  int type = indetifyRequest(request);
  client.flush();

  handleType(client, type);

  delay(100);
}
 