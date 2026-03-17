# 14. Maximum Value Under Constraint

**Difficulty:** Medium

## Problem Statement

You are given an array of integers `nums` and an integer `budget`. Your goal is to find the **maximum integer x** such that the sum of `min(nums[i], x)` for all `i` does not exceed the `budget`.

```
sum(min(nums[i], x)) <= budget
```

This is useful in scenarios where you want to cap the values in an array while staying within a total budget.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 4, 9], budget = 10
Output: 5
Explanation: 
min(1, 5) + min(4, 5) + min(9, 5) = 1 + 4 + 5 = 10 (<= 10).
If x = 6, sum = 1 + 4 + 6 = 11 (> 10).
Maximum x is 5.
```

**Example 2:**
```
Input: nums = [10, 20, 30], budget = 25
Output: 8
Explanation: 8+8+8 = 24. 9+9+9 = 27.
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= budget <= 10^14`
