# 15. Maximum Distance From Land

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = water`, `1 = land`. Find a water cell whose **distance to nearest land is maximized**. Return that distance, or `-1` if impossible.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0, 0},
                {0, 1, 0, 1, 1},
                {0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0}
            }
Output: 2
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 1}
            }
Output: 3
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
