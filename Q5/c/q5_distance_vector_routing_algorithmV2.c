#include <stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main() {
    int costmat[20][20];
    int nodes, i, j, k, count = 0;
    int update_happened;

    printf("--- DISTANCE VECTOR ROUTING (C CODE) ---\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter the Cost Matrix (Row by Row):\n");
    printf("Hint: Enter 9999 for no direct link, 0 for self.\n");
    
    // 1. Input the Matrix
    for(i = 0; i < nodes; i++) {
        printf("Enter costs for Router %d: ", i + 1);
        for(j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            
            // Initialize the routing table with direct costs
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j; // Initially, next hop is the destination itself
        }
    }

    // 2. The Algorithm (Bellman-Ford / Distance Vector)
    do {
        update_happened = 0;
        for(i = 0; i < nodes; i++) {       // For every Source 'i'
            for(j = 0; j < nodes; j++) {   // For every Destination 'j'
                for(k = 0; k < nodes; k++) { // Check every neighbor 'k'
                    
                    // LOGIC: 
                    // If cost to neighbor 'k' + neighbor's cost to 'j' 
                    // is LESS than my current cost to 'j', then update!
                    
                    if(rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k; // Update Next Hop to be 'k'
                        update_happened = 1; // We made a change, so run loop again
                    }
                }
            }
        }
        count++;
    } while(update_happened);

    // 3. Output
    printf("\n\n=== FINAL ROUTING TABLES ===\n");
    for(i = 0; i < nodes; i++) {
        printf("\nRouter %d Table:\n", i + 1);
        printf("Dest\tNext Hop\tDist\n");
        printf("----------------------------\n");
        for(j = 0; j < nodes; j++) {
            printf("%d\t%d\t\t%d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    printf("\n");
    return 0;
}