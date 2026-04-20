# 15. Strength of Array

**Difficulty:** Hard

## Problem Statement

The strength of a subarray is `min(subarray) * length(subarray)`. Return the total sum of strengths of all possible subarrays.

### Example Testcases

**Example 1:**
```
Input: arr = {1, 3, 1}
Output: 12
Explanation: Strengths: [1]*1=1, [3]*1=3, [1]*1=1, [1,3] min=1 len=2 -> 2, [3,1] min=1 len=2 -> 2, [1,3,1] min=1 len=3 -> 3. Total = 1+3+1+2+2+3 = 12.
```

**Example 2:**
```
Input: arr = {5, 4}
Output: 17
```

**Example 3:**
```
Input: arr = {1, 2}
Output: 5
```

## Constraints

- `1 <= n <= 3 * 10^4` 
- `1 <= arr[i] <= 10^5`
