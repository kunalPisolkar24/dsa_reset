# 7. Count Leaf Nodes in DFS Tree

**Difficulty:** Medium

## Problem Statement
Run a DFS starting from node `0`. A node in the DFS traversal is considered a leaf if it has no unvisited neighbors when visited. Count how many such leaf nodes exist.

**Note**: When checking neighbors, always iterate them in strictly **ascending order** of labels.

### Example Testcases

**Example 1:**
```
Input:
n = 7
edges = [[2, 4], [1, 4], [0, 5], [3, 6], [2, 5], [3, 5]]
Output: 2
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [0, 4], [1, 5], [1, 4], [2, 3], [4, 5], [2, 5]]
Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
