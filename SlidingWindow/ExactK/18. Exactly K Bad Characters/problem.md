# 18. Exactly K Bad Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s`, a vector of bad characters `bad`, and an integer `k`, return the **number of substrings** that contain **exactly `k` bad characters**.

A bad character is any character present in the `bad` list.

### Example Testcases

**Example 1:**
```
Input: s = "abcde", bad = ['b', 'd'], k = 2
Output: 4
Explanation: Substrings with exactly 2 bad characters ('b' and 'd'): "abcd", "abcde", "bcd", "bcde".
```

**Example 2:**
```
Input: s = "aaa", bad = ['b'], k = 1
Output: 0
Explanation: No bad characters exist in the string.
```

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists of lowercase English letters only.
- `0 <= k <= s.length`
