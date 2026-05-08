# Consecutive Bonus Rule

## Description
You are given an array `points[]`. You want to select elements from the array to maximize the total points collected.

However, there is a restriction on how many consecutive elements you can pick:
- You **can** choose a single element.
- You **can** choose two consecutive elements.
- You **cannot** choose **three** consecutive elements.

Find the maximum points you can collect.

## Examples

### Example 1
**Input:** `points = [3, 2, 7, 10]`
**Output:** `20`
**Explanation:** 
- Pick index 1 (2), index 2 (7), and index 3 (10).
- Total = 2 + 7 + 10 = 19? Wait, 3 + 7 + 10 = 20.
- Indices 0, 2, 3 are picked. No three are consecutive.
- Total = 20.

### Example 2
**Input:** `points = [10, 20, 30, 40]`
**Output:** `90`
**Explanation:**
- We must skip one element to avoid 3-consecutive.
- Skip index 0: 20+30+40 = 90.
- Skip index 1: 10+30+40 = 80.
- Skip index 2: 10+20+40 = 70.
- Skip index 3: 10+20+30 = 60.
- Max is 90.

### Example 3
**Input:** `points = [1, 2, 3, 4, 5, 6]`
**Output:** `16`
**Explanation:**
- Pick 1, 2, skip 3, pick 4, 5, skip 6? Total = 12.
- Skip 1, pick 2, 3, skip 4, pick 5, 6. Total = 16.
- Skip 2, pick 1, skip 3, pick 4, 5, 6? No, can't pick 4,5,6.
- Best is skipping 1 and 4: 2+3+5+6 = 16.

## Constraints
- `1 <= n <= 2 * 10^5`
- `0 <= points[i] <= 10^4`
