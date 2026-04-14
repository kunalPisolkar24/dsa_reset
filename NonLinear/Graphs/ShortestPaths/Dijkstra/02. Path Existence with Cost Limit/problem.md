# Path Existence with Cost Limit

**Difficulty:** Easy

## Problem Statement

You are given a weighted graph. Determine if there exists a path from node `0` to node `n-1` such that the total sum of edge weights on the path is less than or equal to `k`. If node `n-1` is unreachable from node `0`, return `false`.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 6], [0, 2, 6], [0, 3, 8], [3, 2, 16], [1, 0, 11], [1, 2, 5], [0, 1, 6], [0, 1, 5], [4, 0, 7], [2, 1, 15]], k = 1
Output: false
```
**Explanation:** Check if target is reachable within a budget.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 7], [0, 2, 18], [1, 3, 13], [2, 1, 20], [1, 0, 7], [0, 3, 15], [0, 4, 3], [0, 1, 6], [1, 0, 1], [3, 0, 15]], k = 3
Output: true
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 13], [1, 2, 11], [1, 3, 3], [1, 4, 14], [3, 4, 12], [0, 4, 14], [0, 3, 16], [0, 1, 6], [1, 0, 13], [0, 1, 16]], k = 1
Output: false
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
