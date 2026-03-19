# 6. Longest Subarray With Sum ≤ K

**Difficulty:** Medium

## Problem Statement

Given an array of integers `nums` and an integer `k`, return the **maximum length** of a contiguous subarray whose sum is **less than or equal to `k`**. All elements in the array are non-negative.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 0, 1, 1, 0], k = 4
Output: 5
Explanation: The subarray [1, 0, 1, 1, 0] has a sum of 3, which is <= 4, and its length is 5.
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 0
Output: 0
Explanation: No non-empty subarray has a sum less than or equal to 0.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^4`
- `0 <= k <= 10^9`
