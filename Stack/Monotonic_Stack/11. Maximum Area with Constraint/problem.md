# 11. Maximum Area with Constraint

**Difficulty:** Medium

## Problem Statement

Find the largest rectangle area in a histogram that **must include** the bar at index `k`. This requires identifying the left and right boundaries for the bar at `k`.

### Example Testcases

**Example 1:**
```
Input: heights = {2, 1, 5, 6, 2, 3}, k = 2
Output: 10
```

**Example 2:**
```
Input: heights = {10, 2, 10}, k = 1
Output: 6
```

**Example 3:**
```
Input: heights = {5, 5, 5}, k = 1
Output: 15
```

## Constraints

- `1 <= heights.length <= 10^5` 
- `0 <= heights[i] <= 10^4` 
- `0 <= k < heights.length`
