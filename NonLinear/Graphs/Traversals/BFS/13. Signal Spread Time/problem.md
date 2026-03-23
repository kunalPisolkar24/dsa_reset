# 13. Signal Spread Time

**Difficulty:** Medium

## Problem Statement
A signal starts at node `0` and spreads to all neighbors every second. Return the time it takes to reach all reachable nodes.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [1, 2], [0, 4], [1, 5], [1, 4], [3, 5]]


Output: 3
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [0, 3], [2, 3], [1, 3]]


Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
