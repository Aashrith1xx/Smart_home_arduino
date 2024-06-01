const int potPin = A0;
const int fanPin = 9;
void setup {
pinMode(fanPin, OUTPUT);
}
void loop ( {
int potValue = analogRead (potPin);
int fanSpeed = map (potValue, 0, 1023,
0, 255);
analogWrite(fanPin, fanSpeed);
delay (10);
