Practical 1
### 1. Tower of Hanoi (Recursive)

* **Aim**: To move a stack of  disks from one rod to another following specific constraints (only one disk moves at a time and no larger disk sits on a smaller one).
* **Use Case**: Solving logical puzzles, studying recursive sub-problems, and understanding exponential time complexity ().
* **Algorithm**:
1. **Base Case**: If , move the disk directly from Source to Target.
2. **Recursive Step**: Move  disks from Source to Auxiliary.
3. Move the  disk from Source to Target.
4. Move the  disks from Auxiliary to Target.



---

### 2. Bouncing Ball Simulation

* **Aim**: To calculate the total number of bounces a ball makes until its velocity falls below a threshold (1 unit).
* **Use Case**: Physics simulations and game engines to model energy loss and damping effects.
* **Algorithm**:
1. **Base Case**: If velocity<=1 , return the current count .
2. **Recursive Step**: Multiply velocity by the restitution factor (0.575) and increment .
3. Return the result of the next recursive call.



---

### 3. Binary Exponentiation (Fast Approach)

* **Aim**: To calculate  efficiently using the "divide and conquer" approach.
* **Use Case**: Competitive programming, and handling large exponent calculations.
* **Algorithm**:
1. **Base Case**:if (b==0) return 1;
2. Calculate int half=power(a,b/2);.
3. **If  is even**: return half*half .
4. **If  is odd**: return a*half*half .



---

### 4. String Permutations (Backtracking)

* **Aim**: To generate all possible rearrangements of a given string.
* **Use Case**: Brute-force searching, anagram solvers, and combinatorial optimization.
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
* **Algorithm**:
1. Generate a large array of random integers.
2. Capture start time using `high_resolution_clock`.
3. Perform a loop of 1,000 iterations searching for a target.
4. Calculate the total duration and divide by the number of iterations for the average time.



---

### 6. Horner’s Rule (Recursive)

* **Aim**: To evaluate a polynomial  at a specific value  using the minimum number of multiplications.
* **Use Case**: Efficiently calculating polynomial values in graphics and digital signal processing.
* **Algorithm**:
1. **Base Case**: if (n == poly.size() - 1) {
        return poly[n]; }
    
2. **Recursive Step**: return poly[n] + x * hornerRecursive(poly, n + 1, x);



---

### 7. Bubble Sort Benchmarking

* **Aim**: To sort an array using adjacent swaps and measure the time taken.
* **Use Case**: Sorting small datasets and demonstrating  time complexity.
* **Algorithm**:
1. Use nested loops to compare adjacent elements.
2. Swap if elements are in the wrong order.
3. **Benchmarking**: Reset the array to its unsorted state using `copy()` before each iteration to ensure a fair average.



---

### 8. Selection Sort Benchmarking

* **Aim**: To sort an array by repeatedly finding the minimum element and placing it at the start.
* **Use Case**: Situations where memory "write" operations are expensive (it performs fewer swaps than Bubble Sort).
* **Algorithm**:
1. Find the minimum value in the unsorted portion of the array.
2. Swap it with the first element of that portion.
3. Repeat for the rest of the array.



---

### 9. Missing Number Finder (Recursive XOR)

* **Aim**: To find a single missing number in a range  without using arithmetic operators.
* **Use Case**: Identifying lost packets in network streams where order isn't guaranteed.
* **Algorithm**:
1. **XOR Range**: Recursively XOR all integers from 1 to .
2. **XOR Vector**: Recursively XOR all integers actually present in the array.
3. The final result is `(XOR Range) ^ (XOR Vector)`.



---

### 10. First Duplicate Finder (Nested Recursion)

* **Aim**: To identify the first element in an array that has a duplicate earlier in the sequence.
* **Use Case**: Data cleaning and finding the first "collision" in a set of entries.
* **Algorithm**:
1. **Outer Recursion**: Traverses each element  of the array.
2. **Inner Recursion**: Checks all elements from index  to .
3. If a match is found, stop and return the index and value.
