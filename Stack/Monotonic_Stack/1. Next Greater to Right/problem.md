# 1. Next Greater to Right

**Difficulty:** Easy

## Problem Statement

Given an array, for each element find the first greater element to its right. If no such element exists, return -1. This problem is the classic introduction to the monotonic stack pattern.

### Example Testcases

**Example 1:**
```
Input: arr = {4, 5, 2, 10}
Output: {5, 10, 10, -1}
Explanation: 4->5, 5->10, 2->10, 10->none
```

**Example 2:**
```
Input: arr = {1, 2, 3, 4}
Output: {2, 3, 4, -1}
```

**Example 3:**
```
Input: arr = {4, 3, 2, 1}
Output: {-1, -1, -1, -1}
```

## Constraints

- `1 <= n <= 10^5` 
- `-10^9 <= arr[i] <= 10^9`
