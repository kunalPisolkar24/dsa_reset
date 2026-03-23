# 1. Boundary Flood Fill

**Difficulty:** Easy

## Problem Statement
You are given a `m x n` grid containing only `0` and `1`.

Starting from every **boundary cell** that contains `1`, perform a flood fill using **4-directional** adjacency (up, down, left, right) and change every connected `1` to `2`.

Return the modified grid.

### Example Testcases

**Example 1:**
```
Input:
grid = {
  {1, 0, 1, 0},
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1}
}

Output:
{
  {2, 0, 2, 0},
  {2, 2, 0, 0},
  {0, 2, 2, 0},
  {0, 0, 2, 2}
}
```

**Example 2:**
```
Input:
grid = {
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1}
}

Output:
{
  {0, 0, 0, 0},
  {2, 0, 0, 0},
  {2, 2, 2, 2}
}
```

**Example 3:**
```
Input:
grid = {
  {0, 0, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0}
}

Output:
{
  {0, 0, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {0, 0, 0, 0}
}
```

## Constraints
- `1 <= m, n <= 200`
- `grid[i][j]` is either `0` or `1`
