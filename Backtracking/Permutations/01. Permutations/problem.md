# 1. Permutations

**Difficulty:** Medium

## Problem Statement

Given an array `nums` of **distinct** integers, return **all possible permutations**.

Order matters in permutations. You can return the result in **any order**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
```

**Example 2:**
```
Input: nums = [0, 1]
Output: [[0,1], [1,0]]
```

**Example 3:**
```
Input: nums = [1]
Output: [[1]]
```

## Constraints

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

## Notes

- Use the **Loop-based Backtracking** pattern.
- **State Tracking**: Since permutations allow picking any element at any position (as long as it hasn't been used yet), you need a `visited` array (or a bitmask) to track which elements are currently in the permutation.
- In each recursive step, loop from `0` to `n-1`. If `!visited[i]`, pick `nums[i]`, mark as `visited`, and recurse.
- Remember to **backtrack**: Unmark `visited[i]` and remove from the current list after the recursive call.
