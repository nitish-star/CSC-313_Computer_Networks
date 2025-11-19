# Stop-and-Wait ARQ Protocol Simulation

This Python program simulates the Stop-and-Wait Automatic Repeat reQuest (ARQ) protocol, a fundamental error-control mechanism in data communication systems. The simulation demonstrates how frames are sent, acknowledged, and retransmitted in the presence of a noisy channel.

## Features

- **Frame Transmission:** Simulates the sending of frames with a probability of frame loss.
- **ACK Handling:** Simulates the acknowledgment (ACK) process with a probability of ACK loss.
- **Timeout Mechanism:** Implements a timeout for retransmitting lost frames or ACKs.
- **Sequence Numbering:** Uses alternating sequence numbers (0 and 1) to ensure proper frame acknowledgment.

## How It Works

1. **Sender Side:**
   - Sends a frame with a sequence number (0 or 1).
   - Waits for an acknowledgment (ACK) from the receiver.
   - Retransmits the frame if the frame is lost or if the ACK is not received within the timeout period.

2. **Receiver Side:**
   - Sends an acknowledgment (ACK) for each successfully received frame.
   - Simulates the loss of ACKs based on a user-defined probability.

3. **Channel:**
   - Introduces noise by randomly losing frames or ACKs based on user-defined probabilities.

## Inputs

- **Number of Frames:** Total number of frames to be transmitted (default: 5).
- **Frame Loss Probability:** Probability of a frame being lost during transmission (default: 0.3).
- **ACK Loss Probability:** Probability of an acknowledgment being lost during transmission (default: 0.2).
- **Timeout:** Time (in seconds) before retransmitting a frame or waiting for an ACK (default: 2 seconds).

## Outputs

- **Sender Side:**
  - Status of frame transmission (success or loss).
  - Status of acknowledgment reception (success or loss).
  - Retransmission attempts due to timeouts.

- **Receiver Side:**
  - Status of acknowledgment sent for each frame.

## Example Walkthrough

This example demonstrates the Stop-and-Wait ARQ protocol in a noisy channel with frame and ACK loss probabilities.

### Input:
- **Number of Frames:** 5 (Total frames to be transmitted.)
- **Frame Loss Probability:** 0.3 (Probability of a frame being lost during transmission.)
- **ACK Loss Probability:** 0.2 (Probability of an acknowledgment being lost during transmission.)
- **Timeout:** 2 seconds (Time before retransmitting a frame or waiting for an ACK.)

### Process:
1. Frame 0 is sent successfully.
2. ACK 0 is lost; frame 0 is retransmitted after a timeout.
3. Frame 1 is sent successfully and acknowledged.
4. Frame 2 is lost; retransmission occurs after a timeout.
5. The process continues until all frames are successfully transmitted and acknowledged.

### Output:
```
--- STOP AND WAIT PROTOCOL SIMULATION (NOISY CHANNEL) ---

Sender: Sending frame 0
Channel: ACK for frame 0 lost!
Sender: Timeout! Retransmitting frame...
Sender: Sending frame 0
Receiver: ACK 0 received
Sender: ACK 0 received successfully
Sender: Sending frame 1
Receiver: ACK 1 received
Sender: ACK 1 received successfully
Sender: Sending frame 2
Channel: Frame 2 lost!
Sender: Timeout! Retransmitting frame...
Sender: Sending frame 2
Receiver: ACK 2 received
Sender: ACK 2 received successfully
...
Transmission complete.
```

### Explanation:
This example illustrates how the Stop-and-Wait ARQ protocol ensures reliable data transmission in a noisy channel. Frames and acknowledgments are retransmitted as needed, ensuring that all frames are successfully delivered despite losses in the channel.

## Functions

### `send_frame(frame_no, loss_prob)`
Simulates the sending of a frame with a given probability of loss.

### `receive_ack(frame_no, loss_prob)`
Simulates the reception of an acknowledgment (ACK) with a given probability of loss.

### `stop_and_wait(frames, frame_loss, ack_loss, timeout)`
Implements the Stop-and-Wait ARQ protocol, handling frame transmission, acknowledgment, and retransmission in a noisy channel.

## Applications

- Reliable data transmission in communication systems.
- Understanding error-control mechanisms in networking protocols.
- Simulating real-world scenarios with noisy communication channels.