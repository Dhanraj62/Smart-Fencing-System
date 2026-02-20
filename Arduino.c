// Pin definitions
const int pirPin = 2;             // PIR motion sensor output
const int buzzerPin = 7;          // Buzzer output
const int ledPin = 8;             // LED output
const int currentSensorPin = A0;  // ACS712 analog output
const int voltageSensorPin = A1;  // Voltage sensor analog output

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.println("Smart Electric Fence Test Started");
}

void loop() {
  // Read PIR sensor
  int motionDetected = digitalRead(pirPin);

  // Read current sensor (analog value 0-1023)
  int currentValue = analogRead(currentSensorPin);

  // Read voltage sensor (analog value 0-1023)
  int voltageValue = analogRead(voltageSensorPin);

  // Print sensor values
  Serial.print("Motion: ");
  if (motionDetected == HIGH) {
    Serial.print("Motion Detected!");
    digitalWrite(ledPin, HIGH);     // Turn ON LED
    digitalWrite(buzzerPin, HIGH);  // Turn ON buzzer
  } else {
    Serial.print("No Motion");
    digitalWrite(ledPin, LOW);     // Turn OFF LED
    digitalWrite(buzzerPin, LOW);  // Turn OFF buzzer
  }
  Serial.print("\t Current: ");
  Serial.print(currentValue);
  Serial.print("\t Voltage: ");
  Serial.println(voltageValue);

  delay(500);  // Update every 0.5 seconds
}
