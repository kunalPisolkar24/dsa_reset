# 4. Distinct Elements in Every Window

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` and an integer `k`, return an array where each element represents the **count of distinct elements** in each contiguous subarray of size `k`.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 3, 4, 2, 3], k = 4
Output: [3, 4, 4, 3]
Explanation: 
Subarrays of size 4:
- [1,2,1,3] → distinct: {1,2,3} = 3
- [2,1,3,4] → distinct: {1,2,3,4} = 4
- [1,3,4,2] → distinct: {1,3,4,2} = 4
- [3,4,2,3] → distinct: {2,3,4} = 3
```

**Example 2:**
```
Input: nums = [1, 2, 1, 2, 1], k = 3
Output: [2, 2, 2]
Explanation: 
Subarrays of size 3:
- [1,2,1] → distinct: {1,2} = 2
- [2,1,2] → distinct: {1,2} = 2
- [1,2,1] → distinct: {1,2} = 2
```

## Constraints

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
