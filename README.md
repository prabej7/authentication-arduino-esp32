# Authentication System Using Arduino and ESP32

This project implements an authentication system using an Arduino and an ESP32 microcontroller. The system utilizes a keypad for user input, communicates via serial between the Arduino and ESP32, and serves authentication responses via a web server.

## Features
- **User Authentication via Keypad**: Users enter a password using a 4x4 matrix keypad.
- **Serial Communication**: The Arduino sends authentication results to the ESP32 over Serial2.
- **Web Server**: The ESP32 runs a web server to display authentication status.
- **LED Indicators**: LED signals for login success and failure.

## Tech Stack
- **Arduino**: Handles user input from the keypad and processes authentication.
- **ESP32**: Hosts a web server and manages communication with the Arduino.
- **C++ (Arduino Core)**: Code written for both devices.
- **FirebaseJson Library**: JSON formatting for web responses.
- **Wi-Fi Connectivity**: ESP32 connects to a specified Wi-Fi network.

## Installation & Setup
### Requirements
- **Hardware**:
  - Arduino Uno/Nano (or compatible)
  - ESP32 (DevKit V1 recommended)
  - 4x4 Keypad
  - LED Indicators (optional)
  - Jumper wires

- **Software**:
  - Arduino IDE
  - ESP32 Board Manager installed in Arduino IDE
  - Required libraries: `WiFi`, `WebServer`, `FirebaseJson`

### Wiring Diagram
| Component | Arduino Pin | ESP32 Pin |
|-----------|------------|-----------|
| Keypad Rows (4) | D2 - D5 | - |
| Keypad Columns (4) | D6 - D9 | - |
| Serial TX | D10 | RX (16) |
| Serial RX | D11 | TX (17) |
| LED (Success) | D12 | - |
| LED (Failure) | D13 | - |

### Uploading Code
1. **Arduino**
   - Open `authentication_system.ino` in Arduino IDE.
   - Select the correct board and port.
   - Upload the code.
2. **ESP32**
   - Open `esp32_server.ino`.
   - Modify the Wi-Fi SSID and password.
   - Upload the code.

## Usage
1. Power up both Arduino and ESP32.
2. Connect ESP32 to the Wi-Fi network.
3. Enter the password on the keypad.
4. Authentication result is displayed via LED and sent to the ESP32.
5. Check the authentication status at `http://<ESP32_IP>/`.

## Troubleshooting
- **ESP32 not connecting to Wi-Fi**: Double-check the SSID and password in `esp32_server.ino`.
- **No response from Arduino**: Ensure the correct baud rate and Serial2 pins are configured.
- **Incorrect string comparison in ESP32**: Use `trim()` or `equals()` to avoid whitespace issues.

## Future Improvements
- Implement an LCD display for feedback.
- Store multiple user credentials in EEPROM.
- Enhance security with encrypted communication.

## Author
Developed by [@prabej7](https://github.com/prabej7). Contributions and improvements are welcome!

