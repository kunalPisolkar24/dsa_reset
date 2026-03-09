# 4. Nodes Per Level

**Difficulty:** Medium

## Problem Statement
Return the number of nodes in each BFS level starting from node `0`. Only consider nodes reachable from `0`.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[2, 4], [0, 4], [0, 2], [1, 6], [2, 5], [1, 3], [3, 5]]


Output: [1, 2, 1, 1, 1, 1]
```

**Example 2:**
```
Input:
n = 7
edges = [[0, 4], [1, 4], [0, 6], [2, 3], [2, 6], [1, 6], [1, 3], [3, 5]]


Output: [1, 2, 2, 1, 1]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
