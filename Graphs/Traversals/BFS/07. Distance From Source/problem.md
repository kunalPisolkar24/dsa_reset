# 7. Distance From Source

**Difficulty:** Medium

## Problem Statement
Return the shortest distance from node `0` to every node. If a node is unreachable, its distance should be `-1`.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 1], [1, 2], [3, 4], [1, 5], [1, 4], [0, 2], [0, 5], [2, 5], [3, 5]]


Output: [0, 1, 1, 2, 2, 1]
```

**Example 2:**
```
Input:
n = 5
edges = [[2, 3], [0, 3], [1, 3]]


Output: [0, 2, 2, 1, -1]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
