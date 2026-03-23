# 3. Largest Island Size

**Difficulty:** Medium

## Problem Statement
Grid contains `0` and `1`. Return the **size of the largest island** using 4-direction adjacency.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0, 0, 1},
                {0, 0, 0, 1, 0},
                {1, 1, 0, 0, 0}
            }
Output: 2
```

**Example 2:**
```
Input:
grid = {
                {1, 0, 0},
                {0, 1, 1},
                {0, 0, 0},
                {0, 0, 0},
                {1, 1, 1}
            }
Output: 3
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
