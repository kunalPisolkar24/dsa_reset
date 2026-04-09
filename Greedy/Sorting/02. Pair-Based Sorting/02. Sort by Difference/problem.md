# 2. Sort by Difference

**Difficulty:** Medium

## Problem Statement

Given an array of pairs `(a, b)`, sort them based on the **difference** `(a - b)` in ascending order.

If two pairs have the same difference, sort them by the **first element** `a` in ascending order.

### Example Testcases

**Example 1:**
```
Input: arr = [(5, 2), (8, 3), (6, 6), (7, 1)]
Compute (a-b):
(3), (5), (0), (6)
Output: [(6, 6), (5, 2), (8, 3), (7, 1)]
Explanation: Differences are 0, 3, 5, 6.
```

**Example 2:**
```
Input: arr = [(10, 5), (20, 15), (5, 0)]
Output: [(5, 0), (10, 5), (20, 15)]
Explanation: All differences are 5. Sorted by first element: 5, 10, 20.
```

**Example 3:**
```
Input: arr = [(1, 10), (10, 1)]
Output: [(1, 10), (10, 1)]
Explanation: Differences are -9 and 9.
```

## Constraints

- `1 <= n <= 10^5`
- `-10^9 <= a, b <= 10^9`
