# 10. Sort by Ratio

**Difficulty:** Hard

## Problem Statement

Given an array of pairs `(value, weight)`, sort them in **descending order** of their ratio `value / weight`.

To avoid precision issues associated with floating-point numbers, use the cross-multiplication method:
Instead of `(v1 / w1) > (v2 / w2)`, use `v1 * w2 > v2 * w1`.

If two pairs have the same ratio, sort them by the **value** in descending order.

### Example Testcases

**Example 1:**
```
Input: arr = [(10, 2), (5, 1), (8, 4), (6, 3)]
Ratios:
10/2 = 5
5/1 = 5
8/4 = 2
6/3 = 2
Output: [(10, 2), (5, 1), (6, 3), (8, 4)]
Explanation: 
- (10, 2) and (5, 1) both have ratio 5. Sorted by value: 10 then 5.
- (6, 3) and (8, 4) both have ratio 2. Sorted by value: 6 then 8 (Wait, sorted by value descending, so 8 then 6? No, let's stick to a clear rule).
Actually, let's use: If ratios are equal, sort by value descending.
So (10, 2), (5, 1), (8, 4), (6, 3).
```

**Example 2:**
```
Input: arr = [(1, 3), (2, 5), (3, 7)]
Ratios: 0.33, 0.4, 0.428
Output: [(3, 7), (2, 5), (1, 3)]
```

**Example 3:**
```
Input: arr = [(10, 5), (20, 10)]
Output: [(20, 10), (10, 5)]
```

## Constraints

- `1 <= n <= 10^5`
- `1 <= value, weight <= 10^9`
