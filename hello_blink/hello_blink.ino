// Pin for the built-in LED
int ledPin = 13;

// Setup function runs once when the Arduino is powered on or reset
void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

// Loop function runs over and over again forever
void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 100 milliseconds (0.1 second)

  // Turn the LED off
  digitalWrite(ledPin, LOW);
  delay(100); // Wait for 100 milliseconds (0.1 second)
}
