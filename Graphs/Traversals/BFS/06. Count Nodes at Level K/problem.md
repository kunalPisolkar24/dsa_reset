# 6. Count Nodes at Level K

**Difficulty:** Easy

## Problem Statement
Given `k`, return the number of nodes exactly at level `k` in a BFS starting from `0`. Return `0` if no such level exists.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[0, 4], [3, 4], [2, 3], [0, 2], [4, 5], [2, 5], [1, 3], [3, 5]]
k = 2

Output: 2
```

**Example 2:**
```
Input:
n = 5
edges = [[2, 3], [0, 4], [1, 4]]
k = 0

Output: 1
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
