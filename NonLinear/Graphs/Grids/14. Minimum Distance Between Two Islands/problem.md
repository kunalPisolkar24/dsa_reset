# 14. Minimum Distance Between Two Islands

**Difficulty:** Hard

## Problem Statement
Grid contains exactly two islands of `1`s. You may convert `0` to `1`. Return the **minimum number of flips required to connect the islands**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0},
                {1, 0, 0},
                {1, 0, 1},
                {1, 0, 0}
            }
Output: 1
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0}
            }
Output: 1
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
