# Boundary Distance Spread

### Problem Statement

You are given a grid containing `0` and `1`.

Treat **all boundary cells containing 1 as sources**.

Spread outward (like BFS). Each step increases distance by `1`.

Return a grid where every cell contains the **minimum distance from the nearest boundary 1**.

Cells unreachable from boundary 1 should be `-1`.

---

### Example

Input

```
grid = {
 {1,0,0},
 {0,0,0},
 {0,1,0}
}
```

Output

```
{
 {0,1,2},
 {1,1,2},
 {1,0,1}
}
```

