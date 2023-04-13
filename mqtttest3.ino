#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "hrm553";
const char* password = "becoming553";
const char* mqtt_server = "broker.mqttdashboard.com";
const char* mqtt_username = "noahp";
const char* mqtt_password = "12345";
const char* mqtt_subscription = "noahp0553/ESP32/helloworld";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // Your code here
  client.publish(mqtt_subscription, "Hello, world!");
  delay(1000);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT server...");
    if (client.connect("ESP32Client", mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe(mqtt_subscription);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Message received");
  // Your code to process the message here
}
