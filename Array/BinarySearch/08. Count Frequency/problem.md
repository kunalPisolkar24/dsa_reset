# 8. Count Frequency Using Binary Search

**Difficulty:** Medium

## Problem Statement

Given a sorted array `nums` (which may contain duplicates) and a `target` value, return the number of times `target` appears in the array. 

**Requirement:** You must use binary search to find the first and last occurrence of the target to compute the frequency. Do **not** use a linear scan.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 2, 2, 3], target = 2
Output: 3
Explanation: 2 appears 3 times (at indices 1, 2, and 3)
```

**Example 2:**
```
Input: nums = [1, 1, 2, 3, 3, 4, 4, 4, 4, 5], target = 4
Output: 4
```

**Example 3:**
```
Input: nums = [1, 2, 3], target = 4
Output: 0
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- `nums` is sorted in non-decreasing order.
