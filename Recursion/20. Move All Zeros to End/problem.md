# 20. Move All Zeros to End

**Difficulty:** Easy

## Problem Statement

Given an array of `N` integers, move all zeros in the array to the end while maintaining the relative order of the non-zero elements. Use **recursion** and return the new modified array. Do not use loops.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 0, 3, 0, 5]
Output: [1, 3, 5, 0, 0]
```

**Example 2:**
```
Input: arr = [0, 0, 1]
Output: [1, 0, 0]
```

## Constraints

- `1 <= N <= 10^4`
- `-10^9 <= arr[i] <= 10^9`
