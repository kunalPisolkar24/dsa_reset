# 11. Shortest Path With One Wall Break

**Difficulty:** Hard

## Problem Statement
Grid contains `0 = empty`, `1 = wall`. You may break **at most one wall**. Return the minimum steps to reach `(n-1,m-1)` from `(0,0)`, or `-1` if impossible.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0},
                {0, 0, 1},
                {1, 1, 0},
                {0, 0, 0},
                {0, 0, 1}
            }
Output: -1
```

**Example 2:**
```
Input:
grid = {
                {0, 1, 0, 1},
                {1, 1, 0, 0},
                {1, 0, 0, 0}
            }
Output: 5
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
