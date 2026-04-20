# 13. Sum of Subarray Minimums

**Difficulty:** Hard

## Problem Statement

Given an array of integers, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of the array.

### Example Testcases

**Example 1:**
```
Input: arr = {3, 1, 2, 4}
Output: 17
Explanation: Subarrays: [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. Mins: 3+1+2+4+1+1+2+1+1+1 = 17.
```

**Example 2:**
```
Input: arr = {11, 81, 94, 43, 3}
Output: 444
```

**Example 3:**
```
Input: arr = {1, 2, 3}
Output: 10
```

## Constraints

- `1 <= n <= 3 * 10^4` 
- `1 <= arr[i] <= 3 * 10^4`
