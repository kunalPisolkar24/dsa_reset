# Binary Weight Graph

**Difficulty:** Medium

## Problem Statement

In a graph where all edges have weight either 0 or 1, find the shortest distance from node `0` to all other nodes. This can be solved more efficiently than standard Dijkstra.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[1, 2, 1], [0, 4, 0], [4, 2, 0], [2, 1, 1], [1, 4, 0], [0, 2, 0], [3, 0, 1], [2, 3, 0], [4, 1, 1], [3, 0, 1]]
Output: [0, 0, 0, 0, 0]
```
**Explanation:** Optimization using a deque (0-1 BFS).

**Example 2:**
```
Input: n = 5, edges = [[3, 4, 0], [0, 2, 0], [2, 1, 0], [0, 3, 1], [3, 4, 0], [2, 1, 1], [1, 2, 0], [4, 3, 0], [0, 4, 0], [3, 2, 0]]
Output: [0, 0, 0, 0, 0]
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 1], [2, 3, 1], [1, 4, 0], [1, 0, 0], [2, 3, 0], [0, 1, 1], [4, 1, 0], [4, 1, 0], [1, 2, 0], [3, 0, 1]]
Output: [0, 0, 0, 0, 0]
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
