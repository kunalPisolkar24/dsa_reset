# 5. Combination Sum With Limited Frequency

**Difficulty:** Medium

## Problem Statement

Given an array of **distinct** integers `nums`, a corresponding array `freq` where `freq[i]` is the maximum number of times you can use `nums[i]`, and a `target` sum, return **all unique combinations** that sum to `target`.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 2, 3], freq = [2, 1, 2], target = 4
Output: [[1, 1, 2], [1, 3]]
Explanation: 
- 1 used twice (max freq 2), 2 used once (max freq 1). Sum = 4.
- 1 used once, 3 used once. Sum = 4.
```

**Example 2:**
```
Input: nums = [1, 2, 3, 5], freq = [2, 1, 1, 1], target = 8
Output: [[1, 2, 5], [3, 5]]
Explanation:
- 1*2 + 2*1 + 5*1 = 2+2+5 = 9 (X)
- 1*2 + 5*1 = 7 (X)
- 3+5 = 8 (✓)
- 1+2+5 = 8 (✓)
- 1+1+2+5 = 9 (X)
```

**Example 3:**
```
Input: nums = [1, 2], freq = [3, 2], target = 4
Output: [[1, 1, 1, 1], [1, 1, 2], [2, 2]]
Explanation:
- 1*4 = 4 (X, max freq 3)
- 1*2 + 2*1 = 4 (✓)
- 2*2 = 4 (✓)
```

## Constraints

- `1 <= nums.length <= 15`
- `1 <= nums[i] <= 50`
- `1 <= freq[i] <= 10`
- `1 <= target <= 100`
