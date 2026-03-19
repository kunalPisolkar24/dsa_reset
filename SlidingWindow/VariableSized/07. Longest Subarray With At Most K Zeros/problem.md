# 7. Longest Subarray With At Most K Zeros

**Difficulty:** Medium

## Problem Statement

Given a binary array `nums` (containing only 0s and 1s) and an integer `k`, return the **maximum length** of a contiguous subarray that contains at most `k` zeros. This is equivalent to finding the longest subarray you can obtain after flipping at most `k` zeros to ones.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
Output: 6
Explanation: The subarray [0, 0, 1, 1, 1, 1] (Indices 4 to 9) contains 2 zeros and has length 6.
```

**Example 2:**
```
Input: nums = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], k = 3
Output: 10
Explanation: The subarray [1, 1, 0, 0, 1, 1, 1, 0, 1, 1] (Indices 2 to 11) contains exactly 3 zeros and has length 10.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`
