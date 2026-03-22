# 2. Valid Bracket String

**Difficulty:** Easy

## Problem Statement

Given a string consisting only of characters `'(', ')'`, `'{', '}'`, `'['`, `']'`, determine if the input string is valid.

A string is valid if:
1. Every opening bracket has a corresponding closing bracket of the same type.
2. The correct order is maintained (brackets must close in the correct order).

### Example Testcases

**Example 1:**
```
Input: s = "{[()]}"
Output: true
```

**Example 2:**
```
Input: s = "{[(])}"
Output: false
```

## Constraints

- `1 <= s.length <= 10^5`
- `s` consists only of parentheses `()[]{}`.
