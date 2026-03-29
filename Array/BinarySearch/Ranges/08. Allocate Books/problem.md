# 8. Allocate Books

**Difficulty:** Medium

## Problem Statement

You are given an array of integers `pages`, where `pages[i]` is the number of pages in the $i^{th}$ book. There are `m` students.

The goal is to distribute all the books among `m` students such that:
1. Each student is assigned at least one book.
2. Each student is assigned a **contiguous** sequence of books.
3. The **maximum number of pages** assigned to a student is **minimized**.

Return the minimized maximum cumulative pages. If the allocation is not possible, return `-1`.

### Example Testcases

**Example 1:**
```
Input: pages = [10, 20, 30, 40], m = 2
Output: 60
Explanation: 
Allocation possibilities:
- [10], [20, 30, 40] -> Max pages = 90
- [10, 20], [30, 40] -> Max pages = 70
- [10, 20, 30], [40] -> Max pages = 60
The minimum of these maximums is 60.
```

**Example 2:**
```
Input: pages = [12, 34, 67, 90], m = 2
Output: 113
Explanation: 
Possible allocations:
- [12], [34, 67, 90] -> Max = 191
- [12, 34], [67, 90] -> Max = 157
- [12, 34, 67], [90] -> Max = 113
Min-max value is 113.
```

**Example 3:**
```
Input: pages = [25, 46, 28, 49, 24], m = 4
Output: 71
Explanation: 
The optimal allocation is [25, 46], [28], [49], [24].
The maximum pages assigned to a student is 71.
```


## Constraints

- `1 <= pages.length <= 10^5`
- `1 <= pages[i] <= 10^9`
- `1 <= m <= pages.length`
