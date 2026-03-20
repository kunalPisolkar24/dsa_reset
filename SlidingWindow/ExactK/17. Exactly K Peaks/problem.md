# 17. Subarrays with Exactly K Peaks

**Difficulty:** Hard

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **number of subarrays** that contain **exactly `k` peaks**.

A **peak** in a subarray `nums[l..r]` is an element `nums[i]` such that:
- `l < i < r`
- `nums[i] > nums[i-1]`
- `nums[i] > nums[i+1]`

**Note:** Elements at the boundaries of a subarray (`nums[l]` and `nums[r]`) can never be peaks of that subarray.

### Examples

**Example 1:**
```
Input: nums = [1, 3, 2, 4, 1, 5, 3, 4, 1], k = 2
Output: 12
Explanation: There are 12 subarrays that contain exactly 2 peaks according to the definition above.
```

**Example 2:**
```
Input: nums = [1, 2, 3, 1], k = 1
Output: 6
Explanation: The subarrays with exactly 1 peak are:
- [1, 2, 3, 1] (Peak 3 at index 2)
- [2, 3, 1] (Peak 3 at index 2)
- [1, 2, 3] (No peak, boundaries 1 and 3)
- ... and others. There are 6 such subarrays.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
