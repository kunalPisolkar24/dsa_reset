# 4. Count Connected Components

**Difficulty:** Medium

## Problem Statement
Given `n` nodes and `edges`, count how many distinct connected components exist.

### Example Testcases

**Example 1:**
```
Input:
n = 5
edges = [[2, 4], [1, 2], [3, 4], [0, 3], [1, 4], [2, 3], [1, 3]]
Output: 1
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [1, 3], [0, 3]]
Output: 1
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
