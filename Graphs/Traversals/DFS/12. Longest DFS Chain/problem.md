# 12. Longest DFS Chain

**Difficulty:** Hard

## Problem Statement
Return the maximum depth reached during the DFS starting from node `0`.

**Note**: Treat `0` as depth `0`. Iterate neighbors in strictly **ascending order**.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[0, 1], [0, 2], [1, 2], [0, 3]]
Output: 2
```

**Example 2:**
```
Input:
n = 5
edges = [[0, 1], [0, 4], [3, 4], [2, 3], [1, 3]]
Output: 3
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
