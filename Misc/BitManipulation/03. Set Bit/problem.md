# 3. Set Bit

**Difficulty:** Easy

## Problem Statement

Given a non-negative integer `n` and a non-negative integer `i`, return the value obtained after setting the `i`-th bit of `n`.

If the `i`-th bit is already set, return `n` unchanged.

The least significant bit is bit `0`.

### Example Testcases

**Example 1:**
```
Input: n = 10, i = 2
Output: 14
Explanation: 10 in binary is 1010. After setting bit 2, it becomes 1110.
```

**Example 2:**
```
Input: n = 5, i = 0
Output: 5
Explanation: 5 in binary is 0101. Bit 0 is already set.
```

## Constraints

- `0 <= n <= 10^9`
- `0 <= i <= 30`
