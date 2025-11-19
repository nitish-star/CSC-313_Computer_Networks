#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int total_packets, window_size;
    int i, random_value;
    
    // This array will track if a packet has been ACKed (1) or not (0)
    // We make it large enough to handle the input
    int ack_received[100] = {0}; 

    srand(time(0));

    printf("--- SELECTIVE REPEAT PROTOCOL SIMULATION ---\n");
    printf("Enter Total Number of Packets: ");
    scanf("%d", &total_packets);
    printf("Enter Window Size: ");
    scanf("%d", &window_size);

    int window_start = 1; // The "Base" of the window

    // Loop until the window slides past the last packet
    while (window_start <= total_packets) {
        
        printf("\n----------------------------------------------\n");
        printf("Current Window: [ ");
        for(i = 0; i < window_size && (window_start + i) <= total_packets; i++) {
            printf("%d ", window_start + i);
        }
        printf("]\n");

        // STEP 1: SENDING (AND RESENDING) LOOP
        // We check every slot in the current window
        for (i = 0; i < window_size && (window_start + i) <= total_packets; i++) {
            int pkt_num = window_start + i;

            // CRITICAL LOGIC: Selective Repeat
            // We only send the packet if we don't have an ACK for it yet.
            // If ack_received[pkt_num] is 1, we skip it (it's already safe at receiver).
            if (ack_received[pkt_num] == 0) {
                printf("SENDER: Sending Packet %d...\n", pkt_num);
                
                // Simulate Network Noise
                random_value = rand() % 100;
                if (random_value < 30) { // 30% chance of loss
                    printf("NETWORK: *** Packet %d / ACK LOST! ***\n", pkt_num);
                    // We do NOTHING to ack_received. It stays 0.
                    // Next time the loop runs, this packet will be resent.
                } else {
                    printf("RECEIVER: Packet %d Received. ACK Sent.\n", pkt_num);
                    ack_received[pkt_num] = 1; // Mark as success
                }
                sleep(1); // Small delay for visualization
            }
        }

        // STEP 2: SLIDING THE WINDOW
        // We can only slide the window if the packet at the 'window_start' is ACKed.
        // If packet 1 is ACKed, we slide. If packet 2 is also ACKed, we slide again.
        // If packet 1 is NOT ACKed, we cannot slide, even if 2, 3, and 4 are done.
        
        while (ack_received[window_start] == 1 && window_start <= total_packets) {
            printf("\nSENDER: Packet %d is Done. Sliding Window.", window_start);
            window_start++; // Move the base of the window forward
        }
    }

    printf("\n----------------------------------------------\n");
    printf("All packets sent and acknowledged successfully.\n");

    return 0;
}