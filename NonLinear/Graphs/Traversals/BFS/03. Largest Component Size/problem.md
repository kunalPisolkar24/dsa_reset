# 3. Largest Component Size

**Difficulty:** Medium

## Problem Statement
Return the size of the largest connected component in the given graph using BFS.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [1, 5], [4, 5], [1, 3], [3, 5]]


Output: 6
```

**Example 2:**
```
Input:
n = 5
edges = [[2, 4], [1, 2], [3, 4], [0, 2]]


Output: 5
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
