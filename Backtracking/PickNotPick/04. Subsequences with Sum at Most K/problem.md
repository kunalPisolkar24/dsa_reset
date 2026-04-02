# 4. Subsequences with Sum at Most K

**Difficulty:** Medium

## Problem Statement

Given an integer array `arr` of **non-negative** integers and an integer `target`, return **all non-empty subsequences of `arr`** whose sum is **less than or equal to `target`**, in any order.

A **subsequence** is a sequence derived from `arr` by deleting some (possibly zero) elements without changing the relative order of the remaining elements.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3], target = 3
Output: [[1], [2], [3], [1,2]]
Explanation: Subsequences with sum <= 3:
             [1] -> sum = 1 ✓
             [2] -> sum = 2 ✓
             [3] -> sum = 3 ✓
             [1,2] -> sum = 3 ✓
             [1,3] -> sum = 4 ✗
             [2,3] -> sum = 5 ✗
             [1,2,3] -> sum = 6 ✗
```

**Example 2:**
```
Input: arr = [1, 2, 3], target = 1
Output: [[1]]
Explanation: Only [1] has a sum <= 1. [2] and [3] already exceed the target.
```

**Example 3:**
```
Input: arr = [2, 4, 6], target = 5
Output: [[2], [4]]
Explanation: [2] -> sum = 2 ✓
             [4] -> sum = 4 ✓
             [6] -> sum = 6 ✗  (exceeds target)
             All multi-element subsequences exceed target.
```

## Constraints

- `1 <= arr.length <= 15`
- `0 <= arr[i] <= 10^4`
- `0 <= target <= 10^5`
- Output order of subsequences does not matter; elements within each subsequence must preserve their original relative order.
- The empty subsequence (sum = 0) is **not** included in the output.
