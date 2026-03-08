# 3. Graph Has Path

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, determine if a path exists between nodes `u` and `v`.

### Example Testcases

**Example 1:**
```
Input:
n = 16
edges = [[5, 13], [0, 12], [4, 7], [0, 2], [11, 15], [3, 6], [2, 6], [4, 14], [7, 12], [14, 15], [3, 5], [12, 14]]
Output: False
```

**Example 2:**
```
Input:
n = 10
edges = [[0, 7], [1, 4]]
Output: False
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
