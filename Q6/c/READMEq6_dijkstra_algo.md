# Dijkstra's Algorithm Simulation in C

This C program simulates Dijkstra's algorithm, a fundamental algorithm used to find the shortest paths from a source node to all other nodes in a weighted graph. The simulation demonstrates how the algorithm iteratively selects the shortest path and updates the distances to neighboring nodes.

## Features

- **Shortest Path Calculation:** Computes the shortest paths from a source node to all other nodes.
- **Cost Matrix Input:** Accepts a cost matrix to represent the graph.
- **Dynamic Updates:** Iteratively updates the shortest distances using the relaxation technique.
- **Output:** Displays the shortest path costs from the source node to all other nodes.

## How It Works

1. **Input:**
   - The user provides the number of nodes in the graph.
   - The user inputs the cost matrix, where:
     - `0` represents the cost to itself.
     - `9999` represents no direct link between nodes.

2. **Algorithm:**
   - Initializes distances to all nodes as infinity (`9999`), except the source node, which is set to `0`.
   - Iteratively selects the unvisited node with the smallest distance.
   - Updates the distances to neighboring nodes if a shorter path is found.

3. **Output:**
   - Displays the shortest path costs from the source node to all other nodes.

## Inputs

- **Number of Nodes:** Total number of nodes in the graph.
- **Cost Matrix:** Matrix representing the direct costs between nodes.
- **Source Node:** The node from which shortest paths are calculated.

## Outputs

- **Shortest Path Costs:**
  - Destination: The destination node.
  - Min Cost: The total cost to reach the destination.

## Example Walkthrough

### Input:
- **Number of Nodes:** 4
- **Cost Matrix:**
  ```
  0 1 4 9999
  1 0 2 6
  4 2 0 3
  9999 6 3 0
  ```
- **Source Node:** 0

### Process:
1. Initializes distances: `[0, 1, 4, INF]`.
2. Selects node 0, updates distances to neighbors.
3. Selects node 1, updates distances to neighbors.
4. Selects node 2, updates distances to neighbors.
5. Selects node 3, no further updates.

### Output:
```
--- DIJKSTRA'S ALGORITHM SIMULATION ---
Enter the number of nodes: 4

Enter the Cost Matrix (Enter 0 for self, 9999 for no link):
Costs for Node 0: 0 1 4 9999
Costs for Node 1: 1 0 2 6
Costs for Node 2: 4 2 0 3
Costs for Node 3: 9999 6 3 0

Enter the Source Node (0 to 3): 0

--- SHORTEST PATHS FROM NODE 0 ---
Destination	 Min Cost
------------------------
Node 0 		 0
Node 1 		 1
Node 2 		 3
Node 3 		 6
```

### Explanation:
This example illustrates how Dijkstra's algorithm computes the shortest paths in a graph. The algorithm iteratively selects the node with the smallest distance, updates the distances to its neighbors, and repeats until all nodes are visited. The final output shows the shortest path costs from the source node to all other nodes.

## Applications

- Routing in computer networks.
- Solving shortest path problems in weighted graphs.
- Simulating real-world scenarios such as road networks and logistics.