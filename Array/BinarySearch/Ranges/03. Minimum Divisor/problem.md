# 3. Minimum Divisor

**Difficulty:** Easy

## Problem Statement

Given an array of integers `nums` and an integer `limit`, find the **smallest positive integer divisor d** such that:

```
sum(ceil(nums[i] / d)) <= limit
```

Each element `nums[i]` is divided by `d`, and the result is rounded **up** to the nearest integer. The sum of these results must be less than or equal to `limit`.

### Example Testcases

**Example 1:**
```
Input: nums = [10, 20, 30], limit = 6
Output: 10
Explanation: 
If d = 10, sum is ceil(10/10) + ceil(20/10) + ceil(30/10) = 1 + 2 + 3 = 6 (<= 6).
If d = 9, sum is ceil(10/9) + ceil(20/9) + ceil(30/9) = 2 + 3 + 4 = 9 (not <= 6).
Thus, 10 is the smallest valid divisor.
```

**Example 2:**
```
Input: nums = [1, 2, 5, 9], limit = 6
Output: 5
Explanation: 
If d = 5, sum is ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5) = 1 + 1 + 1 + 2 = 5 (<= 6).
```

## Constraints

- `1 <= nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 10^6`
- `nums.length <= limit <= 10^6`
