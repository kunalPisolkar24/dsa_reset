# 10. Number of DFS Trees

**Difficulty:** Medium

## Problem Statement
If you run DFS on all nodes (iterating `0..n-1`, starting DFS if not visited), how many distinct DFS trees are formed? This essentially counts the connected components.

### Example Testcases

**Example 1:**
```
Input:
n = 2
edges = []
Output: 2
```

**Example 2:**
```
Input:
n = 20
edges = [[10, 11], [0, 11], [6, 11]]
Output: 17
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
