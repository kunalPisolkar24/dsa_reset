# 6. Climbing Stairs (Custom Steps)

**Difficulty:** Medium

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

You are given an array of integers `steps`, representing the number of steps you can take at once. In how many distinct ways can you climb to the top?

Since the number of ways can be very large, return the result **modulo 10^9 + 7**.

### Example Testcases

**Example 1:**
```
Input: n = 5, steps = [1, 3, 5]
Output: 5
Explanation: The ways are:
1. 1+1+1+1+1
2. 1+1+3
3. 1+3+1
4. 3+1+1
5. 5
```

**Example 2:**
```
Input: n = 4, steps = [2, 4]
Output: 2
Explanation: (2,2) and (4)
```

**Example 3:**
```
Input: n = 10, steps = [1]
Output: 1
Explanation: Only one way: (1,1,1,1,1,1,1,1,1,1)
```

## Constraints

- `1 <= n <= 1000`
- `1 <= steps.length <= 100`
- `1 <= steps[i] <= n`
- All elements in `steps` are unique.
- Result should be modulo `10^9 + 7`.
