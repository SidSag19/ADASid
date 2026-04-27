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