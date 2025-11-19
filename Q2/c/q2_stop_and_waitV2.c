//   2. Simulate and implement stop and wait protocol for noisy channel.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep() function to simulate time delay

#define TOTAL_PACKETS 5

int main() {
    int packet = 1;
    int seq_no = 0; // Sequence number alternates between 0 and 1
    int random_value;
    
    // Seed the random number generator so we get different results each run
    srand(time(0)); 

    printf("--- STOP AND WAIT ARQ SIMULATION ---\n");
    printf("Total Packets to send: %d\n\n", TOTAL_PACKETS);

    while (packet <= TOTAL_PACKETS) {
        // 1. SENDER SENDS PACKET
        printf("----------------------------------------------\n");
        printf("SENDER: Sending Packet %d (Seq: %d)...\n", packet, seq_no);
        
        // Simulate delay
        sleep(1);

        // 2. SIMULATE PACKET LOSS (NOISY CHANNEL)
        // Let's say there is a 20% chance the packet gets lost
        random_value = rand() % 100;
        if (random_value < 20) {
            printf("NETWORK: *** Packet %d LOST in transit! ***\n", packet);
            printf("SENDER: Timeout! Timer Expired.\n");
            printf("SENDER: Resending Packet %d...\n", packet);
            continue; // Restart the loop (Resend)
        }

        // 3. RECEIVER RECEIVES PACKET
        printf("RECEIVER: Received Packet %d.\n", packet);

        // 4. SIMULATE ACK LOSS (NOISY CHANNEL)
        // Let's say there is a 20% chance the ACK gets lost
        random_value = rand() % 100;
        if (random_value < 20) {
            printf("NETWORK: *** ACK for Packet %d LOST in transit! ***\n", packet);
            printf("SENDER: Timeout! Timer Expired (No ACK).\n");
            printf("SENDER: Resending Packet %d...\n", packet);
            // Note: In a real scenario, receiver would detect duplicate here
            continue; // Restart the loop (Resend)
        }

        // 5. SUCCESSFUL ACK
        printf("SENDER: Received ACK for Packet %d.\n", packet);
        
        // Move to next packet and toggle sequence number (0 to 1, or 1 to 0)
        packet++;
        seq_no = !seq_no; 
    }

    printf("\n----------------------------------------------\n");
    printf("All packets sent successfully!\n");

    return 0;
}