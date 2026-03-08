# 3. Graph Has Path

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, determine if a path exists between nodes `u` and `v`.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[0, 2], [1, 3], [2, 4]]
u = 2, v = 0
Output: True
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [2, 3]]
u = 0, v = 3
Output: False
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
