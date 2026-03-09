# 14. Infection Spread

**Difficulty:** Medium

## Problem Statement
Multiple nodes are initially infected. The infection spreads to all neighbors every second. Return the time until the entire connected component(s) containing the sources becomes fully infected.

### Example Testcases

**Example 1:**
```
Input:
n = 6
edges = [[2, 4], [1, 2], [0, 4], [1, 5], [0, 3], [0, 5]]
sources = [5]

Output: 2
```

**Example 2:**
```
Input:
n = 6
edges = [[0, 1], [1, 2], [3, 4], [1, 5], [0, 3], [0, 2], [0, 5]]
sources = [2, 3]

Output: 2
```

## Constraints
- `1 <= n <= 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
