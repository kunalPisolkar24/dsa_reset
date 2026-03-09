# 16. Distance to Nearest Source

**Difficulty:** Hard

## Problem Statement
Given a set of source nodes, return the shortest distance from every node to its **nearest source**. Unreachable nodes get `-1`.

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
sources = [0]

Output: [0, 1, 1, 2]
```

**Example 2:**
```
Input:
n = 5
edges = [[0, 4], [3, 4], [0, 3], [1, 4], [2, 3]]
sources = [0]

Output: [0, 2, 2, 1, 1]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
