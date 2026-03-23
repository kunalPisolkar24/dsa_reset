# 12. Substrings with Exactly K Distinct Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s` and an integer `k`, return the **number of substrings** of `s` that contain **exactly `k` distinct characters**.

### Examples

**Example 1:**
```
Input: s = "pqpqs", k = 2
Output: 7
Explanation: The substrings with exactly 2 distinct characters are: "pq", "qp", "pq", "pqpq", "qpq", "qs", "pqs".
```

**Example 2:**
```
Input: s = "aaaa", k = 1
Output: 10
Explanation: All substrings of "aaaa" contain exactly 1 distinct character. There are 10 such substrings (4 of length 1, 3 of length 2, 2 of length 3, and 1 of length 4).
```

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists of lowercase English letters only.
- `1 <= k <= 26`
