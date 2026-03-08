# 6. Largest Component

**Difficulty:** Medium

## Problem Statement
Return the size of the largest connected component in the given graph.

### Example Testcases

**Example 1:**
```
Input:
n = 25
edges = [[5, 21], [0, 20], [1, 21], [3, 17], [6, 8], [2, 19], [4, 5], [2, 22], [3, 11]]
Output: 4
```

**Example 2:**
```
Input:
n = 12
edges = [[2, 4], [5, 11], [0, 4], [0, 10], [5, 8], [7, 10], [2, 10], [1, 8], [3, 7], [1, 4], [0, 6], [5, 10], [0, 2], [4, 11]]
Output: 11
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
