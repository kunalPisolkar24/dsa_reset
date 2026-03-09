# 2. Count Connected Components (BFS)

**Difficulty:** Easy

## Problem Statement
Given an undirected graph with `n` nodes and `edges`, count how many distinct connected components exist using BFS.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [0, 4], [1, 5], [0, 3], [2, 3], [0, 2], [1, 3], [3, 5]]


Output: 1
```

**Example 2:**
```
Input:
n = 7
edges = [[2, 4], [0, 4], [3, 4], [0, 3], [4, 5], [5, 6], [3, 6], [2, 5]]


Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
