# 7. Stock Span Variant

**Difficulty:** Medium

## Problem Statement

The span of a stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price was less than or equal to today's price.

### Example Testcases

**Example 1:**
```
Input: prices = {100, 80, 60, 70, 60, 75, 85}
Output: {1, 1, 1, 2, 1, 4, 6}
```

**Example 2:**
```
Input: prices = {10, 10, 10}
Output: {1, 2, 3}
```

**Example 3:**
```
Input: prices = {31, 41, 59, 26, 53, 58, 97}
Output: {1, 2, 3, 1, 2, 3, 7}
```

## Constraints

- `1 <= prices.length <= 10^5` 
- `1 <= prices[i] <= 10^5`
