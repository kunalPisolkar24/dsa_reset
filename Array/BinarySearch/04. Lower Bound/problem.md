# 4. Lower Bound

**Difficulty:** Easy

## Problem Statement

Given a sorted array `nums` and a `target` value, return the index of the **first element** that is **greater than or equal to** `target`. This is also known as the lower bound. If all elements in the array are smaller than the `target`, return the length of the array (`n`).

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 4
Output: 2
Explanation: The first 4 is at index 2.
```

**Example 2:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 5
Output: 4
Explanation: The first element >= 5 is 6 at index 4.
```

**Example 3:**
```
Input: nums = [1, 2, 4, 4, 6, 8], target = 9
Output: 6
Explanation: All elements are smaller than 9, return n.
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i], target <= 10^4`
- `nums` is sorted in non-decreasing order.
