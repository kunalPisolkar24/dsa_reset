# 9. Count of Subarrays With Sum ≤ K

**Difficulty:** Medium

## Problem Statement

Given an array of **positive integers** `nums` and an integer `k`, return the **total number of continuous subarrays** whose sum is **less than or equal to `k`**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 2], k = 3
Output: 7
Explanation: 
Subarrays:
- [1] (sum 1)
- [1, 2] (sum 3)
- [2] (sum 2)
- [2, 1] (sum 3)
- [1] (sum 1)
- [1, 2] (sum 3)
- [2] (sum 2)
Total = 7
```

**Example 2:**
```
Input: nums = [10, 5, 2, 6], k = 100
Output: 10
Explanation: All subarrays have sum <= 100. (4*5/2 = 10)
```

**Example 3:**
```
Input: nums = [1, 2, 3], k = 0
Output: 0
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `0 <= k <= 10^9`
