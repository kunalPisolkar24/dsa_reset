# 1. Print BFS Traversal

**Difficulty:** Easy

## Problem Statement
Start from node `0`, visit neighbors in ascending order using BFS. If the graph is disconnected, restart BFS from the smallest unvisited node. Return the traversal order.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[2, 4], [1, 2], [0, 4], [1, 5], [2, 3], [0, 2], [2, 5]]


Output: [0, 2, 4, 1, 3, 5]
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [1, 2], [3, 4], [1, 5], [2, 3], [4, 5], [0, 5], [2, 5], [3, 5]]


Output: [0, 1, 5, 2, 3, 4]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
