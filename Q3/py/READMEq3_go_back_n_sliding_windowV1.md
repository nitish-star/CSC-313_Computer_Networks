# Selective Repeat Sliding Window Protocol Simulation in Python

This Python program simulates the Selective Repeat Sliding Window protocol, a reliable data transmission mechanism used in communication systems. The simulation demonstrates how frames are sent, acknowledged, and retransmitted in the presence of a noisy channel.

## Features

- **Sliding Window Mechanism:** Implements a sliding window for efficient frame transmission.
- **Frame Transmission:** Simulates the sending of frames with a probability of frame loss.
- **ACK Handling:** Simulates the acknowledgment (ACK) process with a probability of ACK loss.
- **Timeout Mechanism:** Implements a timeout for retransmitting lost frames or ACKs.
- **Selective Retransmission:** Retransmits only the frames that were lost or not acknowledged.

## How It Works

1. **Sender Side:**
   - Sends frames within the sliding window.
   - Waits for acknowledgments (ACKs) from the receiver.
   - Retransmits only the frames that were lost or not acknowledged within the timeout period.

2. **Receiver Side:**
   - Sends an acknowledgment (ACK) for each successfully received frame.
   - Simulates the loss of ACKs based on a user-defined probability.

3. **Channel:**
   - Introduces noise by randomly losing frames or ACKs based on user-defined probabilities.

## Inputs

- **Total Frames:** Total number of frames to be transmitted.
- **Window Size:** Number of frames that can be sent without waiting for ACKs.
- **Frame Loss Probability:** Probability of a frame being lost during transmission.
- **ACK Loss Probability:** Probability of an acknowledgment being lost during transmission.
- **Timeout:** Time (in seconds) before retransmitting a frame or waiting for an ACK.

## Outputs

- **Sender Side:**
  - Status of frame transmission (success or loss).
  - Status of acknowledgment reception (success or loss).
  - Retransmission attempts due to timeouts.

- **Receiver Side:**
  - Status of acknowledgment sent for each frame.

## Example Walkthrough

### Input:
- **Total Frames:** 6
- **Window Size:** 3
- **Frame Loss Probability:** 0.2
- **ACK Loss Probability:** 0.1
- **Timeout:** 2 seconds

### Process:
1. Frames 0, 1, and 2 are sent successfully.
2. Frame 3 is lost; retransmission occurs after a timeout.
3. ACK for frame 4 is lost; retransmission occurs after a timeout.
4. The process continues until all frames are successfully transmitted and acknowledged.

### Output:
```
--- SELECTIVE REPEAT SLIDING WINDOW PROTOCOL SIMULATION ---

Enter number of frames to send: 6
Enter window size: 3
Enter frame loss probability (0-1): 0.2
Enter ACK loss probability (0-1): 0.1
Enter timeout value (seconds): 2

Sender: Sending frame 0
Sender: Sending frame 1
Sender: Sending frame 2
Sender: Waiting for ACKs...
Receiver: ACK for frame 0
Sender: ACK received for frame 0
Receiver: ACK for frame 1
Sender: ACK received for frame 1
Channel: Frame 2 LOST!
Sender: Timeout for frame 2! Retransmitting...
...
Transmission Complete.
```

### Explanation:
This example illustrates how the Selective Repeat Sliding Window protocol ensures reliable data transmission in a noisy channel. Frames and acknowledgments are retransmitted as needed, ensuring that all frames are successfully delivered despite losses in the channel.

## Applications

- Reliable data transmission in communication systems.
- Understanding error-control mechanisms in networking protocols.
- Simulating real-world scenarios with noisy communication channels.