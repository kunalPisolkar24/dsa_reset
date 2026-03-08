# 5. Component Sizes

**Difficulty:** Medium

## Problem Statement
Given `n` nodes and `edges`, return the size of every connected component in ascending order.

### Example Testcases

**Example 1:**
```
Input:
n = 24
edges = [[6, 15], [1, 6], [0, 14], [11, 17], [13, 23], [18, 22], [3, 12], [4, 11], [12, 18], [4, 20], [2, 4], [0, 4], [11, 16], [0, 16], [8, 17], [0, 13], [10, 17], [1, 8], [15, 16], [6, 10], [15, 19], [15, 22], [6, 22], [4, 13], [8, 10], [17, 22], [2, 3], [2, 15], [2, 21]]
Output: [1, 1, 1, 21]
```

**Example 2:**
```
Input:
n = 11
edges = [[2, 10], [3, 10], [1, 4], [0, 6], [0, 2], [8, 9], [2, 6], [5, 10], [5, 6], [1, 9]]
Output: [1, 4, 6]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
