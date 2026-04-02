# 4. Unique Subsets of Size K with Sum ≤ Target

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` that may contain **duplicates**, and integers `k` and `target`, return **all unique subsets** of exactly size `k` such that their sum is **less than or equal to `target`**.

The solution set must not contain duplicate combinations. Return the solution in any order.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 2, 3], k = 2, target = 4
Output: [[1, 2], [1, 3], [2, 2]]
Explanation: 
- [1, 2] sum = 3 ≤ 4 ✓ (The two 2's at indices 1 and 2 give the same unique subset [1, 2])
- [1, 3] sum = 4 ≤ 4 ✓
- [2, 2] sum = 4 ≤ 4 ✓
- [2, 3] sum = 5 > 4 ✗
```

**Example 2:**
```
Input: nums = [1, 2, 3, 4], k = 2, target = 5
Output: [[1, 2], [1, 3], [1, 4], [2, 3]]
```

**Example 3:**
```
Input: nums = [1, 1, 1], k = 3, target = 4
Output: [[1, 1, 1]]
```

## Constraints

- `1 <= nums.length <= 15`
- `0 <= nums[i] <= 50`
- `1 <= k <= nums.length`
- `1 <= target <= 100`
