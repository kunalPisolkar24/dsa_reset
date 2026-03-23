# 9. Count Nodes at Even Depth

**Difficulty:** Medium

## Problem Statement
Using the same logic as Problem 8, count how many nodes end up at an **even depth** (`0, 2, 4, ...`).

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [0, 3], [2, 3], [0, 2], [1, 3]]
Output: 2
```

**Example 2:**
```
Input:
n = 5
edges = [[2, 3], [0, 2], [1, 2], [0, 4]]
Output: 3
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
