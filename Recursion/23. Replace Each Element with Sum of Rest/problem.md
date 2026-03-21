# 23. Replace Each Element with Sum of Rest

**Difficulty:** Medium

## Problem Statement

Given an array of `N` integers, replace every element with the sum of all other elements using **recursion**. Do not use any loops.

*Hint: First compute the total sum of the array recursively. Then update each element iteratively via recursion: `new[i] = totalSum - arr[i]`*.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3, 4]
Output: [9, 8, 7, 6]
```

## Constraints

- `1 <= N <= 10^4`
- `-10^4 <= arr[i] <= 10^4`
