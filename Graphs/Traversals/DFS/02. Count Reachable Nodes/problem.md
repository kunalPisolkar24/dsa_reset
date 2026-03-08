# 2. Count Reachable Nodes

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, and a starting node `start`, count how many nodes are reachable from `start`.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [1, 2], [1, 4]]
Output: 1
```

**Example 2:**
```
Input:
n = 7
edges = [[1, 5], [4, 6], [0, 6], [2, 3], [5, 6], [0, 5]]
Output: 5
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
