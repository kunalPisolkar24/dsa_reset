# 1. Binary Strings of Length N

**Difficulty:** Easy

## Problem Statement

Given a positive integer `n`, return **all binary strings of length `n`** in any order.

A binary string consists only of the characters `'0'` and `'1'`. Every possible combination of length `n` must appear exactly once in the result.

### Example Testcases

**Example 1:**
```
Input: n = 1
Output: ["0", "1"]
Explanation: There are 2^1 = 2 binary strings of length 1.
```

**Example 2:**
```
Input: n = 2
Output: ["00", "01", "10", "11"]
Explanation: There are 2^2 = 4 binary strings of length 2.
             Each character at every position is independently either '0' or '1'.
```

**Example 3:**
```
Input: n = 3
Output: ["000", "001", "010", "011", "100", "101", "110", "111"]
Explanation: There are 2^3 = 8 binary strings of length 3.
```

## Constraints

- `1 <= n <= 16`
- The answer must contain exactly `2^n` strings.
- Each string must have length exactly `n`.
- All strings must be unique.
- Output order does not matter.

## Notes

- Model this as a **pick / not-pick** recursion: at each position, independently choose `'0'` or `'1'`.
- Base case: when the current string has length `n`, add it to the result.
- Total output size = `2^n` strings.
