# Selective Repeat Sliding Window Protocol Simulation in C

This C program simulates the Selective Repeat Sliding Window protocol, a reliable data transmission mechanism used in communication systems. The simulation demonstrates how packets are sent, acknowledged, and retransmitted in the presence of a noisy channel.

## Features

- **Sliding Window Mechanism:** Implements a sliding window for efficient packet transmission.
- **Packet Transmission:** Simulates the sending of packets with a probability of packet loss.
- **ACK Handling:** Simulates the acknowledgment (ACK) process.
- **Selective Retransmission:** Retransmits only the packets that were lost or not acknowledged.
- **Window Sliding:** Slides the window forward only when the first packet in the window is acknowledged.

## How It Works

1. **Sender Side:**
   - Sends packets within the sliding window.
   - Waits for acknowledgments (ACKs) from the receiver.
   - Retransmits only the packets that were lost or not acknowledged.

2. **Receiver Side:**
   - Sends an acknowledgment (ACK) for each successfully received packet.
   - Simulates the loss of ACKs based on a predefined probability.

3. **Channel:**
   - Introduces noise by randomly losing packets or ACKs based on a predefined probability.

## Inputs

- **Total Packets:** Total number of packets to be transmitted.
- **Window Size:** Number of packets that can be sent without waiting for ACKs.

## Outputs

- **Sender Side:**
  - Status of packet transmission (success or loss).
  - Status of acknowledgment reception (success or loss).
  - Retransmission attempts for lost packets.

- **Receiver Side:**
  - Status of acknowledgment sent for each packet.

## Example Walkthrough

### Input:
- **Total Packets:** 6
- **Window Size:** 3

### Process:
1. Packets 1, 2, and 3 are sent successfully.
2. Packet 4 is lost; retransmission occurs for packet 4.
3. ACK for packet 5 is lost; retransmission occurs for packet 5.
4. The process continues until all packets are successfully transmitted and acknowledged.

### Output:
```
--- SELECTIVE REPEAT PROTOCOL SIMULATION ---
Enter Total Number of Packets: 6
Enter Window Size: 3

----------------------------------------------
Current Window: [ 1 2 3 ]
SENDER: Sending Packet 1...
RECEIVER: Packet 1 Received. ACK Sent.
SENDER: Sending Packet 2...
RECEIVER: Packet 2 Received. ACK Sent.
SENDER: Sending Packet 3...
NETWORK: *** Packet 3 / ACK LOST! ***

SENDER: Packet 1 is Done. Sliding Window.
SENDER: Packet 2 is Done. Sliding Window.

----------------------------------------------
Current Window: [ 3 4 5 ]
SENDER: Sending Packet 3...
RECEIVER: Packet 3 Received. ACK Sent.
SENDER: Sending Packet 4...
NETWORK: *** Packet 4 / ACK LOST! ***
SENDER: Sending Packet 5...
RECEIVER: Packet 5 Received. ACK Sent.
...
All packets sent and acknowledged successfully.
```

### Explanation:
This example illustrates how the Selective Repeat Sliding Window protocol ensures reliable data transmission in a noisy channel. Packets and acknowledgments are retransmitted as needed, ensuring that all packets are successfully delivered despite losses in the channel.

## Applications

- Reliable data transmission in communication systems.
- Understanding error-control mechanisms in networking protocols.
- Simulating real-world scenarios with noisy communication channels.