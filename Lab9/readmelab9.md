## 1. Floyd-Warshall Algorithm (`fw.cpp`)

### **Aim**
To implement the Floyd-Warshall algorithm to compute the shortest paths between every pair of vertices in a weighted, directed graph.

### **Algorithm in Short**
The algorithm uses Dynamic Programming to build up shortest paths. 
1. It initializes a `dist` matrix with the direct weights between nodes (and $0$ for self-loops, infinity for no edge).
2. It uses three nested loops. The outermost loop picks a vertex $k$ to act as an "intermediate" step.
3. The inner loops check every pair of vertices $(i, j)$ and update their shortest distance if traveling through $k$ (i.e., `dist[i][k] + dist[k][j]`) is shorter than the currently known `dist[i][j]`.

### **Use Cases**
* **Network Routing:** Used in telecommunications to find the optimal data packet routing tables between all routers in a network.
* **Urban Transit:** Evaluating city infrastructure to find the fastest travel times between all subway stations or bus stops.

### **Time Complexity**
* **Time Complexity:** $O(n^3)$, where $n$ is the number of vertices/points.
* **Space Complexity:** $O(n^2)$ for the distance matrix.

---

## 2. Longest Common Subsequence (`LCS.cpp`)

### **Aim**
To determine the Longest Common Subsequence (LCS) between two given strings using Dynamic Programming and trace back the actual matching sequence.

### **Algorithm in Short**
1. It creates a 2D grid (`c[][]`) to store the lengths of matching subsequences and a tracker grid (`p[][]`) to store directions ('D' for Diagonal, 'U' for Up, 'L' for Left).
2. It compares characters of `String X` and `String Y`. If characters match, it adds $1$ to the diagonal cell's value. If they don't, it carries forward the maximum value from either the cell above or the cell to the left.
3. Once the grid is filled, a recursive `WriteSol` function follows the directional arrows back from the bottom-right corner to construct and print the actual subsequence.

### **Use Cases**
* **Bioinformatics:** Comparing DNA strands to find genetic similarities and evolutionary relationships.
* **Version Control:** File comparison tools (like `git diff`) use LCS to figure out exactly which lines of code were added, deleted, or kept the same between two file versions.

### **Time Complexity**
* **Time Complexity:** $O(m \times n)$, where $m$ and $n$ are the lengths of the two strings.
* **Space Complexity:** $O(m \times n)$ to store the DP and directional matrices.

---

## 3. Traveling Salesperson Problem (`tsp.cpp`)

### **Aim**
To find the absolute shortest possible route that visits a set of cities exactly once and returns to the origin city, using Dynamic Programming with Bitmasking.

### **Algorithm in Short**
1. The algorithm uses a recursive function combined with memoization (taking notes to avoid repeating work). 
2. It uses an integer `mask` (binary representation) as a checklist to track which cities have been visited (e.g., `0101` means cities 0 and 2 are visited).
3. From the current city, it checks the distance to all unvisited cities and recursively asks, "What is the shortest path from *that* city through the remaining unvisited cities?"
4. It stores the lowest calculated cost for any given state in a `memo` table.

### **Use Cases**
* **Logistics & Delivery:** Delivery companies (like Amazon or UPS) use TSP variations to plan the shortest routes for delivery trucks, saving time and fuel.
* **Manufacturing:** Optimizing the movement path of a robotic arm, laser cutter, or automated drill to minimize the time it takes to process a circuit board.

### **Time Complexity**
* **Time Complexity:** $O(n^2 \times 2^n)$, where $n$ is the number of cities. (This is significantly faster than the naive $O(n!)$ approach).
* **Space Complexity:** $O(n \times 2^n)$ to store the memoization table.