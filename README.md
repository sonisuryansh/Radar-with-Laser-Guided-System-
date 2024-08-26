# Radar with Laser-Guided System
This project is a radar-based detection system integrated with a laser-guided mechanism, designed for real-time object detection and response. The system uses an ultrasonic sensor to detect objects at varying distances, activating different visual indicators and an alert system based on the proximity of the object.

# Features
Ultrasonic Sensor Integration: Detects objects at three distance levels (200 cm, 100 cm, 50 cm).
Blue LED indicates an object within 200 cm.
Yellow LED indicates an object within 100 cm.
Red LED and buzzer alert when an object is within 50 cm.
Laser-Guided Activation: When an object is within 50 cm for 3 seconds, the laser system is triggered for 5 seconds.
Serial Communication: Real-time data is sent to a connected PC, with an emergency message popping up when an object is detected within 50 cm.
Processing Visualization: A Processing sketch visualizes radar data, providing a graphical interface to monitor object detection.

# Components
Arduino Uno
Ultrasonic Sensor
LEDs (Blue, Yellow, Red)
Buzzer
Laser Module
Bluetooth Module
Processing Sketch for Visualization

# Usage
This system is ideal for projects requiring automated object detection and response, such as security systems or automated guidance systems. It can be easily adapted and expanded for more complex applications.
