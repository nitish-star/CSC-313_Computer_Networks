def distance_vector_routing():
    print("--- DISTANCE VECTOR ROUTING (PYTHON) ---")
    
    try:
        nodes = int(input("Enter number of nodes: "))
    except ValueError:
        print("Please enter a valid integer.")
        return

    # Initialize matrix with Infinity (9999)
    cost_matrix = []
    print("\nEnter the Cost Matrix (row by row).")
    print("Use 9999 for infinite distance (no link). Use 0 for self.")
    
    for i in range(nodes):
        print(f"Enter costs for Router {i+1} (space separated): ")
        # Input robustness: checks if input is valid
        try:
            row = list(map(int, input().split()))
            if len(row) != nodes:
                print(f"Error: You must enter exactly {nodes} numbers.")
                return
            cost_matrix.append(row)
        except ValueError:
            print("Invalid input. Please enter numbers only.")
            return

    # Initialize Distance Table and Next Hop Table
    # distances[i][j] = distance from i to j
    distances = [row[:] for row in cost_matrix]
    next_hops = [[j for j in range(nodes)] for i in range(nodes)]

    updated = True
    iteration = 0

    # The Algorithm Loop
    while updated:
        updated = False
        iteration += 1
        
        for i in range(nodes):       # Source
            for j in range(nodes):   # Destination
                for k in range(nodes): # Intermediate Node
                    
                    # Logic: cost(i->k) + cost(k->j) < current_cost(i->j)
                    dist_via_k = cost_matrix[i][k] + distances[k][j]
                    
                    if distances[i][j] > dist_via_k:
                        distances[i][j] = dist_via_k
                        next_hops[i][j] = k # Path goes via k
                        updated = True

    # Output
    print("\n=== FINAL ROUTING TABLES ===")
    for i in range(nodes):
        print(f"\nRouter {i+1} Table:")
        print(f"{'Dest':<10} {'Next Hop':<10} {'Dist':<10}")
        print("-" * 30)
        for j in range(nodes):
            # Convert 0-based index to 1-based for display
            hop_display = next_hops[i][j] + 1
            # If the next hop is the destination itself, we can show it as direct
            if hop_display == j + 1 and distances[i][j] == cost_matrix[i][j]:
                 hop_display = "-" 
            elif hop_display == j + 1:
                 hop_display = "-"
            else:
                 # Trace back to immediate neighbor for strict Next Hop logic
                 # (Simplified here to show the intermediate node that reduced cost)
                 pass

            print(f"{j+1:<10} {next_hops[i][j]+1:<10} {distances[i][j]:<10}")

if __name__ == "__main__":
    distance_vector_routing()