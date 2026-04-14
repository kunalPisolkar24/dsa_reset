# Signal Spread Time

**Difficulty:** Medium

## Problem Statement

A signal starts at node `0` and travels through edges with weight `w` (representing time). Return the minimum time needed for the signal to reach EVERY node in the graph. If some nodes are unreachable, return -1.

### Example Testcases

**Example 1:**
```
Input: n = 5, edges = [[0, 1, 2], [1, 2, 8], [0, 3, 6], [1, 4, 16], [4, 3, 7], [1, 2, 14], [1, 0, 14], [1, 3, 12], [0, 1, 16], [2, 1, 18]]
Output: 13
```
**Explanation:** The spread time is the maximum of all shortest path distances.

**Example 2:**
```
Input: n = 5, edges = [[0, 1, 20], [2, 3, 3], [3, 4, 11], [2, 3, 12], [3, 1, 5], [2, 0, 10], [4, 1, 9], [1, 3, 10], [3, 1, 18], [0, 1, 11]]
Output: 20
```
**Example 3:**
```
Input: n = 5, edges = [[0, 1, 4], [1, 2, 9], [2, 4, 7], [0, 3, 17], [4, 3, 11], [4, 2, 7], [4, 1, 12], [2, 0, 3], [2, 4, 13], [0, 4, 18]]
Output: 17
```
## Constraints

- $1 \le n \le 10^5$
- $0 \le edges.length \le 2 \times 10^5$
- Weights are non-negative integers ($\le 10^4$).
