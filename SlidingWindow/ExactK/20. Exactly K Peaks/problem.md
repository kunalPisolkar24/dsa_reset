# 20. Exactly K Peaks

**Difficulty:** Hard

## Problem Statement

Given an array `nums` and an integer `k`, return the **number of subarrays** that contain **exactly `k` peaks**.

A **peak** is an element at index `i` (within the subarray) such that `nums[i] > nums[i-1]` and `nums[i] > nums[i+1]`, where `i` is not the first or last index of the subarray. An element at the boundary of a subarray cannot be a peak.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 3, 2, 4, 1, 5, 3, 4, 1], k = 2
Output: 12
Explanation: There are 12 subarrays that contain exactly 2 peaks.
```

**Example 2:**
```
Input: nums = [1, 2, 3, 1], k = 1
Output: 6
Explanation: There are 6 subarrays that contain exactly 1 peak.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
