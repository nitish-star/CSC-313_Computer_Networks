#   1. Simulate Cyclic Redundancy Check (CRC) error detection algorithm for noisy channel.
import random
# -------------------------------
# Python program for Cyclic Redundancy Check (CRC) Simulation
# -------------------------------
def xor(a, b):
    """Perform XOR between two binary strings."""
    result = ""
    for i in range(1, len(b)):
        result += '0' if a[i] == b[i] else '1'
    return result

def mod2div(dividend, divisor):
    """Modulo-2 division used in CRC."""
    pick = len(divisor)
    tmp = dividend[0:pick]

    while pick < len(dividend):
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + dividend[pick]
        else:
            tmp = xor('0'*pick, tmp) + dividend[pick]
        pick += 1

    # Last step
    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0'*pick, tmp)

    return tmp

def introduce_noise(codeword, probability):
    """Flip random bits based on noise probability."""
    noisy = ""
    for bit in codeword:
        if random.random() < probability:
            noisy += '1' if bit == '0' else '0'
        else:
            noisy += bit
    return noisy

# ----------------- Main Program -----------------

data = input("Enter data bits (e.g., 1001001): ")
divisor = input("Enter generator polynomial (e.g., 1101): ")

noise_prob = float(input("Enter noise probability (0–1): "))

print("\n--- CRC ERROR DETECTION SIMULATION ---\n")

# Append zeros = length(divisor) - 1
l_key = len(divisor)
appended_data = data + '0'*(l_key - 1)

# Calculate remainder
remainder = mod2div(appended_data, divisor)

# Form codeword
codeword = data + remainder

print(f"Sender Side:")
print(f"Data    :    {data}")
print(f"CRC     :    {remainder}")
print(f"Codeword:    {codeword}\n")

# Introduce noise
noisy_codeword = introduce_noise(codeword, noise_prob)

print(f"Channel Output (Noisy): {noisy_codeword}")

# Receiver computes remainder again
received_remainder = mod2div(noisy_codeword, divisor)

print(f"Receiver Side Remainder: {received_remainder}")

# Check for error
if "1" in received_remainder:
    print("\nResult: ERROR DETECTED ")
else:
    print("\nResult: NO ERROR ")
