# 13. Subarrays with Exactly K Odd Numbers

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **number of subarrays** that contain **exactly `k` odd numbers**.

- This is equivalent to finding the number of "nice" subarrays as defined in some competitive programming platforms.

### Examples

**Example 1:**
```
Input: nums = [1, 1, 2, 1, 1], k = 3
Output: 2
Explanation: The subarrays with exactly 3 odd numbers are:
- [1, 1, 2, 1] (at indices 0 to 3)
- [1, 2, 1, 1] (at indices 1 to 4)
```

**Example 2:**
```
Input: nums = [2, 4, 6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
