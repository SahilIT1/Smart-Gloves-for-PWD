Smart Glove for PWD (Persons with Disabilities)

Overview

The Smart Glove project is designed to assist individuals with disabilities (PWD) in communicating effectively. The glove utilizes an MPU6050 accelerometer and gyroscope sensor to detect specific gestures, which are then converted into text and transmitted via Bluetooth to a companion mobile application. The app further converts the text into speech, enabling real-time communication with those who do not understand sign language.

Features

Gesture Recognition: Detects predefined hand movements using MPU6050 sensor.

Bluetooth Connectivity: Communicates with a mobile application via Bluetooth module.

Text-to-Speech Conversion: The mobile application converts detected gestures into speech.

Portable and Lightweight: Designed for ease of use and comfort.

Real-Time Communication: Helps users interact with non-sign language speakers effectively.

Hardware Components Used

Arduino Nano – Microcontroller for processing input from sensors.

MPU6050 – Accelerometer and gyroscope for gesture detection.

HC-05 Bluetooth Module – Enables wireless communication between glove and mobile app.

DF Mini Player – Handles audio output functionality.

Micro SD Card – Stores pre-recorded audio files.

10 IR Sensors – Additional sensor inputs for gesture detection.

ESP32 – Supports gesture recognition and wireless communication.

Small Speaker – Outputs voice feedback.

Zero PCB – Circuit board for component integration.

Audio Jack – Connects to external audio devices.

Accelerometer – Enhances motion tracking accuracy.

Rechargeable Cells with Holder & Charging Circuit – Provides power supply.

Glove – Worn by the user to detect gestures.

Double-Sided Tape & Jumper Wires – Assembly and wiring components.

How It Works

The PWD wears the glove and performs a gesture.

The MPU6050 sensor detects the movement and sends data to the Arduino Nano.

The Arduino processes the data and transmits it via the Bluetooth module (HC-05).

The mobile application receives the data, converts it into text, and then into speech.

The audio output is played through the speaker, enabling real-time communication.

Future Enhancements

AI-based Gesture Recognition: Implement machine learning for adaptive gesture detection.

Multi-Language Support: Expand speech output to support multiple languages.

Cloud Integration: Enable online storage and analytics for improved performance.

Customizable Gestures: Allow users to define and store their own gesture-speech mappings.

Longer Battery Life: Optimize power consumption for extended usage.

Conclusion

This Smart Glove project bridges the communication gap for PWD by converting gestures into speech, enhancing accessibility, and promoting inclusivity. Future developments aim to improve recognition accuracy and expand language support, making it a more powerful assistive tool.

