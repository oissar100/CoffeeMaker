#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "Haste Casa"
#define WIFI_PASSWORD "Berkeley$22"
#define FIREBASE_HOST "feedbackcoffee-a7f8c-default-rtdb.firebaseio.com" // Your Firebase Realtime Database URL
#define FIREBASE_AUTH "your_firebase_secret" // Your Firebase database secret

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  int cupsBrewed = 66; // Replace with your actual cups brewed value
  int caffeineIntake = 10540; // Replace with your actual caffeine intake value

  if (Firebase.setInt(firebaseData, "/cupsBrewed", cupsBrewed)) {
    Serial.println("Cups Brewed data was sent to Firebase");
  } else {
    Serial.println("Failed to send Cups Brewed data to Firebase");
    Serial.println("Error: " + firebaseData.errorReason());
  }

  if (Firebase.setInt(firebaseData, "/caffeineIntake", caffeineIntake)) {
    Serial.println("Caffeine Intake data was sent to Firebase");
  } else {
    Serial.println("Failed to send Caffeine Intake data to Firebase");
    Serial.println("Error: " + firebaseData.errorReason());
  }

  delay(5000); // Send data every 5 seconds
}

