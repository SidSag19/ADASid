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
| **Best Case** |  |
| **Average Case** |  |
| **Worst Case** |  |

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
* **Stable Sorting:** Preserves the relative order of equal elements (essential for multi-key sorting).
* **Linked Lists:** The most efficient algorithm for sorting linked lists as it relies on pointers rather than random access.

### **Time Complexity**

| Case | Complexity |
| --- | --- |
| **Best Case** |  |
| **Average Case** |  |
| **Worst Case** |  |