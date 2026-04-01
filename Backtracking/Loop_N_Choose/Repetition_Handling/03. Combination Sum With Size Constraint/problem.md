# 3. Combination Sum With Size Constraint

**Difficulty:** Medium

## Problem Statement

Given an array of **distinct** integers `nums`, a `target` sum, and an integer `k`, return **all combinations of exactly `k` elements** that sum to `target`.

You may use each number in `nums` an **unlimited number of times**.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3], target = 4, k = 3
Output: [[1, 1, 2]]
Explanation: 1+1+2 = 4 (size 3).
```

**Example 2:**
```
Input: nums = [1, 2, 3], target = 4, k = 2
Output: [[1, 3], [2, 2]]
```

**Example 3:**
```
Input: nums = [2, 3, 6], target = 6, k = 2
Output: [[3, 3]]
```

## Constraints

- `1 <= nums.length <= 20`
- `1 <= nums[i] <= 50`
- `1 <= target <= 100`
- `1 <= k <= 20`

## Notes

- Use the **Loop-based Backtracking** pattern.
- **Unlimited Usage**: In the recursive call, pass the current index **`i`** as the next `start` index.
- **Base Cases**:
    1. If `currentCombination.size() == k` and `sum == target`, record the result.
    2. If `currentCombination.size() == k` but `sum != target`, stop.
    3. If `currentSum > target`, stop (if elements are positive).
- **Pruning**: Sort `nums`. If `sum + nums[i] > target`, break the loop. If `(k - currentSize) * nums[0] + currentSum > target`, we can also prune (though simple sum pruning is usually enough).
