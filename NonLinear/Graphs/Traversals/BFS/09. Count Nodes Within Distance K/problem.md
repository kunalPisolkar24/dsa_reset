# 9. Count Nodes Within Distance K

**Difficulty:** Easy

## Problem Statement
Return the number of nodes whose shortest distance from `0` is ≤ `k`.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[0, 1], [2, 4], [3, 4], [4, 5], [0, 2], [0, 5], [3, 6], [1, 3], [3, 5]]
k = 4

Output: 7
```

**Example 2:**
```
Input:
n = 6
edges = [[2, 4], [1, 2], [0, 4], [3, 4], [2, 3], [4, 5], [0, 2], [3, 5]]
k = 4

Output: 6
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
