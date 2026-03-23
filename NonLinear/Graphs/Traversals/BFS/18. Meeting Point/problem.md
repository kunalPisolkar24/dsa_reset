# 18. Meeting Point

**Difficulty:** Hard

## Problem Statement
Two disjoint groups of nodes start spreading signals simultaneously. Find the node(s) where their signals meet furthest along, i.e., minimizing the max time taken to reach the node. Return the nodes sorted.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[2, 4], [2, 5], [1, 3], [1, 4]]
group1 = [3]
group2 = [1]
Output: [1, 3]
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [0, 4], [2, 3], [4, 5], [0, 2], [3, 5]]
group1 = [2, 3]
group2 = [1, 5]
Output: [0, 3, 4, 5]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
