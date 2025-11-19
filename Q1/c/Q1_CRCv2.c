//   1. Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
#include <stdio.h>
#include <string.h>

// A variable to store the "Check Value" (Remainder)
char check_value[28];

// XOR Function: The heart of CRC
// It compares the bits of the data with the divisor
void xor_operation(char *dividend, char *divisor) {
    int len = strlen(divisor);
    for(int i = 0; i < len; i++) {
        // If bits are same, result is '0'. If different, result is '1'.
        if(dividend[i] == divisor[i])
            dividend[i] = '0';
        else
            dividend[i] = '1';
    }
}

// CRC Function: Performs the division
void crc(char *data, char *divisor) {
    int data_len = strlen(data);
    int div_len = strlen(divisor);
    
    // Copy data to a working variable so we don't destroy the original
    char temp_data[100];
    strcpy(temp_data, data);

    // Loop through the data
    for(int i = 0; i < data_len - (div_len - 1); i++) {
        // If the leading bit is '1', we can divide (XOR)
        if(temp_data[i] == '1') {
            xor_operation(&temp_data[i], divisor);
        }
    }
    
    // The remainder is the last few bits of the temp_data
    // We skip the beginning because the division turns them to 0s
    strcpy(check_value, &temp_data[data_len - (div_len - 1)]);
}

int main() {
    char data[100], divisor[30], codeword[100], received_data[100];

    // --- SENDER SIDE ---
    printf("--- SENDER SIDE ---\n");
    printf("Enter Data Bits: ");
    scanf("%s", data);
    printf("Enter Divisor (Key): ");
    scanf("%s", divisor);

    int data_len = strlen(data);
    int div_len = strlen(divisor);

    // 1. Append zeros (length of divisor - 1)
    strcpy(codeword, data);
    for(int i = 0; i < div_len - 1; i++) {
        strcat(codeword, "0");
    }

    printf("Data padded with zeros: %s\n", codeword);

    // 2. Perform CRC to get the remainder (check_value)
    crc(codeword, divisor);
    printf("CRC (Remainder): %s\n", check_value);

    // 3. Create the final codeword (Data + CRC)
    // Reset codeword to original data first
    strcpy(codeword, data);
    // Append the calculated CRC
    strcat(codeword, check_value);
    
    printf("Final Transmitted Message: %s\n\n", codeword);

    // --- NOISY CHANNEL SIMULATION ---
    printf("--- NOISY CHANNEL ---\n");
    printf("Simulate received message (Enter %s for success, or change a bit for error): ", codeword);
    scanf("%s", received_data);

    // --- RECEIVER SIDE ---
    printf("\n--- RECEIVER SIDE ---\n");
    
    // Perform the exact same division on the received data
    // Important: The 'codeword' here is the padded version (Received Data + 0s is not needed, 
    // because the Received Data ALREADY contains the CRC bits, effectively acting as the padding)
    
    // We pass the received_data directly into the CRC function
    crc(received_data, divisor);
    
    // Check if remainder is all zeros
    int error_found = 0;
    for(int i = 0; i < strlen(check_value); i++) {
        if(check_value[i] == '1') {
            error_found = 1;
            break;
        }
    }

    if(error_found)
        printf("Error Detected! (Remainder is %s)\n", check_value);
    else
        printf("No Error. Data Accepted. (Remainder is %s)\n", check_value);

    return 0;
}