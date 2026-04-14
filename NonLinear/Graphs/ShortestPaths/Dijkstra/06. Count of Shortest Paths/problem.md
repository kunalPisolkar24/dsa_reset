# Count of Shortest Paths

**Difficulty:** Medium

## Problem Statement

Calculate the number of different paths from node `0` to node `n-1` that all have the same minimum total weight. Return the count modulo 10^9+7.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 14], [3, 2, 6], [0, 4, 14], [4, 2, 16], [3, 4, 6], [2, 0, 3], [0, 4, 9], [2, 0, 17], [2, 1, 12], [2, 0, 8]]
Output: 1
```
**Explanation:** Standard Dijkstra combined with dynamic programming.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 16], [1, 2, 1], [4, 2, 14], [4, 3, 4], [1, 4, 8], [3, 2, 6], [3, 4, 10], [0, 1, 2], [2, 3, 5], [3, 0, 7]]
Output: 1
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 7], [0, 4, 19], [4, 0, 8], [4, 2, 19], [1, 0, 13], [2, 0, 10], [3, 2, 9], [1, 3, 12], [2, 0, 2], [1, 2, 1]]
Output: 1
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
