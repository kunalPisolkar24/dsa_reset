# 2. Count Reachable Nodes

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, and a starting node `start`, count how many nodes are reachable from `start`.

### Example Testcases

**Example 1:**
```
Input:
n = 14
edges = [[7, 12], [6, 10], [0, 11], [6, 11]]
Output: 1
```

**Example 2:**
```
Input:
n = 9
edges = [[4, 5], [3, 5], [7, 8], [3, 6]]
Output: 4
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
