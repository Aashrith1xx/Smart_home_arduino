#define BLYNK_TEMPLATE_ID "TMPL6k7oXylUX"
#define BLYNK_TEMPLATE_NAME "Self Plant Watering System 2"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define waterPump 4 // GPIO4 is D2 on ESP8266
#define soilMoisturePin A0
#define moistureThresholdHigh 30  // Moisture threshold to turn off the pump (%)
#define moistureThresholdLow 20   // Moisture threshold to turn on the pump (%)


char auth[] = "7V2klMevuGCYOjRUZv7vvBfvSBnStzRO";
char ssid[] = "POCO X4 Pro 5G";
char pass[] = "iamrehaan";


bool Relay = false;  // false means pump is off, true means pump is on


BlynkTimer timer;


void setup() {
 Serial.begin(9600);
 pinMode(waterPump, OUTPUT);
 digitalWrite(waterPump, HIGH);


 Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);


 timer.setInterval(1000L, soilMoistureSensor);
}


void loop() {
 Blynk.run();
 timer.run();
}


BLYNK_WRITE(V1) {
 Relay = param.asInt();


 if (Relay) {
   digitalWrite(waterPump, LOW);  // Turn on the pump
 } else {
   digitalWrite(waterPump, HIGH); // Turn off the pump
 }
}


void soilMoistureSensor() {
 int sensorValue = analogRead(soilMoisturePin);
  // Calibrate sensor readings based on your soil conditions
 int moisturePercent = map(sensorValue, 0, 800, 100, 0);  // Adjust range based on calibration


 // Ensure moisture percentage is within valid range (0-100)
 moisturePercent = constrain(moisturePercent, 0, 100);


 // Update Blynk virtual display with moisture percentage
 Blynk.virtualWrite(V0, moisturePercent);


 // Automatic control based on moisture thresholds
 if (moisturePercent > moistureThresholdHigh && Relay) {
   digitalWrite(waterPump, HIGH); // Turn off the pump
   Relay = false;  // Update pump state to off
   Blynk.virtualWrite(V1, Relay);  // Update Blynk button state
 } else if (moisturePercent < moistureThresholdLow && !Relay) {
   digitalWrite(waterPump, LOW);  // Turn on the pump
   Relay = true;  // Update pump state to on
   Blynk.virtualWrite(V1, Relay);  // Update Blynk button state
 }
}
