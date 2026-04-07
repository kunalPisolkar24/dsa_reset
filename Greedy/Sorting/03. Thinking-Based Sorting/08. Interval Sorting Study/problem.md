# 8. Interval Sorting Study

**Difficulty:** Medium

## Problem Statement

Given an array of intervals where each interval is represented as a pair `(start, end)`, perform **three separate sorting operations**:

1.  **Sort by Start**: Sort intervals based on the `start` time in ascending order. If starts are equal, sort by `end`.
2.  **Sort by End**: Sort intervals based on the `end` time in ascending order. If ends are equal, sort by `start`.
3.  **Sort by Length**: Sort intervals based on their length `(end - start)` in ascending order. If lengths are equal, sort by `start`.

### Example Testcases

**Example 1:**
```
Input: intervals = [(1, 4), (2, 3), (3, 5), (6, 7)]
Output:
By Start: [(1, 4), (2, 3), (3, 5), (6, 7)]
By End:   [(2, 3), (1, 4), (3, 5), (6, 7)]
By Length: [(2, 3), (6, 7), (3, 5), (1, 4)]
```

**Example 2:**
```
Input: intervals = [[1, 10], [2, 3], [5, 8]]
Output:
By Start: [[1, 10], [2, 3], [5, 8]]
By End:   [[2, 3], [5, 8], [1, 10]]
By Length: [[2, 3], [5, 8], [1, 10]]
```

### Observation Task

Once you've implemented these, observe which ordering seems most natural for tasks like:
- Finding the maximum number of non-overlapping intervals (Greedy choice).
- Merging overlapping intervals.

## Constraints

- `1 <= n <= 10^5`
- `0 <= start <= end <= 10^9`
