# 12. Exactly K Types Segment

**Difficulty:** Medium

## Problem Statement

Given a string `s` and an integer `k`, return the **number of substrings** that contain **exactly `k` distinct characters**.

### Example Testcases

**Example 1:**
```
Input: s = "pqpqs", k = 2
Output: 7
Explanation: Substrings with exactly 2 distinct chars: "pq", "qp", "pq", "pqpq", "qpq", "qs", "pqs".
```

**Example 2:**
```
Input: s = "aaaa", k = 1
Output: 10
Explanation: All 10 substrings of "aaaa" contain exactly 1 distinct character.
```

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists of lowercase English letters only.
- `1 <= k <= 26`
