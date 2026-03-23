# 5. Insert Position (True Lower Bound)

**Difficulty:** Easy

## Problem Statement

Given a strictly increasing sorted array `nums` and a `target` value, return the index where the `target` should be inserted. 

Specifically, return the first index `i` such that `nums[i] >= target`. If all elements are smaller than `target`, return the length of the array (`n`).

### Example Testcases

**Example 1:**
```
Input: nums = [1, 3, 5, 6], target = 5
Output: 2
```

**Example 2:**
```
Input: nums = [1, 3, 5, 6], target = 2
Output: 1
```

**Example 3:**
```
Input: nums = [1, 3, 5, 6], target = 7
Output: 4
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- `nums` is a strictly increasing sorted array.
