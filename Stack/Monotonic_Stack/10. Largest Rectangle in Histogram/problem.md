# 10. Largest Rectangle in Histogram

**Difficulty:** Medium

## Problem Statement

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

### Example Testcases

**Example 1:**
```
Input: heights = {2, 1, 5, 6, 2, 3}
Output: 10
Explanation: The largest rectangle is formed by bars at index 2 and 3 with height 5 and width 2.
```

**Example 2:**
```
Input: heights = {2, 4}
Output: 4
```

**Example 3:**
```
Input: heights = {1, 1, 1, 1}
Output: 4
```

## Constraints

- `1 <= heights.length <= 10^5` 
- `0 <= heights[i] <= 10^4`
