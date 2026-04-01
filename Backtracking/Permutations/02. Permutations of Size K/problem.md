# 2. Permutations of Size K

**Difficulty:** Medium

## Problem Statement

Given an array `nums` of **distinct** integers and an integer `k`, return **all possible permutations of size `k`**.

A permutation of size `k` is a selection of `k` elements from `nums` where the **order of selection matters**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3], k = 2
Output: [[1,2], [1,3], [2,1], [2,3], [3,1], [3,2]]
```

**Example 2:**
```
Input: nums = [1, 2, 3], k = 3
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
```

**Example 3:**
```
Input: nums = [1, 2, 3], k = 4
Output: []
```

## Constraints

- `1 <= nums.length <= 8`
- `1 <= k <= 8`
- All the integers of `nums` are **unique**.

## Notes

- Use the **Loop-based Backtracking** pattern.
- **State Tracking**: Use a `visited` array (or bitmask) to track which elements are currently in the permutation.
- **Base Case**: The recursion stops when the current permutation size reaches `k`.
- In each recursive step, loop from `0` to `n-1`. If `!visited[i]`, pick `nums[i]`, mark as `visited`, and recurse.
- Backtrack by unmarking `visited[i]` and popping from the current list.
