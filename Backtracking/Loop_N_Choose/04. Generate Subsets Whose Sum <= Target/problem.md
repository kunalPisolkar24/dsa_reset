# 4. Generate Subsets Whose Sum ≤ Target

**Difficulty:** Medium

## Problem Statement

Given an array `arr` of **non-negative** integers and an integer `target`, return **all subsets** whose sum is **less than or equal to `target`**.

The empty subset (sum = 0) should be included in the output.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3, 4], target = 4
Output: [[], [1], [2], [3], [4], [1,2], [1,3]]
Explanation: 
- [1,4] sum = 5 (too high)
- [2,3] sum = 5 (too high)
- [1,2,3] sum = 6 (too high)
```

**Example 2:**
```
Input: arr = [2, 3, 5], target = 6
Output: [[], [2], [3], [5], [2,3]]
```

**Example 3:**
```
Input: arr = [1, 2, 3], target = 1
Output: [[], [1]]
```

## Constraints

- `1 <= arr.length <= 15`
- `0 <= arr[i] <= 100`
- `0 <= target <= 1000`

## Notes

- Use the **Loop-based Backtracking** pattern.
- Record the current subset at the start of each recursive call.
- **Pruning**: Since all elements are non-negative, if the `currentSum` already exceeds `target`, you can stop exploring that branch immediately.
- Pass the `currentSum` through the recursive calls to avoid recomputing it.
