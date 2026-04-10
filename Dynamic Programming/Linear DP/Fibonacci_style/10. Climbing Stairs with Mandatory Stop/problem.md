# 10. Climbing Stairs with Mandatory Stop

**Difficulty:** Medium

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb **1 or 2** steps. However, there is a mandatory stop at step **m** ($0 < m < n$). You **must** land on step **m** during your climb.

In how many distinct ways can you climb to the top?

Since the number of ways can be large, return the result **modulo 10^9 + 7**.

### Example Testcases

**Example 1:**
```
Input: n = 3, m = 1
Output: 2
Explanation:
Ways to reach step 1: (1) -> 1 way.
Ways to reach step 3 from step 1 (distance 2): (1,1), (2) -> 2 ways.
Total ways: 1 * 2 = 2.
Specific paths: (1, 1, 1), (1, 2).
```

**Example 2:**
```
Input: n = 5, m = 2
Output: 6
Explanation:
Ways to reach step 2: (1,1), (2) -> 2 ways.
Ways to reach step 5 from step 2 (distance 3): (1,1,1), (1,2), (2,1) -> 3 ways.
Total ways: 2 * 3 = 6.
```

**Example 3:**
```
Input: n = 4, m = 2
Output: 4
Explanation:
Ways to 2: 2.
Ways from 2 to 4 (dist 2): 2.
Total: 2 * 2 = 4.
```

## Constraints

- `2 <= n <= 10^5`
- `1 <= m < n`
- Result should be modulo `10^9 + 7`.
