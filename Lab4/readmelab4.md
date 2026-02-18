Here is the `README.md` content formatted exactly according to your template for the three algorithms you requested.

# Lab 4

## 1. Iterative Quick Sort (`qs_iterative.cpp`)

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

The time complexity is defined by the recurrence:



Where the solution is o(n*n!).

### **Use Case**

* **Brute Force Solvers:** Used in Traveling Salesperson Problem (TSP), N-Queens.
* **Combinatorics:** Generating test cases for algorithms that depend on input order.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** | n*n! |
| **Average Case** | n*n! |
| **Worst Case** | n*n! |
