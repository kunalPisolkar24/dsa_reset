# 2. Generate All Combinations of Size K

**Difficulty:** Medium

## Problem Statement

Given an array `arr` and an integer `k`, return **all possible combinations of size `k`** from the array.

A combination is a selection of elements where the order does not matter. However, the elements in each combination should appear in the same relative order as they do in the input array.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3, 4], k = 2
Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
Explanation: Total = C(4, 2) = 6 combinations.
```

**Example 2:**
```
Input: arr = [1, 2, 3, 4], k = 3
Output: [[1,2,3], [1,2,4], [1,3,4], [2,3,4]]
```

**Example 3:**
```
Input: arr = [1, 2, 3], k = 1
Output: [[1], [2], [3]]
```

**Example 4:**
```
Input: arr = [1, 2, 3], k = 0
Output: [[]]
```

## Constraints

- `1 <= arr.length <= 20`
- `0 <= k <= arr.length`
- All elements in `arr` are integers.
