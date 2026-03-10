# 1. Flood Fill Region

**Difficulty:** Easy

## Problem Statement
You are given a grid of integers. Starting from `(r,c)`, change the value of that cell and all **4-directionally connected cells with the same value** to `newColor`. Return the modified grid.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0, 2},
                {1, 1, 1, 0, 1},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
            }
r = 2\nc = 3\nnewColor = 8\nOutput: {
                {8, 8, 8, 8, 2},
                {1, 1, 1, 8, 1},
                {8, 1, 8, 8, 8},
                {8, 8, 8, 8, 8},
                {8, 8, 8, 8, 8}
            }
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }
r = 0\nc = 1\nnewColor = 4\nOutput: {
                {4, 4, 4, 4},
                {4, 4, 4, 4},
                {4, 4, 4, 4},
                {4, 4, 4, 4}
            }
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
