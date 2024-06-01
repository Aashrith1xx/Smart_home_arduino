#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h> // Include DHT Sensor Library

#define DHTPIN 2  // Define the digital pin for DHT11 sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Format -> (Address,Width,Height )

void setup()
{
  // initialize the lcd
  lcd.init();
  // Turn on the Backlight
  lcd.backlight();

  // Initialize DHT sensor
  dht.begin();

  // Initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Clear the display buffer
  lcd.clear(); 
  
  // Set cursor (Column, Row) for temperature rea…
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2  // Define the digital pin for DHT11 sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object

LiquidCrystal_I2C lcd(0x3F, 16, 2); // Format -> (Address,Width,Height )
const int soundPin = A0; // Sound module pin

void setup()
{
  // initialize the lcd
  lcd.init();
  // Turn on the Backlight
  lcd.backlight();

  // Initialize DHT sensor
  dht.begin();

  // Initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read sound sensor value
  int soundValue = analogRead(soundPin);

  // Clear the display buffer
  lcd.clear(); 
  
  // Set cursor (Column, Row) for temperature reading
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  // Set cursor (Column, Row) for humidity reading
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // Set cursor (Column, Row) for sound sensor reading
  lcd.setCursor(0, 2);
  lcd.print("Sound: ");
  lcd.print(soundValue);
  lcd.print(" dB");

  // Print temperature, humidity, and sound value to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Sound: ");
  Serial.print(soundValue);
  Serial.println(" dB");
  
  delay(1000); // Delay for 1 second before reading again
}
