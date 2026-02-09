#include <WiFi.h>

const char* ssid = "TECNO POVA 7 Pro 5G";
const char* password = "qwerty1234";
const char* host = "10.13.141.228";  // IP of sensor node

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void loop() {
  WiFiClient client;
  if (client.connect(host, 80)) {
    while (client.available()) {
      String data = client.readStringUntil('\n');
      Serial.println(data);
    }
    client.stop();
  }
  delay(3000);
}
