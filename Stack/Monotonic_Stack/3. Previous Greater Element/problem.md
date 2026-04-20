# 3. Previous Greater Element

**Difficulty:** Easy

## Problem Statement

Find the nearest element to the left of each element that is strictly greater. If no such element exists, return -1.

### Example Testcases

**Example 1:**
```
Input: arr = {4, 5, 2, 10, 8}
Output: {-1, -1, 5, -1, 10}
```

**Example 2:**
```
Input: arr = {10, 4, 5, 2}
Output: {-1, 10, 10, 5}
```

**Example 3:**
```
Input: arr = {1, 2, 3}
Output: {-1, -1, -1}
```

## Constraints

- `1 <= n <= 10^5` 
- `-10^9 <= arr[i] <= 10^9`
