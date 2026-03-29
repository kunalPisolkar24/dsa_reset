# 7. Floor and Ceil in Sorted Array

**Difficulty:** Medium

## Problem Statement

Given a sorted array `nums` and a `target` value, return both the **floor** and the **ceil** of the `target` as a pair.

- **Floor**: The largest element in the array that is less than or equal to the `target`.
- **Ceil**: The smallest element in the array that is greater than or equal to the `target`.

If either the floor or the ceil does not exist, return `-1` for that value.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 8, 10, 10, 12, 19], target = 5
Output: Floor: 2, Ceil: 8
```

**Example 2:**
```
Input: nums = [1, 2, 8, 10, 10, 12, 19], target = 20
Output: Floor: 19, Ceil: -1
```

**Example 3:**
```
Input: nums = [1, 2, 8, 10, 10, 12, 19], target = 0
Output: Floor: -1, Ceil: 1
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- `nums` is sorted in non-decreasing order.
