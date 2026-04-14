# Effort-Based Path

**Difficulty:** Medium

## Problem Statement

In a 2D grid, the 'effort' of a path is the MAXIMUM absolute difference in height between any two consecutive cells. Find a path from top-left to bottom-right that minimizes this maximum effort.

### Example Testcases

**Example 1:**
```
Input: grid = [[72, 41, 87], [41, 83, 43], [99, 63, 40]]
Output: 42
```
**Explanation:** A variation of Dijkstra where weights are non-additive (min-max path).

**Example 2:**
```
Input: grid = [[46, 72, 18], [72, 85, 48], [79, 29, 22]]
Output: 37
```
**Example 3:**
```
Input: grid = [[21, 72, 99], [96, 73, 11], [87, 38, 94]]
Output: 56
```
## Constraints

- $1 \le n \le 10^5$
- Weights are non-negative integers ($\le 10^4$).
