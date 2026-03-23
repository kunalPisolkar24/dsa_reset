# 1. Basic Existence Search

**Difficulty:** Easy

## Problem Statement

Given a sorted array of integers `nums`, write a function to search for a `target` value. If the `target` exists, then return its index; otherwise, return `-1`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example Testcases

**Example 1:**
```
Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**
```
Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- All integers in `nums` are **unique**.
- `nums` is sorted in ascending order.
