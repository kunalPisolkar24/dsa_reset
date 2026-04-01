# 2. Combination Sum (Unlimited Usage)

**Difficulty:** Medium

## Problem Statement

Given an array of **distinct** integers `candidates` and a target integer `target`, return **all unique combinations** of `candidates` where the chosen numbers sum to `target`.

You may use the same number from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

### Example Testcases

**Example 1:**
```
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
Explanation: 2+2+3 = 7. 7 = 7.
```

**Example 2:**
```
Input: candidates = [2, 3, 5], target = 8
Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
```

**Example 3:**
```
Input: candidates = [2], target = 1
Output: []
```

## Constraints

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- All elements of `candidates` are **distinct**.
- `1 <= target <= 40`

## Notes

- Use the **Loop-based Backtracking** pattern.
- **Unlimited Usage**: In the recursive call, pass the current index **`i`** as the next `start` index. This allows the recursive step to pick the same element again.
- **Pruning**: Sort the `candidates` array first. If the `currentSum + candidates[i]` exceeds `target`, you can `break` the loop because all subsequent elements are also too large.
