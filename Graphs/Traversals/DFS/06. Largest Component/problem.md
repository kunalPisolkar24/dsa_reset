# 6. Largest Component

**Difficulty:** Medium

## Problem Statement
Return the size of the largest connected component in the given graph.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[3, 4], [1, 5], [2, 3], [4, 5], [0, 2], [2, 6], [2, 5]]
Output: 7
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [1, 2], [0, 3], [1, 4], [2, 3], [0, 2], [0, 5], [1, 3]]
Output: 6
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
