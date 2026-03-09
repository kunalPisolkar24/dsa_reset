# 11. Count BFS Tree Leaves

**Difficulty:** Medium

## Problem Statement
Count the number of leaves in the BFS tree rooted at `0`. A node is a leaf if it discovers no other unvisited nodes during BFS traversal.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [0, 4], [3, 4], [2, 3], [4, 5], [0, 2], [2, 5], [3, 5]]


Output: 4
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [0, 4], [3, 4], [1, 5], [4, 5], [2, 5]]


Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
