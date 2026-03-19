# 1. Fixed Window Maximum Sum

**Difficulty:** Easy

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **maximum sum of any contiguous subarray of size exactly `k`**.

### Example Testcases

**Example 1:**
```
Input: nums = [2, 1, 5, 1, 3, 2], k = 3
Output: 9
Explanation: 
Subarrays of size 3:
- [2,1,5] = 8
- [1,5,1] = 7
- [5,1,3] = 9
- [1,3,2] = 6
Maximum sum is 9.
```

**Example 2:**
```
Input: nums = [1, 2, 3, 4, 5], k = 2
Output: 9
Explanation: 
Maximum sum is [4,5] = 9.
```

## Constraints

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
