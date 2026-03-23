# 10. Number of DFS Trees

**Difficulty:** Medium

## Problem Statement
If you run DFS on all nodes (iterating `0..n-1`, starting DFS if not visited), how many distinct DFS trees are formed? This essentially counts the connected components.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[2, 4], [1, 2], [0, 3], [0, 6], [2, 3], [2, 6], [5, 6], [3, 6], [3, 5]]
Output: 1
```

**Example 2:**
```
Input:
n = 7
edges = [[0, 1], [0, 4], [4, 6], [0, 3], [2, 6]]
Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
