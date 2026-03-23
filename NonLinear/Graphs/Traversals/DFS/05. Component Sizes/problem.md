# 5. Component Sizes

**Difficulty:** Medium

## Problem Statement
Given `n` nodes and `edges`, return the size of every connected component in ascending order.

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [0, 3], [0, 2], [1, 3]]
Output: [4]
```

**Example 2:**
```
Input:
n = 7
edges = [[2, 4], [1, 2], [0, 4], [1, 5], [0, 6], [0, 2], [2, 6]]
Output: [1, 6]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
