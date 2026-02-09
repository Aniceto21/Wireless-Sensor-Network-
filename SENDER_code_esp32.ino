#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

const char* ssid = "TECNO POVA 7 Pro 5G";
const char* password = "qwerty1234";

WiFiServer server(80);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  server.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.println(WiFi.localIP());
  WiFiClient client = server.available();
  if (client) {
    client.print("Temperature: ");
    client.println(temp);
    client.print("Humidity: ");
    client.println(hum);
    client.stop();
    
  }
  delay(2000);
}
