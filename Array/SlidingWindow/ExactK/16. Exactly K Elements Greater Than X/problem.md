# 16. Subarrays with Exactly K Elements Greater than X

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums`, an integer `k`, and an integer `x`, return the **number of subarrays** that contain **exactly `k` elements** that are **greater than `x`**.

### Examples

**Example 1:**
```
Input: nums = [1, 5, 2, 4, 3, 7], k = 2, x = 4
Output: 2
Explanation: The elements greater than 4 are 5 and 7.
The subarrays containing exactly two such elements are:
- [1, 5, 2, 4, 3, 7] (contains 5 and 7)
- [5, 2, 4, 3, 7] (contains 5 and 7)
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 1, x = 5
Output: 0
Explanation: There are no elements greater than 5 in the array.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
- `0 <= x <= 10^5`
