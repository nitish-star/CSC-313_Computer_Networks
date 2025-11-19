# Stop-and-Wait ARQ Protocol Simulation in C

This C program simulates the Stop-and-Wait Automatic Repeat reQuest (ARQ) protocol, a fundamental error-control mechanism in data communication systems. The simulation demonstrates how packets are sent, acknowledged, and retransmitted in the presence of a noisy channel.

## Features

- **Packet Transmission:** Simulates the sending of packets with a probability of packet loss.
- **ACK Handling:** Simulates the acknowledgment (ACK) process with a probability of ACK loss.
- **Timeout Mechanism:** Implements a timeout for retransmitting lost packets or ACKs.
- **Sequence Numbering:** Uses alternating sequence numbers (0 and 1) to ensure proper packet acknowledgment.

## How It Works

1. **Sender Side:**
   - Sends a packet with a sequence number (0 or 1).
   - Waits for an acknowledgment (ACK) from the receiver.
   - Retransmits the packet if the packet is lost or if the ACK is not received within the timeout period.

2. **Receiver Side:**
   - Sends an acknowledgment (ACK) for each successfully received packet.
   - Simulates the loss of ACKs based on a user-defined probability.

3. **Channel:**
   - Introduces noise by randomly losing packets or ACKs based on predefined probabilities.

## Inputs

- **Total Packets:** The total number of packets to be transmitted (default: 5).
- **Packet Loss Probability:** 20% chance of packet loss during transmission.
- **ACK Loss Probability:** 20% chance of acknowledgment loss during transmission.

## Outputs

- **Sender Side:**
  - Status of packet transmission (success or loss).
  - Status of acknowledgment reception (success or loss).
  - Retransmission attempts due to timeouts.

- **Receiver Side:**
  - Status of acknowledgment sent for each packet.

## Example Walkthrough

### Input:
- **Total Packets:** 5 (Default value in the program.)
- **Packet Loss Probability:** 20% (Predefined in the program.)
- **ACK Loss Probability:** 20% (Predefined in the program.)

### Process:
1. Packet 1 is sent successfully.
2. Packet 2 is lost; retransmission occurs after a timeout.
3. Packet 3 is sent successfully, but its ACK is lost; retransmission occurs after a timeout.
4. The process continues until all packets are successfully transmitted and acknowledged.

### Output:
```
--- STOP AND WAIT ARQ SIMULATION ---
Total Packets to send: 5

----------------------------------------------
SENDER: Sending Packet 1 (Seq: 0)...
RECEIVER: Received Packet 1.
SENDER: Received ACK for Packet 1.
----------------------------------------------
SENDER: Sending Packet 2 (Seq: 1)...
NETWORK: *** Packet 2 LOST in transit! ***
SENDER: Timeout! Timer Expired.
SENDER: Resending Packet 2...
RECEIVER: Received Packet 2.
SENDER: Received ACK for Packet 2.
----------------------------------------------
...
All packets sent successfully!
```

### Explanation:
This example illustrates how the Stop-and-Wait ARQ protocol ensures reliable data transmission in a noisy channel. Packets and acknowledgments are retransmitted as needed, ensuring that all packets are successfully delivered despite losses in the channel.

## Applications

- Reliable data transmission in communication systems.
- Understanding error-control mechanisms in networking protocols.
- Simulating real-world scenarios with noisy communication channels.