# 11. Multi-Level String Sorting

**Difficulty:** Hard

## Problem Statement

Given an array of strings `arr`, sort them according to the following priorities:

1.  **Last Character**: Sort by the last character of each string in ascending order.
2.  **Length**: If the last characters are equal, sort by the string's length in ascending order.
3.  **Lexicographical**: If both the last character and the length are equal, sort the strings lexicographically in ascending order.

### Example Testcases

**Example 1:**
```
Input: arr = ["cat", "bat", "apple", "dog"]
Sort steps:
- Last chars: 't', 't', 'e', 'g'
- Sorted last chars: 'e' (apple), 'g' (dog), 't' (bat, cat)
- Tie between "bat" and "cat": Both len 3. Lexicographical: "bat", then "cat".
Output: ["apple", "dog", "bat", "cat"]
```

**Example 2:**
```
Input: arr = ["banana", "apple", "cherry"]
Last chars: 'a', 'e', 'y'
Output: ["banana", "apple", "cherry"]
```

**Example 3:**
```
Input: arr = ["abc", "abd", "abe"]
Output: ["abc", "abd", "abe"]
```

## Constraints

- `1 <= n <= 10^5`
- Total characters ≤ 10^6
- All strings consist of lowercase English letters and are non-empty.
