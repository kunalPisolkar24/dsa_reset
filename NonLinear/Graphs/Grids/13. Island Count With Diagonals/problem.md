# 13. Island Count With Diagonals

**Difficulty:** Medium

## Problem Statement
Same as Island counting but connectivity includes **8 directions**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            }
Output: 1
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 1, 0},
                {0, 1, 0, 0}
            }
Output: 2
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
