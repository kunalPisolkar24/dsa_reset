# Remove Boundary Islands

### Problem Statement

You are given a grid containing `0` (water) and `1` (land).

Any **land connected to the boundary** should be removed (turned into `0`).

Return the updated grid.

---

### Example

Input

```
grid = {
 {1,0,0,1},
 {1,1,0,0},
 {0,1,1,0},
 {1,0,1,1}
}
```

Output

```
{
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}
}
```

Explanation
Only **boundary-connected islands disappear**.

