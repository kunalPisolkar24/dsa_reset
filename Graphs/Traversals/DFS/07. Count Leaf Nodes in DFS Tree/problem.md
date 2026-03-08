# 7. Count Leaf Nodes in DFS Tree

**Difficulty:** Medium

## Problem Statement
Run a DFS starting from node `0`. A node in the DFS traversal is considered a leaf if it has no unvisited neighbors when visited. Count how many such leaf nodes exist.

**Note**: When checking neighbors, always iterate them in strictly **ascending order** of labels.

### Example Testcases

**Example 1:**
```
Input:
n = 17
edges = [[2, 14], [0, 7], [1, 3], [0, 10], [2, 16], [8, 16], [14, 15], [4, 5], [3, 9], [5, 6], [6, 16], [3, 12], [5, 9], [8, 15], [10, 12], [4, 7], [0, 11]]
Output: 4
```

**Example 2:**
```
Input:
n = 4
edges = [[0, 2], [1, 3]]
Output: 1
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
