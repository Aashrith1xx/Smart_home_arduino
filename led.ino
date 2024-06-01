// Define the pins for the LEDs
const int numLeds = 6;
int ledPins[numLeds] = {2, 3, 4, 5, 6, 7};

void setup() {
  // Set all LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Loop through each LED in forward direction
  for (int i = 0; i < numLeds; i++) {
    // Turn on current LED
    digitalWrite(ledPins[i], HIGH);
    // Turn off previous LED
    if (i > 0) {
      digitalWrite(ledPins[i - 1], LOW);
    }
    delay(100); // Adjust delay time for speed
  }

  // Loop through each LED in backward direction
  for (int i = numLeds - 1; i >= 0; i--) {
    // Turn on current LED
    digitalWrite(ledPins[i], HIGH);
    // Turn off previous LED
    if (i < numLeds - 1) {
      digitalWrite(ledPins[i + 1], LOW);
    }
    delay(100); // Adjust delay time for speed
  }
}
