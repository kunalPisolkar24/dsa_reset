# Basic Shortest Distance

**Difficulty:** Easy

## Problem Statement

Given a weighted undirected graph with `n` nodes and `edges` where each edge is `[u, v, w]`, find the shortest distance from node `0` to all other nodes. If a node is unreachable from node `0`, its distance should be `-1`.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 2], [1, 3, 11], [3, 4, 3], [4, 0, 4], [3, 4, 11], [4, 2, 19], [0, 4, 17], [1, 3, 20], [3, 4, 15], [3, 0, 6]]
Output: [0, 2, 23, 6, 4]
```
**Explanation:** Find shortest path from root to all reachable destinations using edges weights.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 20], [1, 2, 18], [0, 3, 7], [0, 4, 12], [1, 3, 16], [2, 4, 10], [0, 1, 19], [2, 3, 18], [4, 2, 19], [1, 3, 2]]
Output: [0, 9, 22, 7, 12]
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 15], [1, 2, 18], [1, 3, 7], [1, 4, 13], [3, 0, 19], [0, 1, 19], [2, 0, 16], [3, 1, 7], [1, 0, 2], [3, 4, 5]]
Output: [0, 2, 16, 9, 14]
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
