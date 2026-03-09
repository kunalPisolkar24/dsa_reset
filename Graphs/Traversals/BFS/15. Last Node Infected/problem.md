# 15. Last Node Infected

**Difficulty:** Medium

## Problem Statement
Given a set of initially infected nodes. The infection spreads to neighbors every second. Return the node that gets infected last. If there is a tie, return the smallest node id among them.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[2, 4], [1, 5], [2, 3], [0, 2], [0, 5], [3, 5]]
sources = [1]

Output: 4
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [1, 2], [3, 4], [1, 5], [0, 3], [1, 4], [2, 3], [0, 5], [1, 3]]
sources = [4, 5]

Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
