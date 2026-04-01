# 2. Subsets II

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` that may contain **duplicates**, return **all possible unique subsets** (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 2]
Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
```

**Example 2:**
```
Input: nums = [0]
Output: [[], [0]]
```

**Example 3:**
```
Input: nums = [1, 1, 1]
Output: [[], [1], [1, 1], [1, 1, 1]]
```

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

## Notes

- Use the **Loop-based Backtracking** pattern.
- **Duplicate Suppression**: Sort the array first to group identical elements.
- In the loop, use `if (i > start && nums[i] == nums[i-1]) continue;` to skip duplicates at the same recursive level.
- Record the current subset at the **start** of each recursive call (since every node in the recursion tree is a unique subset).
