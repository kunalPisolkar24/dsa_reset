# Cheapest Path with K Stops

**Difficulty:** Hard

## Problem Statement

Find the cheapest price from node `0` to node `n-1` with at most `k` intermediate stops (at most `k+1` edges). If node `n-1` is unreachable within `k` stops, return -1.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 3], [0, 2, 5], [0, 3, 13], [1, 2, 4], [1, 2, 8], [3, 0, 3], [0, 3, 5], [1, 3, 5], [3, 0, 14], [1, 3, 2]], k = 2
Output: -1
```
**Explanation:** Multi-dimensional Dijkstra or BFS with cost tracking.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 19], [0, 2, 14], [0, 3, 9], [0, 4, 10], [2, 1, 10], [2, 4, 17], [1, 0, 17], [1, 0, 17], [0, 3, 2], [0, 2, 4]], k = 5
Output: 10
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 5], [0, 3, 9], [0, 4, 11], [3, 1, 12], [1, 3, 17], [2, 3, 11], [3, 0, 16], [2, 3, 9], [2, 0, 2], [0, 1, 3]], k = 2
Output: 11
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
