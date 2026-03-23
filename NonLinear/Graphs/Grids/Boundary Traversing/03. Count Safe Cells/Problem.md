# 3. Count Safe Cells

**Difficulty:** Easy

## Problem Statement
You are given a `m x n` grid containing only `0` and `1`.

A cell is **safe** if it is `1` and **not connected to any boundary `1`** using **4-directional** adjacency.

Return the **number of safe cells**.

### Example Testcases

**Example 1:**
```
Input:
grid = {
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 0, 1, 1},
  {1, 1, 1, 1}
}

Output:
0
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
4
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
0
```

## Constraints
- `1 <= m, n <= 200`
- `grid[i][j]` is either `0` or `1`
