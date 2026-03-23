# 6. Shortest Path in Grid

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = free cell` and `1 = obstacle`. Start at `(0,0)` and reach `(n-1,m-1)`. Return **minimum number of moves** using 4 directions. Return `-1` if unreachable.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 1, 0}
            }
Output: 6
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 1},
                {1, 0, 0},
                {0, 0, 1}
            }
Output: -1
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
