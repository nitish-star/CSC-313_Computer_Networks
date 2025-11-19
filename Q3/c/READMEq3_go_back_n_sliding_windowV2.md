# Go-Back-N Sliding Window Protocol Simulation in C

This C program simulates the Go-Back-N Sliding Window protocol, a reliable data transmission mechanism used in communication systems. The simulation demonstrates how packets are sent, acknowledged, and retransmitted in the presence of a noisy channel.

## Features

- **Sliding Window Mechanism:** Implements a sliding window for efficient packet transmission.
- **Packet Transmission:** Simulates the sending of packets with a probability of packet loss.
- **ACK Handling:** Simulates the acknowledgment (ACK) process.
- **Timeout Mechanism:** Implements a timeout for retransmitting lost packets.
- **Go-Back-N Logic:** Retransmits all packets starting from the first lost packet.

## How It Works

1. **Sender Side:**
   - Sends packets within the sliding window.
   - Waits for acknowledgments (ACKs) from the receiver.
   - Retransmits all packets starting from the first lost packet if an ACK is not received.

2. **Receiver Side:**
   - Sends an acknowledgment (ACK) for each successfully received packet.
   - Discards out-of-order packets.

3. **Channel:**
   - Introduces noise by randomly losing packets based on a predefined probability.

## Inputs

- **Total Packets:** Total number of packets to be transmitted.
- **Window Size:** Number of packets that can be sent without waiting for ACKs.

## Outputs

- **Sender Side:**
  - Status of packet transmission (success or loss).
  - Status of acknowledgment reception (success or loss).
  - Retransmission attempts due to timeouts.

- **Receiver Side:**
  - Status of acknowledgment sent for each packet.

## Example Walkthrough

### Input:
- **Total Packets:** 6
- **Window Size:** 3

### Process:
1. Packets 1, 2, and 3 are sent successfully.
2. Packet 4 is lost; retransmission occurs for packets 4, 5, and 6.
3. The process continues until all packets are successfully transmitted and acknowledged.

### Output:
```
--- GO BACK N PROTOCOL SIMULATION ---
Enter Total Number of Packets: 6
Enter Window Size: 3

----------------------------------------------
SENDER: Sending Window starting from Packet 1
SENDER: Sending Packet 1
SENDER: Sending Packet 2
SENDER: Sending Packet 3
RECEIVER: Received Packet 1. Sending ACK.
RECEIVER: Received Packet 2. Sending ACK.
NETWORK: *** Packet 3 LOST! ***

SENDER: Timeout! ACK missing for Packet 3.
SENDER: Go Back N triggered. Resetting window to Packet 3.

----------------------------------------------
SENDER: Sending Window starting from Packet 3
SENDER: Sending Packet 3
SENDER: Sending Packet 4
SENDER: Sending Packet 5
RECEIVER: Received Packet 3. Sending ACK.
RECEIVER: Received Packet 4. Sending ACK.
RECEIVER: Received Packet 5. Sending ACK.

----------------------------------------------
Transmission Complete. All 6 packets sent.
```

### Explanation:
This example illustrates how the Go-Back-N Sliding Window protocol ensures reliable data transmission in a noisy channel. When a packet is lost, all subsequent packets are retransmitted, ensuring that the receiver processes packets in the correct order.

## Applications

- Reliable data transmission in communication systems.
- Understanding error-control mechanisms in networking protocols.
- Simulating real-world scenarios with noisy communication channels.