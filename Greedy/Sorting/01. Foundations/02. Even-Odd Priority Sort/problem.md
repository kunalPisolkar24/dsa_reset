# 2. Even-Odd Priority Sort

**Difficulty:** Easy

## Problem Statement

Given an integer array `arr`, rearrange it according to the following rules:

1.  All **even numbers** must appear first, sorted in **ascending order**.
2.  All **odd numbers** must appear after the even numbers, sorted in **descending order**.

### Example Testcases

**Example 1:**
```
Input: arr = [4, 7, 2, 9, 1, 6]
Output: [2, 4, 6, 9, 7, 1]
Explanation: Even numbers (2, 4, 6) sorted ascending, then Odd numbers (9, 7, 1) sorted descending.
```

**Example 2:**
```
Input: arr = [1, 3, 5, 2, 4]
Output: [2, 4, 5, 3, 1]
```

**Example 3:**
```
Input: arr = [10, 20, 30]
Output: [10, 20, 30]
```

## Constraints

- `1 <= n <= 10^5`
- `-10^9 <= arr[i] <= 10^9`
