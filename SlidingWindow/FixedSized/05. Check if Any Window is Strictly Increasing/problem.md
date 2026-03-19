# 5. Check if Any Window is Strictly Increasing

**Difficulty:** Easy

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if **any contiguous subarray of size `k` is strictly increasing**, otherwise return `false`.

A subarray is strictly increasing if each element is strictly greater than its preceding element in the subarray.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3, 1, 2], k = 3
Output: true
Explanation: 
The subarray [1, 2, 3] is strictly increasing.
```

**Example 2:**
```
Input: nums = [5, 4, 3, 2, 1], k = 2
Output: false
Explanation: 
There is no strictly increasing subarray of size 2.
```

**Example 3:**
```
Input: nums = [1, 5, 5, 6], k = 2
Output: true
Explanation: 
The subarray [1, 5] and [5, 6] are strictly increasing.
```

## Constraints

- `2 <= k <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`
