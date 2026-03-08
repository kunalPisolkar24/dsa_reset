# 12. Longest DFS Chain

**Difficulty:** Hard

## Problem Statement
Return the maximum depth reached during the DFS starting from node `0`.

**Note**: Treat `0` as depth `0`. Iterate neighbors in strictly **ascending order**.

### Example Testcases

**Example 1:**
```
Input:
n = 13
edges = [[5, 10], [3, 9], [5, 6], [0, 11]]
Output: 1
```

**Example 2:**
```
Input:
n = 17
edges = [[4, 9], [3, 7], [14, 16], [0, 2], [11, 14], [2, 8], [2, 14], [13, 14], [1, 15], [6, 11], [8, 11], [9, 16], [0, 4], [1, 5], [15, 16], [10, 13], [1, 4], [11, 12], [0, 6], [13, 15]]
Output: 10
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
