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
