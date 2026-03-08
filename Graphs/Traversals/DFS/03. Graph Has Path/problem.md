# 3. Graph Has Path

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, determine if a path exists between nodes `u` and `v`.

### Example Testcases

**Example 1:**
```
Input:
n = 14
edges = [[9, 13], [6, 11], [6, 8], [2, 6], [3, 9], [5, 12], [0, 11]]
Output: False
```

**Example 2:**
```
Input:
n = 6
edges = [[2, 4], [2, 5], [0, 5]]
Output: True
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
