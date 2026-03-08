# 11. DFS Edge Count

**Difficulty:** Medium

## Problem Statement
During a full DFS traversal (visiting unvisited nodes ascendingly `0..n-1`), count how many **tree edges** were used.

**Note**: When checking neighbors, iterate in strictly **ascending order**.

### Example Testcases

**Example 1:**
```
Input:
n = 21
edges = []
Output: 0
```

**Example 2:**
```
Input:
n = 10
edges = [[0, 7], [1, 4], [0, 6], [6, 7], [0, 5], [3, 6], [0, 8], [7, 8]]
Output: 6
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
