# 5. Component Sizes

**Difficulty:** Medium

## Problem Statement
Given `n` nodes and `edges`, return the size of every connected component in ascending order.

### Example Testcases

**Example 1:**
```
Input:
n = 18
edges = [[6, 12], [12, 16], [0, 2], [0, 5], [1, 9], [6, 17], [0, 10], [2, 7], [1, 5], [0, 13], [2, 16], [15, 16], [7, 15], [9, 12], [1, 4], [9, 15], [10, 13], [0, 15], [11, 15], [7, 11]]
Output: [1, 1, 1, 15]
```

**Example 2:**
```
Input:
n = 12
edges = [[2, 4], [0, 4], [2, 7], [8, 10], [5, 7], [7, 9], [6, 7], [2, 9], [2, 6], [1, 10], [3, 5]]
Output: [1, 3, 8]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
