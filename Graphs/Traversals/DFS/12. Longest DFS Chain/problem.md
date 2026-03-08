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
edges = []
Output: 0
```

**Example 2:**
```
Input:
n = 20
edges = [[4, 11]]
Output: 0
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
