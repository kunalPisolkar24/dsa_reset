# 10. Longest Substring Without Repeating Characters

**Difficulty:** Medium

## Problem Statement

Given a string `s`, return the **length of the longest substring** that does not contain any repeating characters.

### Example Testcases

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with a length of 3.
```

**Example 2:**
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with a length of 1.
```

**Example 3:**
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with a length of 3.
Note that the answer must be a substring; "pwke" is a subsequence and not a substring.
```

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.
