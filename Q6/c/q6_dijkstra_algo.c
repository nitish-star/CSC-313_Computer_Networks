#include <stdio.h>
#include <limits.h> // Used for INT_MAX (Infinity)
#include <stdbool.h>

#define MAX_NODES 20
#define INF 9999

// Function to find the vertex with the minimum distance value,
// from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n, int source) {
    printf("\n--- SHORTEST PATHS FROM NODE %d ---\n", source);
    printf("Destination\t Min Cost\n");
    printf("------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src) {
    int dist[MAX_NODES];     // The output array. dist[i] will hold the shortest distance from src to i
    bool visited[MAX_NODES]; // visited[i] will be true if vertex i is essentially "done"

    // 1. INITIALIZATION
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // 2. THE MAIN LOOP
    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited, n);

        // Mark the picked vertex as visited
        visited[u] = true;

        // 3. RELAXATION STEP
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < n; v++) {
            // Update dist[v] only if:
            // 1. It is not visited
            // 2. There is an edge from u to v (graph[u][v] != 0)
            // 3. Total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, src);
}

int main() {
    int n, graph[MAX_NODES][MAX_NODES];
    int source;

    printf("--- DIJKSTRA'S ALGORITHM SIMULATION ---\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Matrix (Enter 0 for self, 9999 for no link):\n");
    for (int i = 0; i < n; i++) {
        printf("Costs for Node %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            // Safety check: treat 0 as no-edge unless it's self-loop
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF; 
            }
        }
    }

    printf("\nEnter the Source Node (0 to %d): ", n - 1);
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}