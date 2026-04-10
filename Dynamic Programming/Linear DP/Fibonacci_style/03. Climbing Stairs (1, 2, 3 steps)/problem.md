# 3. Climbing Stairs (1, 2, 3 steps)

**Difficulty:** Easy

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb **1**, **2**, or **3** steps. In how many distinct ways can you climb to the top?

### Example Testcases

**Example 1:**
```
Input: n = 3
Output: 4
Explanation: There are four ways to climb to the top.
1. 1+1+1
2. 1+2
3. 2+1
4. 3
```

**Example 2:**
```
Input: n = 4
Output: 7
Explanation: There are seven ways to climb to the top.
(1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1)
```

**Example 3:**
```
Input: n = 1
Output: 1
Explanation: Only one way: (1)
```

## Constraints

- `1 <= n <= 35`
- The answer will fit in a 32-bit signed integer.
