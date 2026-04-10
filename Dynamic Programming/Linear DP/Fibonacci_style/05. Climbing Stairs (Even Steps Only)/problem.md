# 5. Climbing Stairs (Even Steps Only)

**Difficulty:** Easy

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

However, you can only take steps of **even** sizes, specifically **2** or **4** steps at a time. In how many distinct ways can you climb to the top?

Return the result **modulo 10^9 + 7**.

### Example Testcases

**Example 1:**
```
Input: n = 4
Output: 2
Explanation: The ways are:
1. 2+2
2. 4
```

**Example 2:**
```
Input: n = 6
Output: 3
Explanation: The ways are:
1. 2+2+2
2. 2+4
3. 4+2
```

**Example 3:**
```
Input: n = 5
Output: 0
Explanation: Since we can only take even steps, we can never reach an odd step.
```

## Constraints

- `1 <= n <= 100`
- Result should be modulo `10^9 + 7`.
