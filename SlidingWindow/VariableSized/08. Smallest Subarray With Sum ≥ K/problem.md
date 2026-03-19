# 8. Smallest Subarray With Sum ≥ K

**Difficulty:** Medium

## Problem Statement

Given an array of positive integers `nums` and a positive integer `k`, return the **minimum length** of a contiguous subarray whose sum is **greater than or equal to `k`**. If no such subarray exists, return `-1`.

### Example Testcases

**Example 1:**
```
Input: nums = [2, 3, 1, 2, 4, 3], k = 7
Output: 2
Explanation: The subarray [4, 3] has the minimal length.
```

**Example 2:**
```
Input: nums = [1, 4, 4], k = 4
Output: 1
Explanation: The subarray [4] has length 1.
```

**Example 3:**
```
Input: nums = [1, 1, 1, 1, 1, 1, 1, 1], k = 11
Output: -1
Explanation: No subarray sum reaches 11.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `1 <= k <= 10^9`
