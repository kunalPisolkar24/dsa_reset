# 6. Longest Subarray With Sum ≤ K

**Difficulty:** Medium

## Problem Statement

Given an array of **positive integers** (which may include zero in some variations, but here assume all $nums[i] \ge 0$) `nums` and an integer `k`, return the **length of the longest contiguous subarray** whose sum is **less than or equal to `k`**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 1, 0, 1, 1, 0], k = 4
Output: 5
Explanation: 
The subarray [1, 0, 1, 1, 0] has sum 3, which is <= 4, and its length is 5.
Other subarrays like [2, 1, 0, 1] have sum 4, but length is only 4.
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 0
Output: 0
Explanation: No subarray has sum <= 0 except maybe empty ones (if nums[i]>0), but here we look for positive length.
If the only way to get sum 0 is an empty subarray, length is 0.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^4`
- `0 <= k <= 10^9`
