#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "host"
#define FIREBASE_AUTH "auth key"
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "pass"

void setup() {
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(D0,OUTPUT);
}
int n = 0;
void loop() {
  int b = Firebase.getInt("Led");
  //Serial.println(Firebase.getString("CSEIoT/Led"));
  if(b==1)
  //if(Firebase.getString("CSEIoT/Led") == "1")
  { 
    digitalWrite(D0, HIGH);
  }
  else
  {
    digitalWrite(D0, LOW);
  }
  delay(1000);
}
