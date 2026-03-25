# 5. Toggle Bit

**Difficulty:** Easy

## Problem Statement

Given a non-negative integer `n` and a non-negative integer `i`, return the value obtained after toggling the `i`-th bit of `n`.

Toggling means changing `1` to `0` and `0` to `1`.

The least significant bit is bit `0`.

### Example Testcases

**Example 1:**
```
Input: n = 10, i = 1
Output: 8
Explanation: 10 in binary is 1010. After toggling bit 1, it becomes 1000.
```

**Example 2:**
```
Input: n = 10, i = 0
Output: 11
Explanation: 10 in binary is 1010. After toggling bit 0, it becomes 1011.
```

## Constraints

- `0 <= n <= 10^9`
- `0 <= i <= 30`
