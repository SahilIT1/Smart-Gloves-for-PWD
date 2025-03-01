Smart Glove for Speech Impaired Individuals

Overview

The Smart Glove is an assistive technology device designed to help individuals with speech impairments communicate effectively. By detecting hand gestures using an MPU6050 accelerometer and gyroscope, the glove translates sign language into text and converts it into speech through a mobile application. The application connects to the glove via Bluetooth, ensuring seamless communication for users who rely on sign language.

Features

Gesture Recognition: Uses MPU6050 accelerometer and gyroscope to detect hand movements.

Bluetooth Connectivity: Wirelessly transmits data from the glove to the mobile application.

Text-to-Speech Conversion: Converts recognized gestures into text, which is then spoken aloud via the app.

User-Friendly Interface: Simple and intuitive mobile application for easy communication.

Portable and Wearable: Designed for everyday use with lightweight and flexible materials.

Hardware Components

Arduino Nano – Microcontroller for processing sensor data.

MPU6050 Accelerometer & Gyroscope – Motion detection and gesture recognition.

Bluetooth Module (HC-05/HC-06/ESP32) – Wireless communication between the glove and mobile application.

DF Mini Player – Audio playback for speech output.

Micro SD Card – Stores pre-recorded speech files.

IR Sensors (10x) – Additional gesture tracking support.

Small Speaker – Outputs synthesized speech.

Zero PCB – Circuit mounting for compact design.

Rechargeable Batteries & Charging Circuit – Power source for portable usage.

Glove – Wearable material for sensor attachment.

Jumper Wires & Double-Sided Tape – Connections and secure sensor placement.

How It Works

The user wears the smart glove and makes predefined hand gestures.

The MPU6050 sensor detects the movement and sends data to the Arduino Nano.

The Arduino processes the data and transmits it via Bluetooth to the mobile application.

The mobile application maps the received data to predefined text phrases.

The app converts the text to speech, allowing others to understand what the user is communicating.

Installation & Usage

Glove Setup:

Assemble the hardware components as per the circuit diagram.

Upload the Arduino code to the Arduino Nano.

Ensure the Bluetooth module is properly paired with the mobile device.

Mobile Application:

Install the smart glove application on your Android device.

Pair the application with the Bluetooth module.

Start making gestures, and the application will convert them into speech.

Future Enhancements

Integration with AI-based gesture recognition for improved accuracy.

Expansion of supported languages for broader usability.

Development of a more compact and ergonomic design.

Contributors

Sahil Shaikh - Developer & Researcher

License

This project is open-source and available for modification and enhancement. Feel free to contribute and improve accessibility for those in need.

![image](https://github.com/user-attachments/assets/fb28ed60-63a9-4b7b-b344-5acf4611ddcc)
