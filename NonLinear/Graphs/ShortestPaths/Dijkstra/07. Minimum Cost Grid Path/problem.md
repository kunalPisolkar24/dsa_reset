# Minimum Cost Grid Path

**Difficulty:** Medium

## Problem Statement

You are given a 2D `grid` where each cell `(r, c)` has a non-negative integer cost. Find the path from `(0,0)` to `(n-1, m-1)` with the minimum sum of cell costs.

### Example Testcases

**Example 1:**
```
Input: grid = [[44, 37, 58], [98, 6, 58], [86, 3, 36]]
Output: 126
```
**Explanation:** Treat each cell as a node with directed edges to its 4 neighbors.

**Example 2:**
```
Input: grid = [[33, 75, 40], [41, 5, 30], [10, 40, 81]]
Output: 190
```
**Example 3:**
```
Input: grid = [[89, 1, 86], [19, 20, 61], [11, 60, 53]]
Output: 223
```
## Constraints

- $1 \le n \le 500$
- Weights are non-negative integers ($\le 10^4$).
