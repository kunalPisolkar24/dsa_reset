# 2. Count Islands

**Difficulty:** Easy

## Problem Statement
Grid contains `0` (water) and `1` (land). Return the number of **connected components of land** using **4-direction adjacency**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 1},
                {0, 0, 0}
            }
Output: 1
```

**Example 2:**
```
Input:
grid = {
                {0, 0, 0},
                {1, 0, 0},
                {0, 0, 1},
                {1, 0, 1},
                {1, 1, 0}
            }
Output: 3
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
