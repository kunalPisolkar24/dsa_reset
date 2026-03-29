# 1. Integer Square Root (Binary Search on Answer Space)

**Difficulty:** Medium

## Problem Statement

Given a non-negative integer `x`, compute and return the square root of `x`. Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

In other words, return the largest integer `y` such that `y * y <= x`.

**Requirement:** You must use binary search on the range `[0, x]` and handle potential overflows in your checks. Time complexity must be $O(\log x)$.

### Example Testcases

**Example 1:**
```
Input: x = 4
Output: 2
```

**Example 2:**
```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

## Constraints

- `0 <= x <= 2^31 - 1`
