# 3. Maximum Even Numbers in Window

**Difficulty:** Easy

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **maximum count of even numbers** in any contiguous subarray of size `k`.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 4, 6, 3], k = 3
Output: 3
Explanation: 
Subarrays of size 3:
- [1,2,4] → 2 evens
- [2,4,6] → 3 evens
- [4,6,3] → 2 evens
Maximum count is 3.
```

**Example 2:**
```
Input: nums = [1, 3, 5, 7], k = 2
Output: 0
Explanation: 
No even numbers exist in the array.
```

**Example 3:**
```
Input: nums = [2, 4, 6], k = 1
Output: 1
Explanation: 
All elements are even. Subarrays of size 1 have at most 1 even number.
```

## Constraints

- `1 <= k <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`
