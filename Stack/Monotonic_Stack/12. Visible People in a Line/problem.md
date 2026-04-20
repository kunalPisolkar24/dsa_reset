# 12. Visible People in a Line

**Difficulty:** Medium

## Problem Statement

There are `n` people in a queue. A person `i` can see person `j` (i < j) if everyone in between is strictly shorter than both. Return how many people each person can see to their right.

### Example Testcases

**Example 1:**
```
Input: heights = {10, 6, 8, 5, 11, 9}
Output: {3, 1, 2, 1, 1, 0}
Explanation: Person 0 sees 1, 2, and 4. Person 4 sees 5.
```

**Example 2:**
```
Input: heights = {5, 1, 2, 3, 10}
Output: {4, 1, 1, 1, 0}
```

**Example 3:**
```
Input: heights = {1, 2, 3, 4}
Output: {1, 1, 1, 0}
```

## Constraints

- `1 <= heights.length <= 10^5` 
- `1 <= heights[i] <= 10^9` 
- All heights are unique.
