#include <WiFi.h>
#include <WebServer.h>
#include <FirebaseJson.h>
#include <string.h>

#define RXp2 16
#define TXp2 17

const char *ssid = "";
const char *password = "";

WebServer server(80);
FirebaseJson json;

void handleRoot()
{
  String jsonResponse;
  json.toString(jsonResponse, true);
  server.send(200, "application/json", jsonResponse);
}

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  json.set("status", 0);
  json.set("message", "");

  server.on("/", handleRoot);
  server.begin();
}

void loop()
{
  if (Serial2.available())
  {
    String response = Serial2.readString();
    response.trim();

    int responseCode = 401;

    if (response == "Access Granted!")
    {
      responseCode = 200;
    }

    json.set("status", responseCode);
    json.set("message", response);
  }
  server.handleClient();
}
