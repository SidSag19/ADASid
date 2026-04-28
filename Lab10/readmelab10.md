Here is the text for your Lab 10 Readme:

# Lab 10

This lab implements classic computer science problems using the **Backtracking** algorithmic paradigm. Below is the documentation for each C++ file included in this lab.

---

## 1. `Nqueens.cpp`

* **Aim:** To find a valid arrangement of N queens on an N×N chessboard such that no two queens attack each other (no two share the same row, column, or diagonal).
* **Algorithm (Short):**
    1.  Start from the first row and attempt to place a queen in each column.
    2.  Check if the placement is safe by verifying there are no queens above in the same column or diagonals.
    3.  If safe, place the queen and recursively try to place a queen in the next row.
    4.  If placing the queen leads to a dead end, backtrack by removing the queen and trying the next available column.
* **Use Case:** Solving general Constraint Satisfaction Problems (CSPs), task scheduling, and VLSI circuit testing.
* **Time Complexity:** O(N!) in the worst case (significantly optimized by pruning invalid paths).
* **Space Complexity:** O(N) to store the column placements and handle the recursion stack.

---

## 2. `Subsetsum.cpp`

* **Aim:** To find all subsets of a given set of integers whose elements add up exactly to a specific target value.
* **Algorithm (Short):**
    1.  Traverse the set of elements one by one.
    2.  For each element, make a choice: either include it in the current subset or exclude it.
    3.  Keep a running sum. If the sum exactly matches the target, record the subset.
    4.  If the running sum exceeds the target (pruning), or all elements are checked, backtrack by removing the last added element and try the next option.
* **Use Case:** Financial portfolio optimization, cargo loading algorithms (Knapsack variations), and resource allocation.
* **Time Complexity:** O(2^N) in the worst case (where N is the number of elements), as we explore all subset combinations.
* **Space Complexity:** O(N) for the recursion depth and the temporary array holding the current subset.

---

## 3. `chromatic.cpp`

* **Aim:** To find the Chromatic Number of a graph (the minimum number of colors required to color all vertices so that no two adjacent vertices share the same color).
* **Algorithm (Short):**
    1.  Iteratively test the graph with an increasing number of colors, starting from m = 1.
    2.  For a given m, traverse vertices one by one and try assigning a color from 1 to m.
    3.  Before assigning, check against all adjacent vertices to ensure no conflict.
    4.  If all vertices are successfully colored, the current m is the minimal chromatic number. If a dead end is reached, backtrack and change the previous vertex's color.
* **Use Case:** Register allocation in compilers, frequency/channel assignment in cellular networks, and creating conflict-free schedules (like university exam timetables).
* **Time Complexity:** O(m^V) for checking a specific m, where V is the number of vertices and m is the number of colors.
* **Space Complexity:** O(V) for the recursion stack and the array storing vertex colors.

---

## 4. `hamil.cpp`

* **Aim:** To determine if an undirected graph contains a Hamiltonian Cycle (a closed loop path that visits every single vertex exactly once and returns to the starting vertex).
* **Algorithm (Short):**
    1.  Start at an arbitrary initial vertex (e.g., vertex 0) and add it to the path array.
    2.  Recursively attempt to add unvisited adjacent vertices to the path.
    3.  Once all vertices are added, check if there is an edge connecting the last vertex back to the initial starting vertex. If so, a cycle exists.
    4.  If no valid adjacent unvisited vertex is found at any step, backtrack by removing the current vertex from the path and trying a different adjacent node.
* **Use Case:** The Traveling Salesperson Problem (TSP) routing, delivery logistics, microchip manufacturing, and network topology analysis.
* **Time Complexity:** O(V!) in the worst case, as the algorithm explores permutations of vertex visits.
* **Space Complexity:** O(V) for the recursion depth and the path array storing the current route.