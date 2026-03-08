# 1. Print DFS Traversal

**Difficulty:** Easy

## Problem Statement
You are given an undirected graph with `n` nodes and `m` edges.

Start DFS traversal from node `0`. If there are any unvisited nodes left after the traversal, pick the smallest unvisited node and start a new DFS until all nodes are visited.

**Note**: When iterating through a node's neighbors, ALWAYS visit them in strictly **ascending order** of their labels.

Return the order in which nodes are visited.

### Example Testcases

**Example 1:**
```
Input:
n = 4
edges = [[0, 1], [1, 2], [2, 3], [0, 2], [1, 3]]
Output: [0, 1, 2, 3]
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [2, 4], [1, 2], [3, 4], [0, 3], [1, 4], [2, 3], [4, 5], [1, 3]]
Output: [0, 1, 2, 3, 4, 5]
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
