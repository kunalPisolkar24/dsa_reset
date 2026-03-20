# 18. Substrings with Exactly K Bad Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s`, a list of "bad" characters `bad`, and an integer `k`, return the **number of substrings** of `s` that contain **exactly `k` bad characters**.

A character is considered **bad** if it is present in the provided `bad` list.

### Examples

**Example 1:**
```
Input: s = "abcde", bad = ['b', 'd'], k = 2
Output: 4
Explanation: The substrings with exactly 2 bad characters ('b' and 'd') are:
- "abcd" (contains 'b' and 'd')
- "abcde" (contains 'b' and 'd')
- "bcd" (contains 'b' and 'd')
- "bcde" (contains 'b' and 'd')
```

**Example 2:**
```
Input: s = "aaa", bad = ['b'], k = 1
Output: 0
Explanation: The string "aaa" contains no 'b', so no substring can have exactly 1 bad character.
```

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists of lowercase English letters only.
- `0 <= k <= s.length`
