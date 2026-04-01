# 2. All Subsequences of a String

**Difficulty:** Easy

## Problem Statement

Given a string `s`, return **all possible subsequences** of `s` including the empty string `""`.

A **subsequence** is a string derived from `s` by deleting some (possibly zero or all) characters without changing the relative order of the remaining characters.

### Example Testcases

**Example 1:**
```
Input: s = "a"
Output: ["", "a"]
Explanation: There are 2^1 = 2 subsequences: the empty string and "a" itself.
```

**Example 2:**
```
Input: s = "ab"
Output: ["", "a", "b", "ab"]
Explanation: There are 2^2 = 4 subsequences.
             We can choose to include or exclude each character independently.
```

**Example 3:**
```
Input: s = "abc"
Output: ["", "a", "b", "c", "ab", "ac", "bc", "abc"]
Explanation: There are 2^3 = 8 subsequences. For each character we either
             pick it (maintaining order) or skip it.
```

## Constraints

- `1 <= s.length <= 15`
- `s` consists of only lowercase English letters.
- The answer must contain exactly `2^s.length` strings (all characters in `s` are **distinct**).
- Output order does not matter.

## Notes

- At each index `i`, decide: **include** `s[i]` in the current subsequence, or **skip** it.
- Recurse on index `i + 1` with the updated (or unchanged) current string.
- Base case: when index equals `s.length()`, record the current subsequence.
- Total output size = `2^n` subsequences.
