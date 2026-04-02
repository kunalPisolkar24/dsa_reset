# 1. Generate All Pairs from Array

**Difficulty:** Easy

## Problem Statement

Given an array `arr` of size `n`, return **all unique pairs** `(arr[i], arr[j])` such that `i < j`.

The order of pairs in the output does not matter, but each pair should contain elements in the same relative order as they appear in the original array.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3, 4]
Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
Explanation: All possible pairs where the first element appeared before the second.
```

**Example 2:**
```
Input: arr = [1, 2, 3]
Output: [[1,2], [1,3], [2,3]]
```

**Example 3:**
```
Input: arr = [1, 1]
Output: [[1,1]]
Explanation: Even if elements are the same value, they are distinct by index.
```

## Constraints

- `2 <= arr.length <= 50`
- `-10^4 <= arr[i] <= 10^4`
- The output will contain exactly `n * (n - 1) / 2` pairs.
