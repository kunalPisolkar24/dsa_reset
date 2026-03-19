# 7. Longest Subarray With At Most K Zeros

**Difficulty:** Medium

## Problem Statement

Given a binary array `nums` (containing only 0s and 1s) and an integer `k`, return the **maximum length of a contiguous subarray** that contains at most `k` zeros.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
Output: 6
Explanation: 
The subarray [0, 0, 1, 1, 1, 1] is not valid because it has 2 zeros, wait it is valid.
[0, 0, 1, 1, 1, 1] -> 2 zeros, length 6.
[1, 1, 1, 1, 0] -> 1 zero, length 5.
Wait, let's check:
[1, 1, 1, 0, 0] -> 2 zeros, length 5.
[0, 0, 1, 1, 1, 1] -> 2 zeros, length 6.
Maximum length is 6.
```

**Example 2:**
```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [1,1,1,0,1,1,0,0,0,1,1,1,1] contains too many zeros.
Actually this is the same as LeetCode "Max Consecutive Ones III".
```

## Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`
