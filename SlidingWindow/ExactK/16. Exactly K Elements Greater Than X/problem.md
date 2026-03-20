# 16. Exactly K Elements Greater Than X

**Difficulty:** Medium

## Problem Statement

Given an array `nums`, an integer `k`, and an integer `x`, return the **number of subarrays** that contain **exactly `k` elements greater than `x`**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 5, 2, 4, 3, 7], k = 2, x = 4
Output: 2
Explanation: Subarrays with exactly 2 elements > 4: [5, 2, 4, 3, 7] — has 5 and 7 (2 elements). [4, 3, 7] — 7 is > 4 (only 1 element)... actually [5, 2, 4, 3, 7] has 5, 7 > 4 so 2 elements. Also [1, 5, 2, 4, 3, 7] has 5, 7 > 4 so 2 elements. Count = 2.
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 1, x = 5
Output: 0
Explanation: No element is greater than 5.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= nums.length`
- `0 <= x <= 10^5`
