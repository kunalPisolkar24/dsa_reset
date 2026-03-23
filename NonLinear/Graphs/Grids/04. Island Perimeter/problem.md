# 4. Island Perimeter

**Difficulty:** Medium

## Problem Statement
Grid contains `0` and `1`. Compute the **total perimeter of all land cells**. A land edge touching water or grid boundary contributes **1 to perimeter**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {0, 1, 0, 0, 0}
            }
Output: 10
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0}
            }
Output: 16
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
