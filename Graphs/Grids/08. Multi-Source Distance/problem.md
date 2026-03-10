# 8. Multi-Source Distance

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = empty`, `1 = source`. For every cell, compute **distance to nearest source**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 1, 0},
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0}
            }
Output: {
                {1, 0, 1},
                {2, 1, 2},
                {1, 0, 1},
                {2, 1, 2}
            }
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 1, 0},
                {1, 0, 0, 0},
                {0, 0, 1, 0}
            }
Output: {
                {1, 1, 0, 1},
                {0, 1, 1, 2},
                {1, 1, 0, 1}
            }
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
