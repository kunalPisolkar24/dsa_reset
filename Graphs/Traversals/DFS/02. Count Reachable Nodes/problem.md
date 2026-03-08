# 2. Count Reachable Nodes

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, and a starting node `start`, count how many nodes are reachable from `start`.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3]]
Output: 4
```

**Example 2:**
```
Input:
n = 7
edges = [[2, 4], [1, 2], [0, 4], [1, 5], [1, 4], [2, 3], [5, 6], [1, 3]]
Output: 7
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
