# 9. Painter Partition

**Difficulty:** Medium

## Problem Statement

Given an array `boards` where `boards[i]` is the length of the $i^{th}$ board. There are `k` painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

The goal is to paint all boards such that:
1. Each painter paints a **contiguous** section of boards.
2. The **total time** taken to paint all boards is minimized (i.e., minimize the maximum length assigned to any one painter).

Return the **minimum time** required to complete the task.

### Example Testcases

**Example 1:**
```
Input: boards = [1, 10], k = 2
Output: 10
Explanation: 
Painter 1 paints boards[0] (1 unit).
Painter 2 paints boards[1] (10 units).
Total time = max(1, 10) = 10.
```

**Example 2:**
```
Input: boards = [10, 20, 30, 40], k = 2
Output: 60
Explanation: 
The optimal partition is [10, 20, 30] and [40].
Maximum units painted by a painter = 60.
```

**Example 3:**
```
Input: boards = [5, 5, 5, 5], k = 2
Output: 10
Explanation: 
Painter 1 paints [5, 5], Painter 2 paints [5, 5].
Maximum units painted = 10.
```


## Constraints

- `1 <= boards.length <= 10^5`
- `1 <= boards[i] <= 10^9`
- `1 <= k <= boards.length`
