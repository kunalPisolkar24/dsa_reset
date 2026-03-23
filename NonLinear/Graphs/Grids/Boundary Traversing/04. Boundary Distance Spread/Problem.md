# 4. Boundary Distance Spread

**Difficulty:** Medium

## Problem Statement
You are given a `m x n` grid containing only `0` and `1`.

Treat every **boundary cell** with value `1` as a source. Perform a multi-source BFS using **4-directional** movement and compute, for every cell, the minimum distance to any boundary `1`.

Return a grid of distances where:
- A boundary `1` has distance `0`.
- Each step to a 4-directionally adjacent cell increases distance by `1`.
- If there is **no boundary `1`**, every cell should be `-1`.

### Example Testcases

**Example 1:**
```
Input:
grid = {
  {1, 0, 0},
  {0, 0, 0},
  {0, 1, 0}
}

Output:
{
  {0, 1, 2},
  {1, 1, 2},
  {1, 0, 1}
}
```

**Example 2:**
```
Input:
grid = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
}

Output:
{
  {-1, -1, -1, -1},
  {-1, -1, -1, -1},
  {-1, -1, -1, -1}
}
```

**Example 3:**
```
Input:
grid = {
  {1, 0, 1, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 1, 0, 0}
}

Output:
{
  {0, 1, 0, 1},
  {1, 2, 1, 2},
  {2, 1, 2, 3},
  {1, 0, 1, 2}
}
```

## Constraints
- `1 <= m, n <= 200`
- `grid[i][j]` is either `0` or `1`
