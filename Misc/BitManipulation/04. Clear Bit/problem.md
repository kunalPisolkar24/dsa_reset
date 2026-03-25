# 4. Clear Bit

**Difficulty:** Easy

## Problem Statement

Given a non-negative integer `n` and a non-negative integer `i`, return the value obtained after clearing the `i`-th bit of `n`.

If the `i`-th bit is already `0`, return `n` unchanged.

The least significant bit is bit `0`.

### Example Testcases

**Example 1:**
```
Input: n = 14, i = 2
Output: 10
Explanation: 14 in binary is 1110. After clearing bit 2, it becomes 1010.
```

**Example 2:**
```
Input: n = 5, i = 1
Output: 5
Explanation: 5 in binary is 0101. Bit 1 is already 0.
```

## Constraints

- `0 <= n <= 10^9`
- `0 <= i <= 30`
