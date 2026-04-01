# 3. Generate All Subsets (Power Set)

**Difficulty:** Medium

## Problem Statement

Given an array `arr` of integers, return **all possible subsets** (the power set).

A subset is a selection of elements from the original array. The power set contains $2^n$ subsets, including the empty set and the array itself.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
Explanation: 2^3 = 8 subsets.
```

**Example 2:**
```
Input: arr = [1, 2]
Output: [[], [1], [2], [1,2]]
```

**Example 3:**
```
Input: arr = [1]
Output: [[], [1]]
```

## Constraints

- `1 <= arr.length <= 15`
- `-10 <= arr[i] <= 10`
- All integers in `arr` are **unique** for this problem.

## Notes

- Use the **Loop-based Backtracking** pattern.
- In this pattern, every node in the recursion tree represents a valid subset.
- Append the current combination to the result at the **start** of each recursive call.
- The loop handles the inclusion of each subsequent element.
