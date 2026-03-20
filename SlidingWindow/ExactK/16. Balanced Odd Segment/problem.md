# 16. Balanced Odd Segment

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **number of subarrays** that contain **exactly `k` odd numbers**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 1, 2, 1, 1], k = 3
Output: 2
Explanation: Subarrays with exactly 3 odd numbers: [1, 1, 2, 1] and [1, 2, 1, 1].
```

**Example 2:**
```
Input: nums = [2, 4, 6], k = 1
Output: 0
Explanation: No odd numbers exist in the array.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
