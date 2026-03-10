# 17. Closest Special Node

**Difficulty:** Medium

## Problem Statement
Some nodes are special. For each node, compute the distance to the nearest special node. Unreachable nodes get `-1`.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[0, 2], [1, 3], [3, 4]]
specialNodes = [0]

Output: [0, -1, 1, -1, -1]
```

**Example 2:**
```
Input:
n = 7
edges = [[0, 4], [4, 6], [1, 4], [2, 6], [0, 5], [3, 5]]
specialNodes = [0, 6]

Output: [0, 2, 1, 2, 1, 1, 0]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
