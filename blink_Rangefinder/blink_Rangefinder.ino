// Pin definitions for HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// LED pin
const int ledPin = 13;

// Variables for sensor
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the trigPin as OUTPUT, echoPin as INPUT, and ledPin as OUTPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin high for 10 microseconds to send out the ultrasound pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration of the pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Adjust the blink speed based on the distance
  int blinkDelay;
  if (distance < 10) {
    blinkDelay = 50; // Fast blink
  } else if (distance < 20) {
    blinkDelay = 100; // Medium blink
  } else {
    blinkDelay = 500; // Slow blink
  }

  // Blink the LED
  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);
}