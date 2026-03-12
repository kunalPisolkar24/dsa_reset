# Boundary Flood Fill

### Problem Statement

You are given a grid containing `0` and `1`.

From **all boundary cells containing 1**, perform a DFS/BFS and mark every connected `1` as `2`.

Return the modified grid.

---

### Example

Input

```
grid = {
 {1,0,1,0},
 {1,1,0,0},
 {0,1,1,0},
 {0,0,1,1}
}
```

Output

```
{
 {2,0,2,0},
 {2,2,0,0},
 {0,2,2,0},
 {0,0,2,2}
}
```

