# 4. Count Connected Components

**Difficulty:** Medium

## Problem Statement
Given `n` nodes and `edges`, count how many distinct connected components exist.

### Example Testcases

**Example 1:**
```
Input:
n = 16
edges = [[1, 12], [3, 8], [8, 14], [9, 12], [4, 12], [5, 7], [3, 13], [1, 13], [7, 12], [2, 15], [7, 11], [3, 15], [2, 8]]
Output: 4
```

**Example 2:**
```
Input:
n = 21
edges = [[0, 13], [3, 20], [8, 13], [1, 7], [4, 11]]
Output: 16
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
