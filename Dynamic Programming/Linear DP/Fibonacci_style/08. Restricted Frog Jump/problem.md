# 8. Restricted Frog Jump

**Difficulty:** Medium

## Problem Statement

A frog is on the first stair (0-indexed as stair 0) of $n$ stairs. Each stair $i$ has a height $h_i$. The frog wants to reach the $(n-1)$-th stair with minimum cost.

The frog has the following jumping rules:
- Normally, the frog can jump to either the next stair $(i+1)$ or the stair after that $(i+2)$.
- However, if the current stair index $i$ is **even**, the frog is restricted and can **only** jump to the next stair $(i+1)$.
- If the current stair index $i$ is **odd**, the frog can jump normally to either $(i+1)$ or $(i+2)$.

The cost of a jump from stair $i$ to stair $j$ is $|h_i - h_j|$.

Find the minimum total cost to reach the $(n-1)$-th stair.

### Example Testcases

**Example 1:**
```
Input: heights = [10, 20, 30, 10]
Output: 20
Explanation:
- Stair 0 (even): Must jump to stair 1. Cost = |20-10| = 10.
- Stair 1 (odd): Can jump to stair 2 or 3. Jump to stair 3. Cost = |10-20| = 10.
Total cost: 10 + 10 = 20.
```

**Example 2:**
```
Input: heights = [10, 15, 20]
Output: 10
Explanation:
- Stair 0 (even): Must jump to stair 1. Cost = 5.
- Stair 1 (odd): Can jump to stair 2. Cost = 5.
Total cost: 10.
```

**Example 3:**
```
Input: heights = [10, 20, 10, 20, 10]
Output: 20
Explanation:
0->1 (10), 1->3 (0), 3->4 (10). Total 20.
```

## Constraints

- `2 <= n <= 10^5`
- `1 <= heights[i] <= 10^4`
