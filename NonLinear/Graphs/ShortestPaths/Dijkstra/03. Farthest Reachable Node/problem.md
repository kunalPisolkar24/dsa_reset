# Farthest Reachable Node

**Difficulty:** Medium

## Problem Statement

From node `0`, identify the node that has the maximum shortest-path distance. If multiple nodes share the same maximum distance, return the one with the smallest index.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 2, 7], [2, 4, 20], [1, 2, 9], [4, 2, 4], [2, 4, 17], [4, 1, 16], [1, 4, 6], [2, 3, 3], [0, 1, 2], [1, 0, 4]]
Output: 3
```
**Explanation:** Identify the 'most isolated' reachable node.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 8], [0, 3, 2], [1, 4, 8], [2, 1, 9], [4, 2, 7], [0, 1, 8], [3, 1, 4], [4, 2, 9], [0, 1, 5], [2, 0, 2]]
Output: 4
```
**Example 3:**
```
Input: n = 5, edges = [[0, 2, 9], [1, 3, 2], [3, 4, 4], [0, 4, 3], [1, 4, 11], [1, 0, 6], [3, 1, 5], [3, 2, 19], [1, 3, 1], [2, 3, 7]]
Output: 2
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
