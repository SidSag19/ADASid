# Multi-Stage Graph: Shortest Path (Forward Approach)

### Aim
Calculate the minimum cost and optimal path from source to destination in a directed multi-stage graph using Dynamic Programming.

---

### Algorithm (Forward Approach)
1. **Initialize:** Set the cost of the destination node to `0`.
2. **Evaluate Backward:** Loop backward from the second-to-last node down to the source node.
3. **Find Minimums:** For each node, calculate the total cost for all valid forward paths (`Edge Weight + Cost of Next Node`).
4. **Store Choices:** Save the lowest cost and the specific next node that provides that optimal route.
5. **Trace Path:** Starting from the source, use the stored choices to reconstruct and print the shortest path.

---

### Complexity
* **Time Complexity:** $O(V^2)$ — Iterating backward through the vertices and checking forward edges using an adjacency matrix evaluates $V \times V$ elements.
* **Space Complexity:** $O(V^2)$ — Primarily due to the $20 \times 20$ adjacency matrix used to store the graph.

---

### Use Cases
1. **Logistics & Routing:** Finding the most cost-effective transport route through a strict sequence of intermediate distribution hubs before reaching the final delivery point.
2. **Resource Allocation:** Determining the optimal distribution of a limited budget across sequential phases of a project to maximize overall return on investment.