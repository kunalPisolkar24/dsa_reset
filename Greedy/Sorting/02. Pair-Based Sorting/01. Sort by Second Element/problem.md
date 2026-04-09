# 1. Sort by Second Element

**Difficulty:** Medium

## Problem Statement

Given an array of pairs `(a, b)`, sort them based on the **second element** `b` in ascending order.

If two pairs have the same second element, sort them by the **first element** in ascending order.

### Example Testcases

**Example 1:**
```
Input: arr = [(1, 5), (2, 3), (4, 6), (3, 2)]
Output: [(3, 2), (2, 3), (1, 5), (4, 6)]
Explanation: Sorted by the second elements: 2, 3, 5, 6.
```

**Example 2:**
```
Input: arr = [(10, 1), (5, 5), (2, 0)]
Output: [(2, 0), (10, 1), (5, 5)]
```

**Example 3:**
```
Input: arr = [(1, 1), (2, 1), (0, 1)]
Output: [(1, 1), (2, 1), (0, 1)] 
Explanation: All second elements are 1, any order is fine.
```

## Constraints

- `1 <= n <= 10^5`
- `-10^9 <= a, b <= 10^9`
