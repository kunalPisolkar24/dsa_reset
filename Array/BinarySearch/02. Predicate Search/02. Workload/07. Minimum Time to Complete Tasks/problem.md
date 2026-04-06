# 07. Minimum Time to Complete Tasks

**Difficulty:** Medium

## Problem Statement

There are `n` workers where each worker takes `time[i]` minutes to complete one task. Multiple workers can work in parallel, and each worker can work on multiple tasks sequentially.

Given an array `time` and an integer `k`, find the **minimum time T** (in minutes) required to complete at least `k` tasks in total.

### Example Testcases

**Example 1:**
```
Input: time = [2, 3], k = 5
Output: 6
Explanation: 
At T = 6:
- Worker 1 (time=2) completes floor(6/2) = 3 tasks.
- Worker 2 (time=3) completes floor(6/3) = 2 tasks.
Total tasks = 3 + 2 = 5 (>= 5).
```

**Example 2:**
```
Input: time = [1, 1, 1], k = 10
Output: 4
Explanation: At T = 3, tasks = 3+3+3 = 9. At T = 4, tasks = 4+4+4 = 12.
```

## Constraints

- `1 <= time.length <= 10^5`
- `1 <= time[i] <= 10^9`
- `1 <= k <= 10^9`
