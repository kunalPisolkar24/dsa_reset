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
edges = [[2, 3], [1, 3], [1, 4]]
Output: 3
```

**Example 2:**
```
Input:
n = 24
edges = [[4, 21], [0, 2], [3, 13], [14, 22], [8, 12], [3, 22], [9, 20], [15, 23], [12, 21], [5, 9], [12, 18], [14, 21], [5, 12], [4, 20], [17, 23], [2, 16], [1, 17], [7, 15], [18, 21], [3, 14], [3, 17], [0, 6], [11, 15], [2, 6], [10, 19], [1, 16], [10, 22], [16, 17]]
Output: 23
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
