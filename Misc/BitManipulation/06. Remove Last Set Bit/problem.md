# 6. Remove Last Set Bit

**Difficulty:** Medium

## Problem Statement

Given a non-negative integer `n`, return the result after removing its lowest set bit.

The lowest set bit is the rightmost bit whose value is `1`.

If `n` is `0`, return `0`.

### Example Testcases

**Example 1:**
```
Input: n = 12
Output: 8
Explanation: 12 in binary is 1100. Removing the lowest set bit gives 1000.
```

**Example 2:**
```
Input: n = 7
Output: 6
Explanation: 7 in binary is 111. Removing the lowest set bit gives 110.
```

## Constraints

- `0 <= n <= 10^9`
