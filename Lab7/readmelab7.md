Just a quick heads-up: the text you provided actually perfectly describes the **Backward Approach** (since it initializes the destination to `0` and loops backward down to the source).

I have corrected the title for your original text below and written out the true **Forward Approach** (which builds from the source to the destination) in the exact same format so you have a complete, accurate set\!

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