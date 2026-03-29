# 11. Maximum Minimum Distance

**Difficulty:** Medium

## Problem Statement

You are given an array `positions` representing the locations of `n` stalls on a straight line. You have `k` aggressive cows that you need to assign to the stalls such that the **minimum distance** between any two of them is **maximized**.

Return the largest possible minimum distance.

### Example Testcases

**Example 1:**
```
Input: positions = [1, 2, 8, 4, 9], k = 3
Output: 3
Explanation: 
Sorted positions: [1, 2, 4, 8, 9]
One optimal way to place 3 cows is at stalls 1, 4, and 8. 
Distances: (4-1)=3, (8-4)=4. Min distance = 3.
Another way: 1, 4, 9. Distances: 3, 5. Min distance = 3.
Maximum minimum distance is 3.
```

**Example 2:**
```
Input: positions = [10, 2, 5, 3, 15], k = 3
Output: 5
```

## Constraints

- `2 <= positions.length <= 10^5`
- `0 <= positions[i] <= 10^9`
- `2 <= k <= positions.length`
