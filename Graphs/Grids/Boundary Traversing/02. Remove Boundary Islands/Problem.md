# 2. Remove Boundary Islands

**Difficulty:** Easy

## Problem Statement
You are given a `m x n` grid containing only `0` (water) and `1` (land).

Any land cell connected to the **boundary** (top row, bottom row, left column, right column) through **4-directional** adjacency is considered a boundary island and must be removed (changed to `0`).

Return the updated grid after removing all boundary-connected land.

### Example Testcases

**Example 1:**
```
Input:
grid = {
  {1, 0, 0, 1},
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {1, 0, 1, 1}
}

Output:
{
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
}
```

**Example 2:**
```
Input:
grid = {
  {0, 0, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {0, 0, 0, 0}
}

Output:
{
  {0, 0, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {0, 0, 0, 0}
}
```

**Example 3:**
```
Input:
grid = {
  {1, 1, 1},
  {1, 1, 1},
  {1, 1, 1}
}

Output:
{
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
}
```

## Constraints
- `1 <= m, n <= 200`
- `grid[i][j]` is either `0` or `1`
