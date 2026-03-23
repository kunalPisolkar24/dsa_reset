# 10. Fire Spread Escape

**Difficulty:** Hard

## Problem Statement
Grid contains `.` (empty), `#` (wall), `F` (fire), `S` (start). Fire spreads every second in 4-directions. You move one step per second. Return `true` if S can reach the boundary before fire reaches it, else `false`.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {'#', '.', '.', '.'},
                {'.', '#', '#', '.'},
                {'.', '.', '#', '.'},
                {'.', '.', '.', '.'},
                {'S', '.', '.', '.'}
            }
Output: true
```

**Example 2:**
```
Input:
grid = {
                {'.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.'},
                {'.', '.', '#', '.', '.'},
                {'.', '.', 'F', 'S', '#'}
            }
Output: true
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
