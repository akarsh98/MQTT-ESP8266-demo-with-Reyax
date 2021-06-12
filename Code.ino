#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "wifiname"
#define WLAN_PASS       "wifipass"

/************************* MQTT Setup *********************************/

#define MQTT_SERVER      "iot.reyax.com"
#define MQTT_USER        "mqtt_username"
#define MQTT_PASSWORD    "mqtt_password"

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, 1883, MQTT_USER, MQTT_PASSWORD);

/****************************** Feeds ***************************************/

Adafruit_MQTT_Subscribe TOPIC1 = Adafruit_MQTT_Subscribe(&mqtt, "bulb");

Adafruit_MQTT_Publish TOPIC2 = Adafruit_MQTT_Publish(&mqtt, "counter");


/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(13,OUTPUT);

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  mqtt.subscribe(&TOPIC1);
}

uint32_t x=0;
int cnt = 0;

void loop() {

  MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &TOPIC1) {
      Serial.print(F("Got: "));
      Serial.println((char *)TOPIC1.lastread);
     uint16_t num = atoi((char *)TOPIC1.lastread);
     digitalWrite(13,num);
    }
  }


  Serial.print(F("\nSending counter "));
  Serial.print(cnt);
  Serial.print("...");
  if (! TOPIC2.publish(cnt++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return; 
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
