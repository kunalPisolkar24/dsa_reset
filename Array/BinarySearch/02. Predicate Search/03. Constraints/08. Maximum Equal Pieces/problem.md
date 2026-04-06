# 08. Maximum Equal Pieces

**Difficulty:** Medium

## Problem Statement

You have several ropes with lengths given in the array `nums`. You want to cut these ropes into equal pieces. Your goal is to find the **maximum possible length L** of each piece such that you can obtain at least `k` pieces in total.

Each piece must be cut from a single rope.

### Example Testcases

**Example 1:**
```
Input: nums = [8, 5, 8], k = 5
Output: 4
Explanation: 
If L = 4, pieces: floor(8/4) + floor(5/4) + floor(8/4) = 2 + 1 + 2 = 5 pieces (>= 5).
If L = 5, pieces: floor(8/5) + floor(5/5) + floor(8/5) = 1 + 1 + 1 = 3 pieces (< 5).
Maximum length L is 4.
```

**Example 2:**
```
Input: nums = [1, 1, 1], k = 4
Output: 0
Explanation: Cannot even get 4 pieces of length 1.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`
