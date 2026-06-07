# Smart Plant Growth Monitoring System in Vertical Farming

## Overview

This project monitors plant growth using an ESP32 and HC-SR04 ultrasonic sensor.

The system measures plant height, applies Simple Moving Average (SMA) filtering to reduce noise, and generates daily growth reports.

## Features

- Plant height measurement
- Ultrasonic sensing (HC-SR04)
- ESP32 processing
- SMA filtering
- Daily growth calculation
- Serial Monitor output
- WiFi-ready architecture

## Hardware

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires
- Power Bank

## Software

- Arduino IDE
- C++
- SMA Filtering Algorithm

## System Workflow

HC-SR04 → Distance Calculation → Plant Height Calculation → SMA Filter → ESP32 Processing → Output

## Results

- Accuracy: 92%
- Noise Reduction: 75%
- Standard Deviation Reduced:
  - Raw Data: 0.80 cm
  - Filtered Data: 0.20 cm

## Author

Akhila JayakumariAnand
Industrial Inter Things Project
