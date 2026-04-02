# 5. Combinations Whose Sum = Target

**Difficulty:** Medium

## Problem Statement

Given an array `arr` and an integer `target`, return **all unique combinations** of elements from the array whose sum is **exactly equal** to `target`.

Each element in the array may only be used **once** in each combination. The input array may contain **duplicate elements**, but the final list of combinations must not contain duplicate combinations.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3, 4], target = 5
Output: [[1,4], [2,3]]
```

**Example 2:**
```
Input: arr = [1, 1, 2], target = 2
Output: [[1,1], [2]]
Explanation: We can pick both '1's to get 2, or the single '2'.
```

**Example 3:**
```
Input: arr = [2, 4, 6], target = 1
Output: []
```

## Constraints

- `1 <= arr.length <= 30`
- `1 <= arr[i] <= 50`
- `1 <= target <= 100`
