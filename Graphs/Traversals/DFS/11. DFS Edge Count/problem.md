# 11. DFS Edge Count

**Difficulty:** Medium

## Problem Statement
During a full DFS traversal (visiting unvisited nodes ascendingly `0..n-1`), count how many **tree edges** were used.

**Note**: When checking neighbors, iterate in strictly **ascending order**.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[0, 1], [1, 2], [0, 4], [3, 4], [0, 3], [0, 2], [1, 3]]
Output: 4
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [0, 3], [2, 3], [0, 2], [1, 3]]
Output: 3
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
