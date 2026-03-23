# 5. First Node of Each Level

**Difficulty:** Medium

## Problem Statement
Return the first node discovered at every BFS level starting from node `0`. Note: When iterating neighbors, do so in ascending order.

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [2, 3], [0, 2], [1, 3]]


Output: [0, 1, 3]
```

**Example 2:**
```
Input:
n = 5
edges = [[2, 4], [1, 2], [0, 4], [0, 3], [1, 4], [0, 2], [1, 3]]


Output: [0, 2, 1]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
