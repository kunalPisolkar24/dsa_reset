# 3. Subsequences of Length K

**Difficulty:** Medium

## Problem Statement

Given an integer array `arr` of **distinct** elements and an integer `k`, return **all subsequences of `arr` that have exactly `k` elements**, in any order.

A **subsequence** is a sequence derived from `arr` by deleting some (possibly zero) elements without changing the relative order of the remaining elements.

### Example Testcases

**Example 1:**
```
Input: arr = [1, 2, 3], k = 2
Output: [[1,2], [1,3], [2,3]]
Explanation: C(3,2) = 3 subsequences of length 2 exist.
```

**Example 2:**
```
Input: arr = [1, 2, 3, 4], k = 2
Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
Explanation: C(4,2) = 6 subsequences of length 2 exist.
```

**Example 3:**
```
Input: arr = [1, 2, 3, 4], k = 1
Output: [[1], [2], [3], [4]]
Explanation: C(4,1) = 4 subsequences of length 1, each is a single element.
```

## Constraints

- `1 <= arr.length <= 15`
- `0 <= k <= arr.length`
- `-10^4 <= arr[i] <= 10^4`
- All elements in `arr` are **distinct**.
- Output order of subsequences does not matter; the elements within each subsequence must preserve their original relative order.
