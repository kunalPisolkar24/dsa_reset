# 05. Minimum Days for Bouquets

**Difficulty:** Medium

## Problem Statement

You are given an integer array `bloomDay`, representing the day each flower will bloom. You want to make `m` bouquets. To make one bouquet, you need to use `k` **adjacent** flowers from the garden.

A flower can be used in at most one bouquet.

Return the **minimum number of days** you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets, return `-1`.

### Example Testcases

**Example 1:**
```
Input: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 1
Output: 3
Explanation: 
At day 1: [B, _, _, _, _] (1 bouquet)
At day 2: [B, _, _, _, B] (2 bouquets)
At day 3: [B, _, B, _, B] (3 bouquets)
```

**Example 2:**
```
Input: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 2
Output: -1
Explanation: Need 3*2 = 6 flowers. Only 5 available.
```

**Example 3:**
```
Input: bloomDay = [7, 7, 7, 7, 12, 7, 7], m = 2, k = 3
Output: 12
```

## Constraints

- `bloomDay.length == n`
- `1 <= n <= 10^5`
- `1 <= bloomDay[i] <= 10^9`
- `1 <= m <= 10^6`
- `1 <= k <= n`
