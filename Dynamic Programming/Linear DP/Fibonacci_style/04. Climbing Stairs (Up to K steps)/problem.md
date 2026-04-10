# 4. Climbing Stairs (Up to K steps)

**Difficulty:** Medium

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can climb any number of steps from **1 to k** inclusive. In how many distinct ways can you climb to the top?

Since the number of ways can be very large, return the result **modulo 10^9 + 7**.

### Example Testcases

**Example 1:**
```
Input: n = 3, k = 2
Output: 3
Explanation: The ways are:
1. 1+1+1
2. 1+2
3. 2+1
```

**Example 2:**
```
Input: n = 4, k = 2
Output: 5
Explanation: The ways are:
(1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2)
```

**Example 3:**
```
Input: n = 5, k = 3
Output: 13
Explanation: Ways to reach 5 with steps {1, 2, 3}.
```

## Constraints

- `1 <= n <= 1000`
- `1 <= k <= 100`
- Result should be modulo `10^9 + 7`.
