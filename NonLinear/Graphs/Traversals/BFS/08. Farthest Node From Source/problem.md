# 8. Farthest Node From Source

**Difficulty:** Medium

## Problem Statement
Return the node with the maximum shortest-path distance from node `0`. If there are multiple, return the smallest index. Only consider reachable nodes.

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [2, 3], [1, 2], [1, 3]]


Output: 2
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [2, 3], [0, 2], [1, 3]]


Output: 3
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
