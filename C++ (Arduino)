#include <Servo.h>
#include <SoftwareSerial.h>

const int bluetoothTxPin = 2; 
const int bluetoothRxPin = 3;
SoftwareSerial bluetooth(bluetoothTxPin, bluetoothRxPin); 

const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 9; 
const int led50cmPin = 5; 
const int led100cmPin = 6;
const int led200cmPin = 7;
const int additionalLedPin = 8;

long duration;
int distance;
const int maxDistance = 500;

Servo myServo; 
unsigned long objectDetectedTime = 0;
bool objectUnder50cm = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led50cmPin, OUTPUT); 
  pinMode(led100cmPin, OUTPUT); 
  pinMode(led200cmPin, OUTPUT); 
  pinMode(additionalLedPin, OUTPUT);
  Serial.begin(9600);  
  bluetooth.begin(9600);

  myServo.attach(12); 
}

void loop() {
  
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle); 
    delay(10);
    distance = calculateDistance(); 

    if (distance > maxDistance) {
      distance = maxDistance; 
    }

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    controlIndicators(distance);
    updateAdditionalLED(distance);
  }

  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle); 
    delay(10);

    distance = calculateDistance(); 

    if (distance > maxDistance) {
      distance = maxDistance; 
    }

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    controlIndicators(distance);
    updateAdditionalLED(distance);
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  int distance = duration * 0.034 / 2; 
  return distance;
}

void controlIndicators(int distance) {
  if (distance <= 50) {
    digitalWrite(led50cmPin, HIGH);
    tone(buzzerPin, 2000); 
    delay(3000); 
    digitalWrite(led50cmPin, LOW);
    noTone(buzzerPin); 
    digitalWrite(led100cmPin, LOW);
    digitalWrite(led200cmPin, LOW);

    if (!objectUnder50cm) {
      objectDetectedTime = millis(); 
      objectUnder50cm = true;
    }

    bluetooth.println("Emergency: Object detected under 50 cm!");
  } else if (distance <= 100) {
    digitalWrite(led100cmPin, HIGH);
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led200cmPin, LOW);
    noTone(buzzerPin); 
    objectUnder50cm = false; 
  } else if (distance <= 200) {
    digitalWrite(led200cmPin, HIGH);
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led100cmPin, LOW);
    noTone(buzzerPin); 
    objectUnder50cm = false; 
  } else {
    digitalWrite(led50cmPin, LOW);
    digitalWrite(led100cmPin, LOW);
    digitalWrite(led200cmPin, LOW);
    noTone(buzzerPin); 
    objectUnder50cm = false; 
  }
}

void updateAdditionalLED(int distance) {
  if (distance <= 50) {
    if (millis() - objectDetectedTime > 3000) {
      digitalWrite(additionalLedPin, HIGH); 
    }
  } else {
    digitalWrite(additionalLedPin, LOW); 
    objectUnder50cm = false; 
  }
}
