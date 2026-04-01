# 1. Combination Sum II

**Difficulty:** Medium

## Problem Statement

Given an array of candidate integers `candidates` and a target integer `target`, find **all unique combinations** where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

### Example Testcases

**Example 1:**
```
Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
Output: 
[
  [1, 1, 6],
  [1, 2, 5],
  [1, 7],
  [2, 6]
]
```

**Example 2:**
```
Input: candidates = [2, 5, 2, 1, 2], target = 5
Output: 
[
  [1, 2, 2],
  [5]
]
```

**Example 3:**
```
Input: candidates = [1, 1, 1, 1], target = 3
Output: [[1, 1, 1]]
```

## Constraints

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Notes

- Use the **Loop-based Backtracking** pattern.
- **Duplicate Suppression**: To avoid using the same value multiple times at the same level of recursion, **sort** the input array first.
- In the loop, use `if (i > start && candidates[i] == candidates[i-1]) continue;` to skip duplicates.
- **Pruning**: Since all candidates are positive, if `currentSum + candidates[i] > target`, we can `break` the loop early.
