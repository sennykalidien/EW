
#include <EIoTCloudRestApi.h>
#include <EIoTCloudRestApiConfig.h>
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>


//Pins
int pinLdr = A0;
int exposure = 0;


//WiFi Client
const char* ssid = "";
const char* password = "";
WiFiClient client;

// IOT Cloud credentials
EIoTCloudRestApi eiotcloud;
#define LDR_ID "570635c7c943a0661cf314d1/fERPFdpr3etTRDqS"

//ThingSpeak credentials
const int CHANNEL_ID = ;
const char * API_KEY = "";


void setup() {
 Serial.begin(9600);
 eiotcloud.begin();
 ThingSpeak.begin(client);
}

void loop() {
  delay(1000);

  exposure = analogRead(pinLdr);
  Serial.println(exposure);
  eiotcloud.sendParameter(LDR_ID, exposure);
  ThingSpeak.writeField(CHANNEL_ID, 2, exposure, API_KEY);
}
