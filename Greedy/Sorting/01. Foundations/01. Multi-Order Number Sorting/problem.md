# 1. Multi-Order Number Sorting

**Difficulty:** Easy

## Problem Statement

Given an array of integers `arr` and a target integer `k`, perform the following three sorting operations:

1.  **Ascending Order**: Sort the array from smallest to largest.
2.  **Descending Order**: Sort the array from largest to smallest.
3.  **Distance from k**: Sort the array based on the absolute difference between each element and `k`. If two elements have the same distance, the **smaller element** should come first.

### Example Testcases

**Example 1:**
```
Input: arr = [7, 2, 9, 1, 5], k = 5
Output:
Ascending: [1, 2, 5, 7, 9]
Descending: [9, 7, 5, 2, 1]
Distance from 5: [5, 7, 2, 1, 9]
```

**Example 2:**
```
Input: arr = [10, -5, 0, 5], k = 0
Output:
Ascending: [-5, 0, 5, 10]
Descending: [10, 5, 0, -5]
Distance from 0: [0, 5, -5, 10]
```

**Example 3:**
```
Input: arr = [1, 1, 1], k = 2
Output:
Ascending: [1, 1, 1]
Descending: [1, 1, 1]
Distance from 2: [1, 1, 1]
```

## Constraints

- `1 <= n <= 10^5`
- `-10^9 <= arr[i] <= 10^9`
- `-10^9 <= k <= 10^9`
