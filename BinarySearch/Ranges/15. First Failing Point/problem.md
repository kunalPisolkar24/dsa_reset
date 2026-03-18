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
For x = 10: ceil(10/10) + ceil(20/10) + ceil(30/10) = 1 + 2 + 3 = 6 (<= 6). True.
For x = 9: ceil(10/9) + ceil(20/9) + ceil(30/9) = 2 + 3 + 4 = 9 (> 6). False.
The first integer x such that f(x) is true is 10.
```

**Example 2:**
```
Input: low = 1, high = 100, thresholds = [5, 5, 5], limit = 10
Output: 2
Explanation:
For x = 2: ceil(5/2) + ceil(5/2) + ceil(5/2) = 3 + 3 + 3 = 9 (<= 10). True.
For x = 1: ceil(5/1) + ceil(5/1) + ceil(5/1) = 5 + 5 + 5 = 15 (> 10). False.
Output: 2.
```

**Example 3:**
```
Input: low = 1, high = 5, thresholds = [10], limit = 1
Output: -1
Explanation:
Even at the maximum possible x = 5, ceil(10/5) = 2, which is greater than the limit 1.
No value in the range [1, 5] makes f(x) true.
```

## Constraints

- `1 <= low <= high <= 10^12`
- `1 <= thresholds.length <= 10^5`
- `1 <= thresholds[i] <= 10^9`
- `1 <= limit <= 10^14`
