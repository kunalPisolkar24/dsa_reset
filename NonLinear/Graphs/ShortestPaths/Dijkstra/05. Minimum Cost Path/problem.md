# Minimum Cost Path

**Difficulty:** Medium

## Problem Statement

Instead of just the distance, return the actual sequence of nodes (the path) that constitutes the shortest path from node `0` to node `n-1`. If node `n-1` is unreachable from node `0`, return an empty vector.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 16], [0, 2, 10], [3, 4, 4], [2, 1, 4], [0, 3, 20], [4, 3, 9], [0, 4, 19], [4, 1, 5], [2, 1, 17], [4, 1, 14]]
Output: [0, 4]
```
**Explanation:** Path reconstruction using parent tracking during Dijkstra.

**Example 2:**
```
Input: n = 5, edges = [[0, 2, 1], [3, 4, 12], [2, 0, 7], [4, 2, 17], [3, 0, 19], [0, 4, 20], [0, 4, 6], [0, 3, 18], [4, 0, 7], [0, 4, 12]]
Output: [0, 4]
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 9], [1, 2, 15], [1, 4, 6], [1, 0, 1], [1, 0, 11], [0, 2, 16], [4, 2, 18], [4, 3, 9], [2, 3, 12], [2, 4, 6]]
Output: [0, 1, 4]
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
