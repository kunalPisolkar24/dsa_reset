# 17. Exactly K Zeros

**Difficulty:** Medium

## Problem Statement

Given a binary array `nums` (containing only 0s and 1s) and an integer `k`, return the **number of subarrays** that contain **exactly `k` zeros**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 0, 1, 0, 1], k = 2
Output: 4
Explanation: Subarrays with exactly 2 zeros: [1, 0, 1, 0], [0, 1, 0], [0, 1, 0, 1], [1, 0, 1, 0, 1].
```

**Example 2:**
```
Input: nums = [0, 0, 0, 0], k = 1
Output: 4
Explanation: Subarrays with exactly 1 zero: [0] (at indices 0, 1, 2, 3).
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`
