# 12. Maximum BFS Width

**Difficulty:** Medium

## Problem Statement
Return the largest number of nodes in any single level for a BFS starting from node `0`.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[1, 2], [1, 4], [2, 3], [0, 2], [2, 6], [5, 6], [3, 5]]


Output: 3
```

**Example 2:**
```
Input:
n = 5
edges = [[0, 1], [2, 4], [1, 2], [0, 4], [0, 2]]


Output: 3
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
