#   2. Simulate and implement stop and wait protocol for noisy channel.

import random
import time

# -------------------------------
# Python program for Stop-and-Wait ARQ Simulation
# -------------------------------
def send_frame(frame_no, loss_prob):
    """Simulate sending frame with probability of loss."""
    print(f"Sender: Sending frame {frame_no}")
    if random.random() < loss_prob:
        print(f"Channel: Frame {frame_no} lost!")
        return False
    return True

def receive_ack(frame_no, loss_prob):
    """Simulate ACK receiving with probability of ACK loss."""
    if random.random() < loss_prob:
        print(f"Channel: ACK for frame {frame_no} lost!")
        return False
    print(f"Receiver: ACK {frame_no} received")
    return True

def stop_and_wait(frames=5, frame_loss=0.2, ack_loss=0.2, timeout=2):
    print("\n--- STOP AND WAIT PROTOCOL SIMULATION (NOISY CHANNEL) ---\n")

    seq = 0  # sequence number (0/1)

    for i in range(frames):
        ack_received = False

        while not ack_received:
            sent_success = send_frame(seq, frame_loss)

            if not sent_success:
                print("Sender: Timeout! Retransmitting frame...\n")
                time.sleep(timeout)
                continue

            print("Sender: Waiting for ACK...")
            time.sleep(1)

            ack_success = receive_ack(seq, ack_loss)

            if ack_success:
                print(f"Sender: ACK {seq} received successfully\n")
                ack_received = True
                seq = 1 - seq  # toggle sequence number
            else:
                print("Sender: ACK timeout! Retransmitting frame...\n")
                time.sleep(timeout)

    print("Transmission complete.\n")

# Run simulation
stop_and_wait(frames=5, frame_loss=0.3, ack_loss=0.2, timeout=2)
