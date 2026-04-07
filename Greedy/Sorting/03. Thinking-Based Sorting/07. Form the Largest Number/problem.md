# 7. Form the Largest Number

**Difficulty:** Medium

## Problem Statement

Given a list of non-negative integers `arr`, arrange them such that they form the largest possible number.

The result should be a string because the numbers can be very large.

### Example Testcases

**Example 1:**
```
Input: arr = [3, 30, 34, 5, 9]
Output: "9534330"
Explanation: The combinations are "3303459", "9534330", etc. "9534330" is the largest.
```

**Example 2:**
```
Input: arr = [10, 2]
Output: "210"
```

**Example 3:**
```
Input: arr = [0, 0]
Output: "0"
Explanation: Not "00".
```

## Constraints

- `1 <= n <= 10^5`
- `0 <= arr[i] <= 10^9`
