# 15. First Failing Point

**Difficulty:** Medium/Hard

## Problem Statement

You are given a range `[low, high]` and a monotonic boolean function `f(x)`. The function `f(x)` is `false` for small values of `x` and becomes `true` after a certain threshold (and stays `true` for all value greater than that).

Your goal is to find the **smallest integer x** in the range `[low, high]` such that `f(x)` is `true`.

In this problem, the function `f(x)` is defined by an array of integers `thresholds` and an integer `limit`. The function `f(x)` is true if:
```
sum(ceil(thresholds[i] / x)) <= limit
```

*Note: This is an abstract representation of many binary search on answers problems. It generalizes the "First True" pattern.*

### Example Testcases

**Example 1:**
```
Input: low = 1, high = 100, thresholds = [10, 20, 30], limit = 6
Output: 10
Explanation:
For x=10, sum = 1+2+3 = 6 (<= 6). True.
For x=9, sum = 2+3+4 = 9 (> 6). False.
The first failing point (first true) is 10.
```

## Constraints

- `1 <= low <= high <= 10^12`
- `1 <= thresholds.length <= 10^5`
- `1 <= thresholds[i] <= 10^9`
- `1 <= limit <= 10^14`
