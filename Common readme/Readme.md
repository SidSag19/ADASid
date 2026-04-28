# Lab 1

### 1. Tower of Hanoi (Recursive)

* **Aim**: To move a stack of  disks from one rod to another following specific constraints (only one disk moves at a time and no larger disk sits on a smaller one).
* **Use Case**: Solving logical puzzles, studying recursive sub-problems, and understanding exponential time complexity ().
* **Time Complexity**: O(2^n) where n is the number of disks.
* **Algorithm**:
1. **Base Case**: If , move the disk directly from Source to Target.
2. **Recursive Step**: Move  disks from Source to Auxiliary.
3. Move the  disk from Source to Target.
4. Move the  disks from Auxiliary to Target.

---

### 2. Bouncing Ball Simulation

* **Aim**: To calculate the total number of bounces a ball makes until its velocity falls below a threshold (1 unit).
* **Use Case**: Physics simulations and game engines to model energy loss and damping effects.
* **Time Complexity**: O(log v) where v is the initial velocity.
* **Algorithm**:
1. **Base Case**: If velocity<=1 , return the current count .
2. **Recursive Step**: Multiply velocity by the restitution factor (0.575) and increment .
3. Return the result of the next recursive call.

---

### 3. Binary Exponentiation (Fast Approach)

* **Aim**: To calculate  efficiently using the "divide and conquer" approach.
* **Use Case**: Competitive programming, and handling large exponent calculations.
* **Time Complexity**: O(log b) where b is the exponent.
* **Algorithm**:
1. **Base Case**: if (b==0) return 1;
2. Calculate int half=power(a,b/2);.
3. **If  is even**: return half*half .
4. **If  is odd**: return a*half*half .

---

### 4. String Permutations (Backtracking)

* **Aim**: To generate all possible rearrangements of a given string.
* **Use Case**: Brute-force searching, anagram solvers, and combinatorial optimization.
* **Time Complexity**: O(n * n!) where n is the length of the string.
* **Algorithm**:
1. **Base Case**: If `left == right`, print the current string.
2. **Recursive Step**: Loop from `left` to `right`.
3. Swap the current character with the character at `left`.
4. Recurse for the next index (`left + 1`).
5. **Backtrack**: Swap the characters back to restore the original state for the next branch.

---

### 5. Linear Search Benchmarking

* **Aim**: To measure the average execution time of a linear search across a large array.
* **Use Case**: Performance analysis and comparing the efficiency of search algorithms on modern hardware.
* **Time Complexity**: O(n) where n is the number of elements in the array.
* **Algorithm**:
1. Generate a large array of random integers.
2. Capture start time using `high_resolution_clock`.
3. Perform a loop of 1,000 iterations searching for a target.
4. Calculate the total duration and divide by the number of iterations for the average time.

---

### 6. Horner’s Rule (Recursive)

* **Aim**: To evaluate a polynomial  at a specific value  using the minimum number of multiplications.
* **Use Case**: Efficiently calculating polynomial values in graphics and digital signal processing.
* **Time Complexity**: O(n) where n is the degree of the polynomial.
* **Algorithm**:
1. **Base Case**: if (n == poly.size() - 1) {
        return poly[n]; }
    
2. **Recursive Step**: return poly[n] + x * hornerRecursive(poly, n + 1, x);

---

### 7. Bubble Sort Benchmarking

* **Aim**: To sort an array using adjacent swaps and measure the time taken.
* **Use Case**: Sorting small datasets and demonstrating  time complexity.
* **Time Complexity**: O(n^2) where n is the number of elements in the array.
* **Algorithm**:
1. Use nested loops to compare adjacent elements.
2. Swap if elements are in the wrong order.
3. **Benchmarking**: Reset the array to its unsorted state using `copy()` before each iteration to ensure a fair average.

---

### 8. Selection Sort Benchmarking

* **Aim**: To sort an array by repeatedly finding the minimum element and placing it at the start.
* **Use Case**: Situations where memory "write" operations are expensive (it performs fewer swaps than Bubble Sort).
* **Time Complexity**: O(n^2) where n is the number of elements in the array.
* **Algorithm**:
1. Find the minimum value in the unsorted portion of the array.
2. Swap it with the first element of that portion.
3. Repeat for the rest of the array.

---

### 9. Missing Number Finder (Recursive XOR)

* **Aim**: To find a single missing number in a range  without using arithmetic operators.
* **Use Case**: Identifying lost packets in network streams where order isn't guaranteed.
* **Time Complexity**: O(n) where n is the size of the range.
* **Algorithm**:
1. **XOR Range**: Recursively XOR all integers from 1 to .
2. **XOR Vector**: Recursively XOR all integers actually present in the array.
3. The final result is `(XOR Range) ^ (XOR Vector)`.

---

### 10. First Duplicate Finder (Nested Recursion)

* **Aim**: To identify the first element in an array that has a duplicate earlier in the sequence.
* **Use Case**: Data cleaning and finding the first "collision" in a set of entries.
* **Time Complexity**: O(n^2) where n is the number of elements in the array.
* **Algorithm**:
1. **Outer Recursion**: Traverses each element  of the array.
2. **Inner Recursion**: Checks all elements from index  to .
3. If a match is found, stop and return the index and value.


# Lab 2

## 1. Insertion Sort (`IS.cpp`)

### **Aim**

To implement and analyze a stable, in-place sorting algorithm that builds a sorted list by comparing each new element to the already-sorted section and inserting it into the correct position.

### **Algorithm**

1. Iterate from the second element () to the end of the array.
2. Store the current element as a `key`.
3. Compare the `key` with the elements to its left (the sorted portion).
4. Shift elements that are greater than the `key` one position to the right.
5. Insert the `key` into its correct empty slot.
6. Repeat until the entire array is sorted.

### **Use Case**

* **Small Data:** Highly efficient for small arrays due to low overhead.
* **Online Sorting:** Can sort data as it is being received (real-time).
* **Nearly Sorted:** Fastest algorithm for arrays that are already mostly in order.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(n) |
| **Average Case** | O(n^2) |
| **Worst Case** | O(n^2) |

---

## 2. Binary Search (`bs.cpp`)

### **Aim**

To implement an efficient searching algorithm that finds a target element within a sorted array by repeatedly halving the search interval.

### **Algorithm**

1. Begin with an interval covering the whole array (Low = 0, High = N-1).
2. Calculate the middle element: .
3. If the target matches the middle element, return the index.
4. If the target is less than the middle, narrow the interval to the lower half.
5. If the target is greater than the middle, narrow the interval to the upper half.
6. Repeat until the target is found or the interval is empty.

### **Use Case**

* **Large Datasets:** Ideal for massive lists where linear search is too slow.
* **Static Databases:** Used when data is sorted once and searched many times.
* **Dictionary Lookups:** The standard method for looking up terms in ordered indices.

### **Time Complexity**
//Time Measured in Nanoseconds
| Case | Complexity |
| --- | --- |
| **Best Case** | O(1) |
| **Average Case** | O(logn) |
| **Worst Case** | O(logn) |

---


# Lab 3

## 1. Quick Sort (`qs.cpp`)

### **Aim**

To implement a highly efficient, in-place sorting algorithm that uses a divide-and-conquer strategy with **Hoare’s Partition Scheme** to order elements around a chosen pivot.

### **Algorithm**

1. **Partitioning (Hoare's Scheme):**
* Select the first element as the `pivot`.
* Initialize two pointers: `i` at the start and `j` at the end.
* Increment `i` until an element **greater than** the pivot is found.
* Decrement `j` until an element **smaller than** the pivot is found.
* If `i` is still to the left of `j`, swap the elements at `i` and `j`.
* Repeat until the pointers cross. Finally, swap the pivot with the element at `j`.


2. **Recursion:**
* Recursively apply the above steps to the sub-array left of the pivot (`low` to `j-1`).
* Recursively apply the steps to the sub-array right of the pivot (`j+1` to `high`).


3. **Base Case:** Stop when the sub-array has 0 or 1 elements (`low >= high`).

### **Use Case**

* **General Purpose:** The default sorting choice for arrays in C++ (part of `std::sort`) due to superior average-case performance.
* **Memory Constrained Systems:** Requires only  stack space and sorts **in-place** (no extra arrays needed).
* **Cache Performance:** Excellent locality of reference, making it faster on modern CPUs than other  algorithms.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(nlog n) |
| **Average Case** | O(nlog n) |
| **Worst Case** | O(n^2) |

---

## 2. Merge Sort (`ms.cpp`)

### **Aim**

To implement a **stable** sorting algorithm that guarantees  performance by recursively dividing the array and merging sorted halves using a **Single Temporary Array** optimization.

### **Algorithm**

1. **Divide:** Calculate the middle index and recursively split the array into two halves until the sub-arrays size is 1.
2. **Merge (Optimized):**
* Use a single pre-allocated `temp[]` array (allocated once in `main`) to avoid repeated memory allocation overhead.
* Initialize pointers for the left half (`i`), right half (`j`), and temp array (`k`).
* Compare elements from both halves: place the smaller element into `temp[k]`.
* Copy any remaining elements from the left or right half into `temp`.


3. **Copy Back:** Transfer the sorted elements from `temp[]` back into the original `arr[]`.

### **Use Case**

* **Consistent Performance:** Guaranteed  time regardless of data distribution (no "bad pivot" risks).

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(nlog n) |
| **Average Case** | O(nlog n) |
| **Worst Case** | O(nlog n) |


# Lab 4

## 1. Iterative Quick Sort (`qs.cpp`)

### **Aim**

To implement an **iterative** version of Quick Sort that explicitly manages the stack to optimize memory usage by always processing the **shorter sub-array first**.

### **Algorithm**

1. **Stack Initialization:**
* Create a `std::stack` of pairs (storing `low` and `high` indices).
* Push the initial range `(0, n-1)` onto the stack.


2. **Partitioning:**
* Pop the top range (`low`, `high`) from the stack.
* Apply the partition logic (Hoare's or Lomuto's) to place the pivot in its correct sorted position `p`.


3. **Shorter-Half-First Logic:**
* Calculate the sizes of the left partition (`p - low`) and right partition (`high - p`).
* **Push the Larger** partition onto the stack *first* (so it is processed later).
* **Push the Smaller** partition onto the stack *last* (so it is processed immediately).


4. **Loop:**
* Repeat the process until the stack is empty.



### **Use Case**

* **Deep Recursion Prevention:** Prevents stack overflow errors on large datasets by ensuring the stack depth never exceeds .
* **Embedded Systems:** Suitable for environments where system stack size is strictly limited.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(log n) |
| **Average Case** | O(log n) |
| **Worst Case** | O(n^2) |

---

## 2. Biased Binary Search (`BS13.cpp`)

### **Aim**

To implement a modified Binary Search that divides the search space into **1/3 and 2/3 partitions** instead of equal halves, checking elements closer to the beginning of the array earlier.

### **Algorithm**

1. **Calculate Offset Midpoint:**
* Instead of the standard middle, calculate the pivot point at the 1/3 mark:



2. **Check Midpoint:**
* If `arr[mid] == target`, return `mid`.


3. **Recursive Step:**
* If `target < arr[mid]`, recurse on the **left 1/3** (`low` to `mid - 1`).
* If `target > arr[mid]`, recurse on the **right 2/3** (`mid + 1` to `high`).


4. **Base Case:**
* If `low > high`, return -1 (Not Found).



### **Use Case**

* **Non-Uniform Distributions:** Efficient when the target element is statistically more likely to be located in the earlier indices of the sorted array.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(1) |
| **Average Case** | O(log n) base is 1.5|
| **Worst Case** | O(log n) base is 1.5|

---

## 3. Permutation Generator (`perm.cpp`)

### **Aim**

To generate all possible permutations of a given string using **backtracking** by swapping characters at different positions.

### **Algorithm**

1. **Base Case:**
* If `left == right`, the current permutation is complete. Print the string `str` and return.


2. **Recursive Step:**
* Iterate through the string with loop variable `i` from `left` to `right`.


3. **Swap (Fix Character):**
* Swap `str[left]` with `str[i]`. This fixes the character at index `i` into the current `left` position.


4. **Recurse:**
* Recursively call `permute(str, left + 1, right)` to generate permutations for the remaining characters.


5. **Backtrack (Undo Swap):**
* After the recursive call returns, swap `str[left]` and `str[i]` again to restore the string to its original state for the next iteration of the loop.



### **Recurrence Relation**

The time complexity is defined by the recurrence: T(n)=n*T(n-1) + O(1)



Where the solution is o(n*n!).

### **Use Case**

* **Brute Force Solvers:** Used in Traveling Salesperson Problem (TSP), N-Queens.
* **Combinatorics:** Generating test cases for algorithms that depend on input order.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | O(n*n!) |
| **Average Case** | O(n*n!) |
| **Worst Case** | O(n*n!) |



# Lab 5

## Experiment 1: Fractional Knapsack Problem

**Aim:** To solve the Fractional Knapsack problem by maximizing the total profit without exceeding the bag's weight capacity.

**Algorithm:** 1. Calculate the profit-to-weight ratio for each item.
2. Sort the items based on a chosen greedy strategy (the optimal approach sorts by highest ratio first).
3. Loop through the sorted items, adding them fully to the knapsack if space permits.
4. If an item is too heavy, take a fraction of it that perfectly fills the remaining capacity.

**Time Complexity:** $O(n \log n)$ (dominated by the sorting step).

**Use Case:** Resource allocation, maximizing return on investment with divisible goods, and cargo loading algorithms.

---

## Experiment 2: Convex Hull (QuickHull)

**Aim:** To find the convex hull (the smallest bounding polygon) of a given set of 2D points using a Divide and Conquer approach.

**Algorithm:** 1. Find the extreme minimum and maximum X-coordinate points and draw a line between them.
2. Divide the remaining points into two subsets based on which side of the line they fall.
3. Recursively find the point farthest from the current line, adding it to the hull.
4. Form a triangle with the new point, discard any points trapped inside, and repeat the process for points outside the new outer edges.

**Time Complexity:** * Average/Best Case: $O(n \log n)$

* Worst Case: $O(n^2)$ (e.g., when all points form a circle).

**Use Case:** Collision detection in video games, geographic mapping bounding, and pattern/shape recognition in computer vision.

---

## Experiment 3: K-th Smallest Element (Quickselect)

**Aim:** To find the k-th smallest element in an unsorted array efficiently without sorting the entire dataset.

**Algorithm:** 1. Select a "pivot" element and partition the array so that smaller elements are on the left and larger elements are on the right.
2. Check the final index of the pivot. If it equals k-1, the target is found.
3. If the pivot's index is greater than k-1, recursively search only the left partition.
4. If the pivot's index is less than k-1, recursively search only the right partition.

**Time Complexity:** * Average/Best Case: $O(n)$

* Worst Case: $O(n^2)$ (if the array is already sorted and the worst pivot is constantly chosen).

**Use Case:** Finding statistical medians, processing database queries for top/bottom N records, and rendering performance in 3D graphics.

---

## Experiment 4: Maximum and Minimum (Divide and Conquer)

**Aim:** To find both the maximum and minimum elements in an array simultaneously using a Divide and Conquer approach to minimize total comparisons.

**Algorithm:** 1. Divide the array into two halves recursively until you reach sub-arrays of just 1 or 2 elements.
2. Directly compare and return the min/max for those tiny base-case arrays.
3. As the recursion unwinds, combine the results by comparing the minimums and maximums of the left and right halves to find the absolute extremes.

**Time Complexity:** $O(n)$ (Specifically, it reduces the total number of comparisons to 3n/2 - 2, which is mathematically faster than two separate linear scans).

**Use Case:** Establishing bounding boxes for computer graphics, setting dynamic axes in data visualization charts, and fast sensor data analysis.

---



---

# Lab 6

---

## 1. Dijkstra's Algorithm

* **Aim:** To find the shortest path from a single source vertex to all other vertices in a weighted graph with non-negative edge weights.
* **Algorithm:** 1. Initialize distances to all vertices as infinite (`lar` or `INT_MAX`), and the source vertex distance to 0.
2. Maintain a set of unvisited vertices.
3. Pick the unvisited vertex with the minimum distance.
4. Update the distance to its adjacent unvisited neighbors. If the calculated distance is less than the known distance, update it.
5. Mark the current vertex as visited.
6. Repeat until all vertices are visited or the destination is reached.
* **Use Case:** GPS navigation systems (like Google Maps) to find the fastest route, and routing protocols in computer networks (like OSPF).
* **Time Complexity:**
* **Best / Average / Worst Case:** `O(V^2)` when using a basic Adjacency Matrix. If optimized with an Adjacency List and a Min-Heap (Priority Queue), it becomes `O((V + E) log V)`.



---

## 2. Prim's Algorithm

* **Aim:** To find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.
* **Algorithm:**
1. Start with an arbitrary vertex and mark it as part of the MST.
2. Maintain an array to track the minimum edge weights connecting the MST to unvisited vertices.
3. Find the minimum weight edge that connects a vertex inside the MST to a vertex outside the MST.
4. Add that edge and the new vertex to the MST.
5. Update the tracking array with any new, shorter connections provided by the newly added vertex.
6. Repeat until all `V` vertices are included (resulting in `V-1` edges).


* **Use Case:** Designing efficient networks (laying down telecommunication cables, electrical grids, or water pipes) where the goal is to connect all nodes with the minimum amount of wiring.
* **Time Complexity:**
* **Best / Average / Worst Case:** `O(V^2)` using an Adjacency Matrix. If optimized with an Adjacency List and Min-Heap, it drops to `O((V + E) log V)`.



---

## 3. Activity Selection Problem

* **Aim:** To select the maximum number of non-overlapping activities that can be performed by a single person or machine, given their start and finish times.
* **Algorithm:**
1. Sort all activities in non-decreasing order of their finish times.
2. Select the first activity from the sorted list and print it.
3. For all subsequent activities, compare their start time to the finish time of the previously selected activity.
4. If the start time is greater than or equal to the previous finish time, select the activity and update the "last finish time" tracker.


* **Use Case:** CPU task scheduling, booking meeting rooms in a busy office, or scheduling manufacturing processes on a single assembly line.
* **Time Complexity:**
* **Best Case:** `O(N)` (If the activities are already sorted by finish time).
* **Average / Worst Case:** `O(N log N)` (Due to the time required to sort the activities initially).



---

## 4. Cycle Detection (Using Disjoint Set Union / Union-Find)

* **Aim:** To detect if an undirected graph contains a cycle.
* **Algorithm:**
1. Initialize a `parent` array where every vertex is its own parent (each node is its own separate set).
2. Iterate through all the edges in the graph.
3. For each edge `(u, v)`, find the root parent of `u` and the root parent of `v`.
4. If both vertices share the same root parent, a cycle is detected!
5. If they have different parents, perform a `Union` operation to merge their sets and continue.


* **Use Case:** Verifying network topologies to prevent infinite routing loops, and serving as a helper function inside Kruskal's Algorithm.
* **Time Complexity:**
* **Best / Average / Worst Case:** `O(V)` where `E` is the number of edges (Per Edge Check).



---

Here is the complete, updated section for Kruskal's Algorithm using the DFS approach, formatted perfectly for your README file. You can copy and paste this directly:

---

## 5. Kruskal's Algorithm (DFS Variation for Cycle Detection)

* **Aim:** To find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph using an edge-based greedy approach.
* **Algorithm:**
    1. Sort all edges in the graph in non-decreasing order of their weight (often done efficiently using a Min-Heap).
    2. Initialize an empty Adjacency List to keep track of the edges you have safely added to your in-progress Minimum Spanning Tree (MST).
    3. Pick the smallest available edge `(u, v)`. Use a Depth-First Search (DFS) on your *current* MST Adjacency List to check if a path already exists between vertex `u` and vertex `v`.
    4. If no path exists, adding the edge will not form a cycle. Include it in your final MST and permanently add the connection to your MST Adjacency List.
    5. If a path already exists, adding the edge would create a closed loop. Discard the edge.
    6. Repeat until the MST contains exactly `V-1` edges. 
* **Use Case:** While Kruskal's logic is used in clustering algorithms and network design, this specific **DFS variation** is primarily an educational tool. It is excellent for understanding graph traversals and tree-building logic, though not recommended for massive production databases. 
* **Time Complexity:**
    * **Best / Average / Worst Case:** `O(E * V)` (where `E` is the number of edges and `V` is the number of vertices). 
    * **Why it changed:** Sorting the edges initially takes `O(E log E)`. However, in the worst-case scenario, you must evaluate all `E` edges. For each edge, the DFS must physically walk through the in-progress tree to check for a path, which takes `O(V)` time. Because `O(E * V)` grows much faster than `O(E log E)`, the DFS cycle-checking phase becomes the mathematical bottleneck.

---


# Lab 7

# Multi-Stage Graph: Shortest Path (Forward Approach)

### Aim

Calculate the minimum cost and optimal path from source to destination in a directed multi-stage graph using Dynamic Programming by building the solution from the source outward.

-----

### Algorithm (Forward Approach)

1.  **Initialize:** Set the cost of the source node to `0`.
2.  **Evaluate Forward:** Loop forward from the second node up to the destination node.
3.  **Find Minimums:** For each node, calculate the total cost from all valid incoming paths (`Cost of Predecessor Node + Edge Weight`).
4.  **Store Choices:** Save the lowest cost and the specific predecessor node that provides that optimal route.
5.  **Trace Path:** Starting from the destination, use the stored choices to trace the shortest path backward to the source, then reverse it for the final output.

-----

### Complexity

  * **Time Complexity:** $O(V^2)$ — Iterating forward through the vertices and checking all possible incoming edges using an adjacency matrix evaluates $V \times V$ elements.
  * **Space Complexity:** $O(V^2)$ — Primarily due to the $20 \times 20$ adjacency matrix used to store the graph.

-----

### Use Cases

1.  **Assembly Line Scheduling:** Determining the fastest or cheapest way to route a product through various sequential stages of manufacturing when multiple machines are available at each stage.
2.  **Flight Routing:** Finding the cheapest multi-hop flight from a starting city to a destination city through a strict sequence of intermediate geographical zones.

<br>

# Multi-Stage Graph: Shortest Path (Backward Approach)

### Aim

Calculate the minimum cost and optimal path from source to destination in a directed multi-stage graph using Dynamic Programming by working backward from the destination.

-----

### Algorithm (Backward Approach)

1.  **Initialize:** Set the cost of the destination node to `0`.
2.  **Evaluate Backward:** Loop backward from the second-to-last node down to the source node.
3.  **Find Minimums:** For each node, calculate the total cost for all valid forward paths (`Edge Weight + Cost of Next Node`).
4.  **Store Choices:** Save the lowest cost and the specific next node that provides that optimal route.
5.  **Trace Path:** Starting from the source, use the stored choices to reconstruct and print the shortest path.

-----

### Complexity

  * **Time Complexity:** $O(V^2)$ — Iterating backward through the vertices and checking forward edges using an adjacency matrix evaluates $V \times V$ elements.
  * **Space Complexity:** $O(V^2)$ — Primarily due to the $20 \times 20$ adjacency matrix used to store the graph.

-----

### Use Cases

1.  **Logistics & Routing:** Finding the most cost-effective transport route through a strict sequence of intermediate distribution hubs before reaching the final delivery point.
2.  **Resource Allocation:** Determining the optimal distribution of a limited budget across sequential phases of a project to maximize overall return on investment.


# Lab 8

# Matrix Chain Multiplication (Dynamic Programming)

## Aim
To implement a C++ program that determines the optimal parenthesization for a sequence of matrices, minimizing the total number of scalar multiplications required to compute the product. 

## Algorithm in Short
The program uses a bottom-up Dynamic Programming approach:
1. **Initialize a 2D Table:** Create a table `m[][]` where `m[i][i]` is set to `0` (the cost of multiplying a single matrix is zero).
2. **Chain Length Loop:** Iterate through all possible subchain lengths, starting from 2 matrices up to `n` matrices.
3. **Start Position Loop:** For each chain length, iterate through every possible starting matrix `i` to determine the ending matrix `j`.
4. **Split Point Loop:** For each subchain from `i` to `j`, try every possible split point `k`. 
5. **Calculate Cost:** The cost of a split at `k` is calculated as the cost of the left side `m[i][k]` + the cost of the right side `m[k+1][j]` + the cost of multiplying the two resulting matrices together `(p[i-1] * p[k] * p[j])`.
6. **Store Minimum:** Save the lowest cost found for that specific subchain into `m[i][j]`.
7. **Result:** The final minimum cost for the entire chain is found at `m[1][n]`.

## Use Case
This algorithm is crucial in fields requiring heavy linear algebra calculations, such as:
* **3D Computer Graphics:** Optimizing the transformation matrices applied to 3D objects before rendering.
* **Scientific Computing & Physics Simulations:** Minimizing processing time when simulating complex multi-variable systems.
* **Machine Learning / Deep Learning:** Speeding up the backpropagation processes where multiple large weight matrices are multiplied consecutively.

## Complexity
* **Time Complexity:** $O(n^3)$ — The algorithm relies on three nested loops: one for the chain length, one for the start position, and one for the split position $k$. 
* **Space Complexity:** $O(n^2)$ — Required to store the computed minimum costs in the 2D DP table.


# Lab 9

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