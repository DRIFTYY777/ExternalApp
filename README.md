# External App for ESP32-S3

This project is an external application for the ESP32-S3 that can be booted from OTA. Users can compile the firmware, place it on an SD card, and execute it on their device. After using the external application, users can return to the main firmware by calling `return_to_main_firmware();` using a button or any other method they choose.

## Features
- Boot the external app from OTA.
- Compile the firmware and load it from an SD card.
- Execute the external app seamlessly.
- Return to the main firmware easily with `return_to_main_firmware();`.

## Getting Started

### Prerequisites
- ESP32-S3 board
- SD card formatted as FAT32
- PlatformIO (or Arduino IDE with ESP-IDF support)

### Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/external-app.git
   cd external-app
