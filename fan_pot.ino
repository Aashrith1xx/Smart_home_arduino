const int potPin = A0;       // Define the analog pin for the potentiometer
const int fanPin = 9;        // Define the digital pin for the fan

void setup() {
  pinMode(fanPin, OUTPUT);   // Set the fan pin as an output
}

void loop() {
  int potValue = analogRead(potPin);            // Read the potentiometer value
  int fanSpeed = map(potValue, 0, 1023, 0, 255); // Map the potentiometer value to a range from 0 to 255
  analogWrite(fanPin, fanSpeed);                // Set the fan speed using PWM
  delay(10);                                    // Small delay for stability
}
