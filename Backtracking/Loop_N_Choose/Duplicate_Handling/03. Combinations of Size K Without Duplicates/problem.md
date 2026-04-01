# 3. Combinations of Size K Without Duplicates

**Difficulty:** Medium

## Problem Statement

Given an integer array `nums` that may contain **duplicates** and an integer `k`, return **all unique combinations** of size `k`.

The solution set must not contain duplicate combinations. Return the solution in any order.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 1, 2, 2, 3], k = 2
Output: [[1,1], [1,2], [1,3], [2,2], [2,3]]
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 2
Output: [[1,2], [1,3], [2,3]]
```

**Example 3:**
```
Input: nums = [1, 1, 1], k = 2
Output: [[1,1]]
```

**Example 4:**
```
Input: nums = [1, 2], k = 3
Output: []
```

## Constraints

- `1 <= nums.length <= 15`
- `-10 <= nums[i] <= 10`
- `0 <= k <= nums.length`

## Notes

- Use the **Loop-based Backtracking** pattern.
- **Duplicate Suppression**: Sort the array first to group identical elements.
- In the loop, use `if (i > start && nums[i] == nums[i-1]) continue;` to skip duplicates.
- The base case is when the current combination size reaches `k`.
- **Pruning**: If the remaining elements in the array are fewer than the elements needed to reach size `k`, return early.
