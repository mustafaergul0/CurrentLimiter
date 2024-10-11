# Arduino Current Limiting Circuit

## Overview

This project demonstrates how to control the current flowing through a load using an Arduino, MOSFET, and ACS712 current sensor. The circuit limits the current to a predefined threshold (2A in this case) and cuts off the power if the current exceeds this limit, similar to a circuit breaker in electrical systems.

## Components Used

- **Arduino Uno**: The main microcontroller for the project.
- **MOSFET (IRLZ44N)**: Used to control the power to the load.
- **ACS712 Current Sensor**: Measures the current flowing through the circuit.
- **Resistors**: To create loads with specific current draw characteristics.
- **Breadboard and Jumper Wires**: For building the circuit.

## Circuit Diagram

![Circuit Diagram](https://github.com/user-attachments/assets/dab5ce22-911a-4705-aac6-4656394c688f)


In this circuit:
- Load resistance is used to simulate different current draws. 
- For example, to draw 1A, use a 24Ω resistor; for 2A, use a 12Ω resistor, and so on, up to 10A.

### Current Calculation Table

| Current (A) | Resistance (Ω) |
|-------------|----------------|
| 1           | 24             |
| 2           | 12             |
| 3           | 8              |
| 4           | 6              |
| 5           | 4.8            |
| 6           | 4              |
| 7           | 3.43           |
| 8           | 3              |
| 9           | 2.67           |
| 10          | 2.4            |

### Mathematical Calculation

The current flowing through the load can be calculated using Ohm's law: 

 I = V/R

Where:
- \( I \) = Current (A)
- \( V \) = Voltage across the load (24V)
- \( R \) = Resistance (Ω)

## Code Explanation

The Arduino code reads the current sensor value, calculates the current flowing through the load, and compares it to the set limit. If the current exceeds the limit, the MOSFET is turned off to protect the circuit.

1. **Pin Setup**: The analog input pin is set up to read values from the ACS712.
2. **Sensitivity**: The sensitivity factor for the ACS712-30 is set for accurate current readings.
3. **PWM Control**: The PWM output is configured to control the MOSFET based on the current readings.
4. **Current Measurement**: The current is calculated and printed to the serial monitor.
5. **Current Limiting**: If the current exceeds the predefined limit (2A), the MOSFET is turned off.

## How to Use

1. Connect the components according to the circuit diagram.
2. Upload the code to the Arduino.
3. Open the Serial Monitor to view the measured current and any notifications about current limits.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the Arduino community for inspiration and support!
