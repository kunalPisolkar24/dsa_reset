# 8. Depth of Each Node

**Difficulty:** Medium

## Problem Statement
Compute the depth of each node in the DFS tree starting from node `0` (which has depth `0`). If a node is unreachable from node `0` initially, start a new DFS from the smallest unvisited node and its roots will also have depth `0`.

**Note**: When moving to neighbors, visit them in strictly **ascending order** of labels.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[1, 2], [3, 4], [4, 6], [1, 4], [0, 5], [3, 6], [1, 3]]
Output: [0, 0, 1, 1, 2, 1, 3]
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [0, 3], [2, 3], [0, 2], [1, 3]]
Output: [0, 1, 2, 3]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
