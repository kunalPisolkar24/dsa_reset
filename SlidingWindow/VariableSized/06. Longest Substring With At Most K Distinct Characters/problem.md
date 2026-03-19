# 11. Longest Substring With At Most K Distinct Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s` and an integer `k`, return **the length of the longest substring** of `s` that contains **at most `k` distinct characters**.

### Example Testcases

**Example 1:**
```
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
```

**Example 2:**
```
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
```

**Example 3:**
```
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The substring is "cbebebe" or "aaacbebebe"? No.
Let's see: [c, b, e] are 3 distinct. "cbebebe" length 7.
[a, b, c] are 3 distinct. "aabac" length 5.
```

## Constraints

- `1 <= s.length <= 5 * 10^4`
- `0 <= k <= 50`
