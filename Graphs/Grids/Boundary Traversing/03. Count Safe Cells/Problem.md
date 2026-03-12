# Count Safe Cells

### Problem Statement

You are given a grid containing `0` and `1`.

A cell is **safe** if it is a `1` and **NOT connected to any boundary `1`**.

Return the **count of safe cells**.

---

### Example

Input

```
grid = {
 {1,1,1,1},
 {1,0,0,1},
 {1,0,1,1},
 {1,1,1,1}
}
```

Output

```
0
```

Explanation

All 1s are connected to the boundary.

