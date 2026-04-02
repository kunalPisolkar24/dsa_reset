# 4. Combination Sum With Duplicate Candidates

**Difficulty:** Medium

## Problem Statement

Given an array of integers `candidates` (which may contain **duplicates**) and a target integer `target`, return **all unique combinations** where the numbers sum to `target`.

You may use each unique number from `candidates` an **unlimited number of times**.

### Example Testcases

**Example 1:**
```
Input: candidates = [2, 3, 2], target = 7
Output: [[2, 2, 3]]
Explanation: Even though 2 appears twice, using '2' twice and '3' once gives 7.
```

**Example 2:**
```
Input: candidates = [2, 3, 3, 5], target = 8
Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
```

**Example 3:**
```
Input: candidates = [1, 1, 2], target = 4
Output: [[1, 1, 1, 1], [1, 1, 2], [2, 2]]
```

## Constraints

- `1 <= candidates.length <= 30`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 100`
