# 10. Build Parent Tree

**Difficulty:** Medium

## Problem Statement
Return an array `parent` where `parent[i]` is the node that discovered `i` during BFS from `0`. The parent of `0` is `-1`. Unreachable nodes should also have a parent of `-1`.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[1, 2], [0, 4], [0, 3], [0, 2], [3, 6], [3, 5]]


Output: [-1, 2, 0, 0, 0, 3, 3]
```

**Example 2:**
```
Input:
n = 7
edges = [[0, 4], [4, 6], [3, 6], [1, 6], [2, 5], [3, 5]]


Output: [-1, 6, 5, 6, 0, 3, 4]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
