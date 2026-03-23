# 9. Count of Subarrays With Sum ≤ K

**Difficulty:** Medium

## Problem Statement

Given an array of integers `nums` and an integer `k`, return the **total number of continuous subarrays** whose sum is **less than or equal to `k`**. All elements in the array are positive.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 2], k = 3
Output: 7
Explanation: 
Subarrays with sum <= 3:
- [1] (Index 0), [2] (Index 1), [1] (Index 2), [2] (Index 3)
- [1, 2] (Indices 0-1), [2, 1] (Indices 1-2), [1, 2] (Indices 2-3)
Total count is 7.
```

**Example 2:**
```
Input: nums = [10, 5, 2, 6], k = 100
Output: 10
Explanation: All possible subarrays (4 * 5 / 2 = 10) have a sum <= 100.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `0 <= k <= 10^9`
