#include <Servo.h>
#include <SoftwareSerial.h>  // Include the SoftwareSerial library

// Define pins for SoftwareSerial (Bluetooth)
const int bluetoothTxPin = 2; // TX pin for SoftwareSerial (connect to RX on Bluetooth module)
const int bluetoothRxPin = 3; // RX pin for SoftwareSerial (connect to TX on Bluetooth module)
SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin); // Create a SoftwareSerial object

// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 9;    // Buzzer pin
const int led50cmPin = 5;  // LED for objects under 50 cm
const int led100cmPin = 6; // LED for objects under 100 cm
const int led200cmPin = 7; // LED for objects under 200 cm
const int additionalLedPin = 8; // Additional LED pin for object under 50 cm for more than 3 seconds

// Variables for the duration and the distance
long duration;
int distance;
const int maxDistance = 500;  // Assume 500 cm as "infinity" when no object is detected

Servo myServo;  // Creates a servo object for controlling the servo motor

// Variables to track time
unsigned long objectDetectedTime = 0;
bool objectUnder50cm = false;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  pinMode(buzzerPin, OUTPUT); // Sets the buzzer pin as an Output
  pinMode(led50cmPin, OUTPUT); // Sets the 50 cm LED pin as an Output
  pinMode(led100cmPin, OUTPUT); // Sets the 100 cm LED pin as an Output
  pinMode(led200cmPin, OUTPUT); // Sets the 200 cm LED pin as an Output
  pinMode(additionalLedPin, OUTPUT); // Sets the additional LED pin as an Output

  Serial.begin(9600);  // Initialize serial communication for PC
  bluetooth.begin(9600); // Initialize serial communication for Bluetooth module

  myServo.attach(12); // Defines on which pin the servo motor is attached
}

void loop() {
  // Rotates the servo motor from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle); // Move the servo to the current angle
    delay(10); // Reduced delay for faster rotation

    distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

    if (distance > maxDistance) {
      distance = maxDistance; // Cap the distance at the maxDistance (500 cm) to simulate "infinity"
    }

    Serial.print(angle); // Sends the current degree into the Serial Port
    Serial.print(",");
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print(".");

    // Control LEDs and buzzer based on distance
    controlIndicators(distance);
    // Update additional LED based on duration
    updateAdditionalLED(distance);
  }

  // Rotates the servo motor from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle); // Move the servo to the current angle
    delay(10); // Reduced delay for faster rotation

    distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

    if (distance > maxDistance) {
      distance = maxDistance; // Cap the distance at the maxDistance (500 cm) to simulate "infinity"
    }

    Serial.print(angle); // Sends the current degree into the Serial Port
    Serial.print(",");
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print(".");

    // Control LEDs and buzzer based on distance
    controlIndicators(distance);
    // Update additional LED based on duration
    updateAdditionalLED(distance);
  }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  int distance = duration * 0.034 / 2; // Converts duration to distance in cm
  return distance;
}

// Function to control LEDs and buzzer based on distance
void controlIndicators(int distance) {
  // Control LEDs based on distance
  if (distance <= 50) {
    digitalWrite(led50cmPin, HIGH);
    tone(buzzerPin, 2000); // Turn on buzzer at 2000 Hz
    delay(3000); // Keep LED and buzzer on for 3 seconds
    digitalWrite(led50cmPin, LOW);
    noTone(buzzerPin); // Turn off buzzer
    // Turn off other LEDs
    digitalWrite(led100cmPin, LOW);
    digitalWrite(led200cmPin, LOW);

    // Track time when the object is within 50 cm
    if (!objectUnder50cm) {
      objectDetectedTime = millis(); // Start tracking time
      objectUnder50cm = true;
    }

    // Send emergency message via Bluetooth
    bluetooth.println("Emergency: Object detected under 50 cm!");
  } else if (distance <= 100) {
    digitalWrite(led100cmPin, HIGH);
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led200cmPin, LOW);
    noTone(buzzerPin); // Ensure buzzer is off
    objectUnder50cm = false; // Reset time tracking
  } else if (distance <= 200) {
    digitalWrite(led200cmPin, HIGH);
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led100cmPin, LOW);
    noTone(buzzerPin); // Ensure buzzer is off
    objectUnder50cm = false; // Reset time tracking
  } else {
    // Turn off all LEDs and buzzer
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led100cmPin, LOW);
    digitalWrite(led200cmPin, LOW);
    noTone(buzzerPin); // Ensure buzzer is off
    objectUnder50cm = false; // Reset time tracking
  }
}

// Function to control additional LED based on time
void updateAdditionalLED(int distance) {
  if (distance <= 50) {
    // Check if object has been under 50 cm for more than 3 seconds
    if (millis() - objectDetectedTime > 3000) {
      digitalWrite(additionalLedPin, HIGH); // Turn on the additional LED
    }
  } else {
    digitalWrite(additionalLedPin, LOW); // Turn off the additional LED if object is not within 50 cm
    objectUnder50cm = false; // Reset time tracking
  }
}
