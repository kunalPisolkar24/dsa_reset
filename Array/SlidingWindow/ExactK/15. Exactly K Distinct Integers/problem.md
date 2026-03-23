# 15. Subarrays with K Distinct Integers

**Difficulty:** Hard

## Problem Statement

Given an integer array `nums` and an integer `k`, return the *number of **good subarrays*** of `nums`.

A **good subarray** is a subarray that contains exactly `k` different integers.

- For example, `[1, 2, 3, 1, 2]` has `3` different integers: `1`, `2`, and `3`.

### Examples

**Example 1:**
```
Input: nums = [1, 2, 1, 2, 3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 1
Output: 3
Explanation: Subarrays formed with exactly 1 different integer: [1], [2], [3].
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= nums.length`
- `1 <= k <= nums.length`
