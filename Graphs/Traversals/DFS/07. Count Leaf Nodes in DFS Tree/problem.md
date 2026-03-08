# 7. Count Leaf Nodes in DFS Tree

**Difficulty:** Medium

## Problem Statement
Run a DFS starting from node `0`. A node in the DFS traversal is considered a leaf if it has no unvisited neighbors when visited. Count how many such leaf nodes exist.

**Note**: When checking neighbors, always iterate them in strictly **ascending order** of labels.

### Example Testcases

**Example 1:**
```
Input:
n = 18
edges = [[4, 9], [9, 11], [1, 9], [2, 8], [13, 14], [7, 10], [7, 13], [3, 6], [4, 17], [8, 14], [2, 4], [0, 16], [6, 7], [12, 14], [4, 16], [3, 17], [0, 3], [5, 17], [0, 12], [10, 16], [7, 14]]
Output: 5
```

**Example 2:**
```
Input:
n = 13
edges = [[4, 10], [3, 8], [0, 10], [9, 12], [4, 6], [3, 10], [0, 2], [3, 9], [3, 5]]
Output: 5
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
