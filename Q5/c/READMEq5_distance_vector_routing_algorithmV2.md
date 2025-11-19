# Distance Vector Routing Algorithm Simulation in C

This C program simulates the Distance Vector Routing algorithm, a fundamental routing protocol used in computer networks. The simulation demonstrates how routers exchange information to compute the shortest paths to all destinations in a network.

## Features

- **Routing Table Initialization:** Initializes routing tables with direct costs from the cost matrix.
- **Bellman-Ford Algorithm:** Implements the Distance Vector algorithm to compute shortest paths.
- **Dynamic Updates:** Updates routing tables iteratively until no further changes occur.
- **Final Routing Tables:** Displays the final routing tables for all routers.

## How It Works

1. **Input:**
   - The user provides the number of nodes (routers) in the network.
   - The user inputs the cost matrix, where:
     - `0` represents the cost to itself.
     - `9999` represents no direct link between nodes.

2. **Algorithm:**
   - Each router initializes its routing table with direct costs to neighbors.
   - Routers iteratively exchange information with neighbors to update their routing tables.
   - The process continues until no further updates are needed.

3. **Output:**
   - The program displays the final routing tables for all routers, showing the next hop and distance to each destination.

## Inputs

- **Number of Nodes:** Total number of routers in the network.
- **Cost Matrix:** Matrix representing the direct costs between routers.

## Outputs

- **Routing Tables:**
  - Destination: The destination router.
  - Next Hop: The next router in the path to the destination.
  - Distance: The total cost to reach the destination.

## Example Walkthrough

### Input:
- **Number of Nodes:** 3
- **Cost Matrix:**
  ```
  0 2 7
  2 0 1
  7 1 0
  ```

### Process:
1. Routers initialize their routing tables with direct costs.
2. Routers iteratively exchange information and update their tables.
3. The process stops when no further updates are needed.

### Output:
```
--- DISTANCE VECTOR ROUTING (C CODE) ---
Enter the number of nodes: 3

Enter the Cost Matrix (Row by Row):
Hint: Enter 9999 for no direct link, 0 for self.
Enter costs for Router 1: 0 2 7
Enter costs for Router 2: 2 0 1
Enter costs for Router 3: 7 1 0


=== FINAL ROUTING TABLES ===

Router 1 Table:
Dest	Next Hop	Dist
----------------------------
1	1		0
2	2		2
3	2		3

Router 2 Table:
Dest	Next Hop	Dist
----------------------------
1	1		2
2	2		0
3	3		1

Router 3 Table:
Dest	Next Hop	Dist
----------------------------
1	2		3
2	2		1
3	3		0
```

### Explanation:
This example illustrates how the Distance Vector Routing algorithm computes the shortest paths in a network. Each router exchanges information with its neighbors and updates its routing table until convergence. The final routing tables show the optimal next hop and distance for each destination.

## Applications

- Routing in computer networks (e.g., RIP protocol).
- Understanding dynamic routing algorithms.
- Simulating real-world network scenarios.