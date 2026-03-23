# 11. Longest Substring With At Most K Distinct Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s` and an integer `k`, return the **maximum length** of a substring of `s` that contains **at most `k` distinct characters**.

### Example Testcases

**Example 1:**
```
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with a length of 3.
```

**Example 2:**
```
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with a length of 2.
```

**Example 3:**
```
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The substring is "cbebebe" which contains 'b', 'e', and 'c'.
```

## Constraints

- `1 <= s.length <= 5 * 10^4`
- `0 <= k <= 50`
