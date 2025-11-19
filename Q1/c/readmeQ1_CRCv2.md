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

This example demonstrates the CRC process step-by-step, including user inputs, intermediate calculations, and the final output.

### Input:
- **Data Bits:** `10101010` (User enters the binary data to be transmitted.)
- **Generator Polynomial (Key):** `101` (User provides the divisor for CRC computation.)
- **Received Message:** `10101001100` (User simulates the received message, introducing an error in the 8th bit.)

### Process:
1. **Sender Side:**
   - Data padded with zeros: `1010101000` (Zeros are appended to the data based on the length of the divisor minus one.)
   - CRC Remainder: `00` (Computed using modulo-2 division.)
   - Final Transmitted Codeword: `1010101000` (Original data combined with the CRC remainder.)

2. **Noisy Channel:**
   - Simulated Received Message: `10101001100` (An error is introduced in the 8th bit of the transmitted codeword.)

3. **Receiver Side:**
   - Remainder after division: `10` (Computed using the received message and the divisor.)
   - Error Detected: Yes (The non-zero remainder indicates an error in the received message.)

### Output:
- **Sender Side:**
  - Data padded with zeros: `1010101000`
  - CRC Remainder: `00`
  - Final Transmitted Codeword: `1010101000`
- **Receiver Side:**
  - Remainder: `10`
  - Error Detected: Yes

### Explanation:
This example illustrates how the CRC algorithm detects errors in transmitted data. The sender computes the CRC remainder and appends it to the data to form the codeword. During transmission, an error is introduced in the 8th bit. At the receiver's end, the CRC remainder is recomputed using the received message. Since the remainder is non-zero (`10`), the program correctly identifies that an error occurred during transmission.

## Functions

### `xor_operation(char *dividend, char *divisor)`
Performs a bitwise XOR operation between two binary strings.

### `crc(char *data, char *divisor)`
Implements modulo-2 division to compute the CRC remainder.

## Applications

- Ensuring data integrity in communication systems
- Detecting errors in transmitted data
- Simulating real-world communication scenarios