#   3. Simulate and implement go back n sliding window protocol.

import random
import time

# -------------------------------
# Python program for Repeat ARQ Simulation
# -------------------------------

def send_frame(frame_no, loss_prob):
    """Simulate sending a frame."""
    print(f"Sender: Sending frame {frame_no}")
    if random.random() < loss_prob:
        print(f"Channel: Frame {frame_no} LOST!")
        return False
    return True


def receive_ack(frame_no, loss_prob):
    """Simulate ACK receiving."""
    if random.random() < loss_prob:
        print(f"Channel: ACK {frame_no} LOST!")
        return False
    print(f"Receiver: ACK for frame {frame_no}")
    return True


def selective_repeat(total_frames, window_size, frame_loss, ack_loss, timeout):
    print("\n--- SELECTIVE REPEAT SLIDING WINDOW PROTOCOL SIMULATION ---\n")

    base = 0
    next_frame = 0
    frame_status = ["pending"] * total_frames   # pending, sent, acked

    while base < total_frames:

        # Send frames within window
        while next_frame < base + window_size and next_frame < total_frames:
            if frame_status[next_frame] == "pending":
                send_frame(next_frame, frame_loss)
                frame_status[next_frame] = "sent"
                time.sleep(0.5)
            next_frame += 1

        print("Sender: Waiting for ACKs...\n")
        time.sleep(timeout)

        # Check ACK for each frame in the window
        for f in range(base, min(base + window_size, total_frames)):
            if frame_status[f] == "sent":    # Not yet acknowledged
                ack_ok = receive_ack(f, ack_loss)

                if ack_ok:
                    frame_status[f] = "acked"
                    print(f"Sender: ACK received for frame {f}\n")
                else:
                    print(f"Sender: Timeout for frame {f}! Retransmitting...\n")
                    send_frame(f, frame_loss)

        # Slide base (continuous ACKed frames)
        while base < total_frames and frame_status[base] == "acked":
            base += 1

    print("Transmission Complete.\n")


# ------------ Command-line Input Section -------------
if __name__ == "__main__":
    total_frames = int(input("Enter number of frames to send: "))
    window_size  = int(input("Enter window size: "))
    frame_loss   = float(input("Enter frame loss probability (0-1): "))
    ack_loss     = float(input("Enter ACK loss probability (0-1): "))
    timeout      = float(input("Enter timeout value (seconds): "))

    selective_repeat(total_frames, window_size, frame_loss, ack_loss, timeout)
