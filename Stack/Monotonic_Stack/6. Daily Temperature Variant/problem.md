# 6. Daily Temperature Variant

**Difficulty:** Medium

## Problem Statement

Given daily temperatures, return an array of distances to the next day that is at least **3 degrees warmer**. If no such day exists, return -1.

### Example Testcases

**Example 1:**
```
Input: temps = {30, 32, 33, 31, 36}
Output: {4, 3, 2, 1, -1}
Explanation: 30 needs 33+, first is 36 at dist 4. 32 needs 35+, first is 36 at dist 3.
```

**Example 2:**
```
Input: temps = {10, 20, 30}
Output: {1, 1, -1}
```

**Example 3:**
```
Input: temps = {30, 30, 30}
Output: {-1, -1, -1}
```

## Constraints

- `1 <= temps.length <= 10^5` 
- `30 <= temps[i] <= 100`
