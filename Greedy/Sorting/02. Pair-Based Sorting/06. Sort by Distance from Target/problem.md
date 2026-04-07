# 6. Sort by Distance from Target

**Difficulty:** Medium

## Problem Statement

Given an integer array `arr` and a target integer `k`, sort the array elements based on their **absolute difference** from `k`.

Rules:
1.  Elements with a **smaller absolute difference** from `k` should come first.
2.  If two elements have the **same absolute difference**, the **smaller element** should come first.

### Example Testcases

**Example 1:**
```
Input: arr = [10, 5, 3, 9, 2], k = 6
Output: [5, 3, 9, 2, 10]
Explanation:
- |5-6|=1
- |3-6|=3
- |9-6|=3
- |2-6|=4
- |10-6|=4
Sorted: 5, then (3, 9 because 3 < 9), then (2, 10 because 2 < 10).
```

**Example 2:**
```
Input: arr = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 4, 1, 5]
```

**Example 3:**
```
Input: arr = [-10, 0, 10], k = 0
Output: [0, -10, 10]
```

## Constraints

- `1 <= n <= 10^5`
- `-10^9 <= arr[i], k <= 10^9`
