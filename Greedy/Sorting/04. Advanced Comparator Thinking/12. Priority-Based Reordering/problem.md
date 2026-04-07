# 12. Priority-Based Reordering

**Difficulty:** Hard

## Problem Statement

You are given an array `arr` and a `priority` array. Reorder `arr` such that:

1.  All elements in `arr` that are also present in `priority` appear first, in the same relative order as they appear in the `priority` array.
2.  All remaining elements (those not in `priority`) should appear after the prioritized elements, sorted in **ascending order**.

Note: If an element appears multiple times in `arr` and is in `priority`, all occurrences should be placed together in the prioritized section.

### Example Testcases

**Example 1:**
```
Input:
arr = [7, 2, 5, 3, 9, 3]
priority = [5, 3, 7]

Output: [5, 3, 3, 7, 2, 9]
Explanation:
- 5 is first in priority.
- 3 is second (appears twice in arr).
- 7 is third.
- Remaining: 2, 9 (sorted ascending).
```

**Example 2:**
```
Input:
arr = [1, 4, 2, 3]
priority = [4, 1]

Output: [4, 1, 2, 3]
```

**Example 3:**
```
Input:
arr = [10, 20, 30]
priority = []

Output: [10, 20, 30]
```

## Constraints

- `1 <= n <= 10^5`
- `0 <= priority.length <= 10^5`
- `-10^9 <= arr[i], priority[i] <= 10^9`
