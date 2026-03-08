# 8. Depth of Each Node

**Difficulty:** Medium

## Problem Statement
Compute the depth of each node in the DFS tree starting from node `0` (which has depth `0`). If a node is unreachable from node `0` initially, start a new DFS from the smallest unvisited node and its roots will also have depth `0`.

**Note**: When moving to neighbors, visit them in strictly **ascending order** of labels.

### Example Testcases

**Example 1:**
```
Input:
n = 15
edges = [[2, 14], [2, 4], [1, 5], [5, 14], [3, 7], [5, 8], [0, 3], [1, 14], [0, 6], [3, 13], [1, 13], [0, 5], [4, 11], [2, 5], [2, 8]]
Output: [0, 3, 5, 1, 6, 4, 1, 2, 6, 0, 0, 7, 0, 2, 6]
```

**Example 2:**
```
Input:
n = 8
edges = [[1, 2], [3, 7], [1, 4], [0, 2], [3, 6], [1, 6]]
Output: [0, 2, 1, 4, 3, 0, 3, 5]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
