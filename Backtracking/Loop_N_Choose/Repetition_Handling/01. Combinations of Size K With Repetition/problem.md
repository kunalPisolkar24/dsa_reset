# 1. Combinations of Size K With Repetition

**Difficulty:** Medium

## Problem Statement

Given an array of **distinct** integers `nums` and an integer `k`, return **all possible combinations of size `k`**.

You can use the same element from `nums` **multiple times** in a single combination. The order of elements within a combination does not matter, but your output should not contain duplicate combinations.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3], k = 2
Output: [[1,1], [1,2], [1,3], [2,2], [2,3], [3,3]]
Explanation: 6 unique combinations of size 2 with replacement.
```

**Example 2:**
```
Input: nums = [1, 2], k = 3
Output: [[1,1,1], [1,1,2], [1,2,2], [2,2,2]]
```

**Example 3:**
```
Input: nums = [3], k = 2
Output: [[3,3]]
```

## Constraints

- `1 <= nums.length <= 15`
- `1 <= nums[i] <= 50`
- `0 <= k <= 10`
