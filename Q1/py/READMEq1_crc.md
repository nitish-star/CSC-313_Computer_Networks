# Cyclic Redundancy Check (CRC) Simulation in C

This program simulates the Cyclic Redundancy Check (CRC) process, a widely used error-detection technique in data communication systems. It demonstrates how CRC can detect errors introduced during data transmission.

## Features

- **Modulo-2 Division:** Implements the CRC algorithm using modulo-2 division.
- **Error Simulation:** Allows the user to simulate errors in the transmitted codeword.
- **Error Detection:** Verifies the integrity of the received codeword by recomputing the CRC remainder.

## How It Works

### Sender Side:
1. The user inputs the data bits and the generator polynomial (divisor).
2. Zeros (length of divisor - 1) are appended to the data bits.
3. The CRC remainder is computed using modulo-2 division.
4. The remainder is appended to the original data to form the codeword.

### Noisy Channel:
- The user can simulate the received message by entering the transmitted codeword or modifying it to introduce errors.

### Receiver Side:
1. The program recomputes the CRC remainder using the received codeword and the divisor.
2. If the remainder contains any '1', an error is detected; otherwise, the transmission is considered error-free.

## Inputs

- **Data Bits:** Binary string representing the data to be transmitted (e.g., `1001001`).
- **Generator Polynomial:** Binary string representing the divisor (e.g., `1101`).
- **Received Message:** Binary string representing the received codeword (can be modified to simulate errors).

## Outputs

- **Sender Side:**
  - Data padded with zeros
  - CRC remainder
  - Final transmitted codeword

- **Receiver Side:**
  - Remainder computed from the received codeword
  - Error detection result

## Example Usage

1. Compile the program:
   ```bash
   gcc Q1_CRCv2.c -o crc_simulation
   ```

2. Run the program:
   ```bash
   ./crc_simulation
   ```

3. Enter the following inputs:
   - Data bits: `1001001`
   - Generator polynomial: `1101`
   - Received message: `1001001110` (or modify it to simulate errors)

4. Observe the outputs:
   - Sender side details (data, CRC, codeword)
   - Receiver side remainder and error detection result

## Example Walkthrough

### Input:
- **Data Bits:** `1101011011`
- **Generator Polynomial:** `10011`
- **Received Message:** `11010110111110` (with an error introduced in the last bit)

### Process:
1. **Sender Side:**
   - Data padded with zeros: `11010110110000`
   - CRC Remainder: `1110`
   - Final Transmitted Codeword: `11010110111110`

2. **Noisy Channel:**
   - Simulated Received Message: `11010110111110` (error introduced in the last bit)

3. **Receiver Side:**
   - Remainder after division: `0011`
   - Error Detected: Yes

### Output:
- **Sender Side:**
  - Data padded with zeros: `11010110110000`
  - CRC Remainder: `1110`
  - Final Transmitted Codeword: `11010110111110`
- **Receiver Side:**
  - Remainder: `0011`
  - Error Detected: Yes

## Functions

### `xor_operation(char *dividend, char *divisor)`
Performs a bitwise XOR operation between two binary strings.

### `crc(char *data, char *divisor)`
Implements modulo-2 division to compute the CRC remainder.

## Applications

- Ensuring data integrity in communication systems
- Detecting errors in transmitted data
- Simulating real-world communication scenarios

