# 15. Exactly K Distinct Integers

**Difficulty:** Hard

## Problem Statement

Given an integer array `nums` and an integer `k`, return the **number of subarrays** that contain **exactly `k` distinct integers**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 2, 3], k = 2
Output: 7
Explanation: Subarrays with exactly 2 distinct integers: [1, 2], [2, 1], [1, 2], [2, 1, 2], [1, 2, 1, 2], [2, 3], [1, 2, 3] — wait, [1, 2, 3] has 3 distinct. Correct subarrays: [1,2], [2,1], [1,2], [2,1,2], [1,2,1], [1,2,1,2], [2,3].
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 1
Output: 3
Explanation: Subarrays [1], [2], [3].
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= nums.length`
- `1 <= k <= nums.length`
