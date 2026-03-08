# 9. Count Nodes at Even Depth

**Difficulty:** Medium

## Problem Statement
Using the same logic as Problem 8, count how many nodes end up at an **even depth** (`0, 2, 4, ...`).

### Example Testcases

**Example 1:**
```
Input:
n = 13
edges = [[4, 10], [0, 10], [6, 11]]
Output: 11
```

**Example 2:**
```
Input:
n = 7
edges = [[2, 4], [0, 4], [1, 5], [0, 2]]
Output: 5
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
