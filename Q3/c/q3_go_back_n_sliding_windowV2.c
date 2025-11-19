//  3. Simulate and implement go back n sliding window protocol.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep()

int main() {
    int window_size, total_packets;
    int current_packet = 1;
    int i, random_value;
    
    srand(time(0)); // Seed random number generator

    printf("--- GO BACK N PROTOCOL SIMULATION ---\n");
    printf("Enter Total Number of Packets: ");
    scanf("%d", &total_packets);
    printf("Enter Window Size: ");
    scanf("%d", &window_size);

    while (current_packet <= total_packets) {
        printf("\n----------------------------------------------\n");
        printf("SENDER: Sending Window starting from Packet %d\n", current_packet);
        
        // 1. SEND THE WINDOW
        // We attempt to send 'window_size' packets, or however many are left
        for (i = 0; i < window_size && (current_packet + i) <= total_packets; i++) {
            printf("SENDER: Sending Packet %d\n", current_packet + i);
            sleep(1); // Simulate transmission time
        }

        // 2. CHECK FOR ACKS (Simulate Receiver & Noise)
        // We check the packets in the EXACT order they were sent.
        // The moment one fails, the whole batch stops being processed.
        
        int failure_occurred = 0;
        int failed_packet_num = -1;

        for (i = 0; i < window_size && (current_packet + i) <= total_packets; i++) {
            int pkt_num = current_packet + i;
            
            // Simulate 20% chance of packet loss
            random_value = rand() % 100;
            
            if (random_value < 20) { 
                printf("NETWORK: *** Packet %d LOST! ***\n", pkt_num);
                failure_occurred = 1;
                failed_packet_num = pkt_num;
                
                // CRITICAL GBN LOGIC:
                // If Packet X is lost, we don't care if X+1 arrived. 
                // The receiver discards X+1 because it's out of order.
                // So we stop checking ACKs right here.
                break; 
            } else {
                printf("RECEIVER: Received Packet %d. Sending ACK.\n", pkt_num);
            }
        }

        // 3. HANDLE THE OUTCOME (SLIDE OR GO BACK)
        if (failure_occurred) {
            printf("\nSENDER: Timeout! ACK missing for Packet %d.\n", failed_packet_num);
            printf("SENDER: Go Back N triggered. Resetting window to Packet %d.\n", failed_packet_num);
            
            // THE "GO BACK" STEP:
            // We do NOT advance 'current_packet'.
            // We set it exactly to the packet that failed.
            current_packet = failed_packet_num;
            
        } else {
            printf("\nSENDER: All sent packets acknowledged. Sliding Window.\n");
            // SUCCESS: We advance the window by the number of packets we just checked
            current_packet += i;
        }
    }

    printf("\n----------------------------------------------\n");
    printf("Transmission Complete. All %d packets sent.\n", total_packets);

    return 0;
}