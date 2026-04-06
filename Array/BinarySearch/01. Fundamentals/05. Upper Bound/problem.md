# 05. Upper Bound

**Difficulty:** Easy

## Problem Statement

Given a sorted array `nums` and a `target` value, return the index of the **first element** that is **strictly greater than** `target`. This is also known as the upper bound. If all elements in the array are less than or equal to the `target`, return the length of the array (`n`).

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 4
Output: 4
Explanation: The first element strictly greater than 4 is 6 at index 4.
```

**Example 2:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 5
Output: 4
Explanation: The first element strictly greater than 5 is 6 at index 4.
```

**Example 3:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 8
Output: 6
Explanation: All elements are less than or equal to 8, return n.
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i], target <= 10^4`
- `nums` is sorted in non-decreasing order.
