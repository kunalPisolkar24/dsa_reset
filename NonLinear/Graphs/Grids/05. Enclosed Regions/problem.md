# 5. Enclosed Regions

**Difficulty:** Medium

## Problem Statement
Grid contains 'X' and 'O'. Convert all 'O' cells **completely surrounded by X** into 'X'. Any 'O' connected to a **boundary O** remains unchanged.

### Example Testcases

**Example 1:**
```
Input:
grid = {
                {'O', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'O'},
                {'O', 'X', 'O', 'X'},
                {'O', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'}
            }
Output: {
                {'O', 'X', 'X', 'X'},
                {'O', 'O', 'X', 'O'},
                {'O', 'X', 'X', 'X'},
                {'O', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'}
            }
```

**Example 2:**
```
Input:
grid = {
                {'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'O', 'O', 'X'},
                {'X', 'O', 'X', 'X', 'O'}
            }
Output: {
                {'X', 'X', 'O', 'X', 'X'},
                {'O', 'X', 'O', 'O', 'X'},
                {'X', 'O', 'X', 'X', 'O'}
            }
```

## Constraints
- `1 <= grid.length, grid[0].length <= 500`
