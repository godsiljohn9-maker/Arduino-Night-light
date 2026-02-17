// Pin definitions
const int ldrPin = A0;     // Photoresistor connected to A0
const int ledPin1 = 6;     // LED 1 connected to D6
const int ledPin2 = 7;     // LED 2 connected to D7

// Set your light threshold (adjust if needed)
const int threshold = 500; 

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600); // For testing and calibration
}

void loop() {
  int lightValue = analogRead(ldrPin); // Read light level
  Serial.println(lightValue);          // Print value to Serial Monitor
  
  if (lightValue < threshold) {
    // Dark room → Turn LEDs ON
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    // Bright room → Turn LEDs OFF
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  delay(200); // Small delay for stability
}
