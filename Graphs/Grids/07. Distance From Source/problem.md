# 7. Distance From Source

**Difficulty:** Medium

## Problem Statement
Grid contains `0 = empty`, `1 = wall`. Given a source `(r,c)`, compute **distance of every reachable cell from the source**. Unreachable cells (and walls) return `-1`.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {0, 0, 1, 0, 0},
                {0, 0, 1, 1, 0},
                {1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0}
            }
r = 3\nc = 4\nOutput: {
                {7, 6, -1, 4, 3},
                {6, 5, -1, -1, 2},
                {-1, 4, 3, 2, 1},
                {-1, -1, 2, 1, 0}
            }
```

**Example 2:**
```
Input:
grid = {
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0}
            }
r = 2\nc = 1\nOutput: {
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
                {-1, -1, -1, -1}
            }
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
