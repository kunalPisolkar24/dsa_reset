# 9. Count Nodes at Even Depth

**Difficulty:** Medium

## Problem Statement
Using the same logic as Problem 8, count how many nodes end up at an **even depth** (`0, 2, 4, ...`).

### Example Testcases

**Example 1:**
```
Input:
n = 9
edges = [[0, 4], [3, 4], [1, 5], [6, 8], [1, 7], [0, 2], [7, 8], [3, 6], [0, 8], [3, 5], [2, 8]]
Output: 4
```

**Example 2:**
```
Input:
n = 2
edges = []
Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
