# 3. Sort Strings by Length

**Difficulty:** Easy

## Problem Statement

Given an array of strings `arr`, sort them according to the following rules:

1.  First, sort by the **length** of the strings in **ascending order**.
2.  If two strings have the same length, sort them **lexicographically** (alphabetical order).

### Example Testcases

**Example 1:**
```
Input: arr = ["apple", "kiwi", "banana", "fig"]
Output: ["fig", "kiwi", "apple", "banana"]
Explanation:
- "fig" (len 3)
- "kiwi" (len 4)
- "apple" (len 5)
- "banana" (len 6)
```

**Example 2:**
```
Input: arr = ["cat", "bat", "rat", "apple"]
Output: ["bat", "cat", "rat", "apple"]
Explanation: "bat", "cat", "rat" all have length 3, sorted lexicographically.
```

**Example 3:**
```
Input: arr = ["a", "abc", "ab"]
Output: ["a", "ab", "abc"]
```

## Constraints

- `1 <= n <= 10^5`
- Total characters ≤ 10^6
- All strings consist of lowercase English letters.
