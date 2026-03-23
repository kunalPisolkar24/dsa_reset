# 12. Nearest Water Cell

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = water`, `1 = land`. For every land cell, compute distance to **nearest water**. Output matrix should be `-1` for any unreachable regions.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {1, 1, 1, 1},
                {1, 1, 1, 0},
                {1, 0, 1, 1}
            }
Output: {
                {3, 2, 2, 1},
                {2, 1, 1, 0},
                {1, 0, 1, 1}
            }
```

**Example 2:**
```
Input:
grid = {
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1}
            }
Output: {
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1}
            }
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
