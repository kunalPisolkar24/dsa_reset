# 14. Subarrays with Exactly K Zeros

**Difficulty:** Medium

## Problem Statement

Given a binary array `nums` (containing only `0`s and `1`s) and an integer `k`, return the **number of subarrays** that contain **exactly `k` zeros**.

### Examples

**Example 1:**
```
Input: nums = [1, 0, 1, 0, 1], k = 2
Output: 4
Explanation: The subarrays with exactly 2 zeros are:
- [1, 0, 1, 0] (indices 0 to 3)
- [0, 1, 0] (indices 1 to 3)
- [0, 1, 0, 1] (indices 1 to 4)
- [1, 0, 1, 0, 1] (indices 0 to 4)
```

**Example 2:**
```
Input: nums = [0, 0, 0, 0], k = 1
Output: 4
Explanation: The subarrays with exactly 1 zero are: [0], [0], [0], [0] (each single zero element).
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`
