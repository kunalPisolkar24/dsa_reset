# 7. Allocate Books

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

## Constraints

- `1 <= pages.length <= 10^5`
- `1 <= pages[i] <= 10^9`
- `1 <= m <= pages.length`
