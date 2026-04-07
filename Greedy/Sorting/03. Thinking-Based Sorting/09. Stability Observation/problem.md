# 9. Stability Observation

**Difficulty:** Medium

## Problem Statement

Given an array of pairs `(value, label)`, sort the array based on the `value` in ascending order.

The goal of this problem is to observe the property of **Stability** in sorting algorithms. A sorting algorithm is stable if it preserves the relative order of elements with equal keys.

### Task

1.  Sort the input array by `value`.
2.  Use a **Stable Sort** algorithm (like `std::stable_sort` in C++) to ensure that equal values maintain their original relative order of labels.

### Example Testcases

**Example 1:**
```
Input: arr = [(1, 'A'), (3, 'B'), (1, 'C'), (2, 'D')]
Output: [(1, 'A'), (1, 'C'), (2, 'D'), (3, 'B')]
Explanation: 'A' and 'C' both have value 1. In a stable sort, 'A' must remain before 'C' because it appeared first in the input.
```

**Example 2:**
```
Input: arr = [(2, 'X'), (1, 'Y'), (2, 'Z')]
Output: [(1, 'Y'), (2, 'X'), (2, 'Z')]
```

**Example 3:**
```
Input: arr = [(5, 'P'), (5, 'Q'), (5, 'R')]
Output: [(5, 'P'), (5, 'Q'), (5, 'R')]
```

## Constraints

- `1 <= n <= 10^5`
- `0 <= value <= 10^9`
- `label` is a character from 'A' to 'Z'.
