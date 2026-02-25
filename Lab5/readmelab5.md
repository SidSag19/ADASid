
---

# Algorithm Laboratory Experiments

This repository contains C++ implementations of four classic algorithmic problems, demonstrating Greedy strategies, Divide and Conquer techniques, and Partitioning algorithms.

---

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