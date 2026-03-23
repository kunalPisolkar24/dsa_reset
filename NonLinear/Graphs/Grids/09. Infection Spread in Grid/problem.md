# 9. Infection Spread in Grid

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = empty`, `1 = healthy`, `2 = infected`. Each second, infected cells infect **4-direction neighbors**. Return time required to infect all healthy cells. Return `-1` if impossible.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {2, 1, 0},
                {1, 1, 0},
                {1, 1, 2}
            }
Output: 2
```

**Example 2:**
```
Input:
grid = {
                {1, 0, 1, 1},
                {0, 0, 0, 0},
                {1, 1, 1, 1}
            }
Output: -1
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
