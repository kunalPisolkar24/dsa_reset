# 4. Distance to Next Greater

**Difficulty:** Easy

## Problem Statement

For each element, instead of the value of the next greater element, return the distance (number of indices) to it. If none exists, return -1.

### Example Testcases

**Example 1:**
```
Input: arr = {2, 1, 2, 4, 3}
Output: {3, 1, 1, -1, -1}
Explanation: 2 at index 0 sees 4 at index 3 (dist 3). 1 at index 1 sees 2 at index 2 (dist 1).
```

**Example 2:**
```
Input: arr = {73, 74, 75, 71, 69, 72, 76, 73}
Output: {1, 1, 4, 2, 1, 1, -1, -1}
```

**Example 3:**
```
Input: arr = {1, 1, 1}
Output: {-1, -1, -1}
```

## Constraints

- `1 <= n <= 10^5` 
- `-10^9 <= arr[i] <= 10^9`
