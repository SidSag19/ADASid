---

# Algorithm Implementations

This repository contains C++ implementations of fundamental graph and greedy algorithms. Below is a breakdown of each algorithm included, its core logic, real-world use cases, and time complexities.

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

## 5. Kruskal's Algorithm

* **Aim:** To find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph using an edge-based greedy approach.
* **Algorithm:**
1. Sort all edges in the graph in non-decreasing order of their weight (often done efficiently using a Min-Heap).
2. Initialize a Disjoint Set Union (DSU) structure to keep track of connected components.
3. Pick the smallest edge. Check if adding it forms a cycle using the DSU `find` operation.
4. If it does not form a cycle, include it in the MST and `union` the sets.
5. If it forms a cycle, discard the edge.
6. Repeat until the MST contains exactly `V-1` edges.


* **Use Case:** Clustering algorithms in data science, image segmentation, and laying out printed circuit boards (PCBs).
* **Time Complexity:**
* **Best / Average / Worst Case:** `O(E log E)` or `O(E log V)`. The dominant factor is the time taken to sort the edges initially. The DSU operations take near-constant time.If doing DFS then `O(E*V)`



---
