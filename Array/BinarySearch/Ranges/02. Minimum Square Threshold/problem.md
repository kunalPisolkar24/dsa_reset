# 2. Minimum Square Threshold

**Difficulty:** Very Easy

## Problem Statement

Given a non-negative integer `x`, find the **smallest integer y** such that `y * y >= x`.

### Example Testcases

**Example 1:**
```
Input: x = 20
Output: 5
Explanation: 4*4 = 16 (not >= 20). 5*5 = 25 (>= 20). Thus, 5 is the smallest integer.
```

**Example 2:**
```
Input: x = 25
Output: 5
Explanation: 5*5 = 25 (>= 25).
```

## Constraints

- `0 <= x <= 2^31 - 1`
