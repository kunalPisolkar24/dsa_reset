# 8. Next Greater Frequency

**Difficulty:** Medium

## Problem Statement

Given an array, for each element find the first element to its right that has a **strictly higher frequency** in the entire array. If none exists, return -1.

### Example Testcases

**Example 1:**
```
Input: arr = {1, 1, 2, 3, 4, 2, 1}
Output: {-1, -1, 1, 2, 2, 1, -1}
Explanation: freq(1)=3, freq(2)=2, freq(3)=1, freq(4)=1. For 2 at index 2, next element with freq > 2 is 1 at index 6.
```

**Example 2:**
```
Input: arr = {1, 2, 1, 2, 1, 2}
Output: {-1, -1, -1, -1, -1, -1}
```

**Example 3:**
```
Input: arr = {4, 4, 4, 3, 2, 1}
Output: {-1, -1, -1, -1, -1, -1}
```

## Constraints

- `1 <= n <= 10^5` 
- `-10^9 <= arr[i] <= 10^9`
