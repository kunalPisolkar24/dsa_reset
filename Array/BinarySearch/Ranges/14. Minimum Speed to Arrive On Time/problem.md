# 14. Minimum Speed to Arrive On Time

**Difficulty:** Medium

## Problem Statement

You are given a floating-point number `hour`, representing the amount of time you have to reach the office. To commute to the office, you must take `n` trains in sequential order. You are also given an integer array `dist` of length `n`, where `dist[i]` describes the distance (in kilometers) of the $i^{th}$ train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.
- For example, if the distance of the $1^{st}$ train ride is 3km and your speed is 1km/h, you will arrive at the $1^{st}$ station in 3 hours.
- If the distance of the $2^{nd}$ train ride is 7km and your speed is 3km/h, you will arrive at the $2^{nd}$ station in $3 + \text{ceil}(7/3) = 3 + 3 = 6$ hours.

The last train does not need to arrive at an integer hour.

Return the **minimum positive integer speed** (in km/h) that all the trains must travel at for you to reach the office on time, or `-1` if it is impossible to be on time.

### Example Testcases

**Example 1:**
```
Input: dist = [1, 3, 2], hour = 6
Output: 1
Explanation: 
At speed 1: 1/1 + ceil(3/1) + 2/1 = 1 + 3 + 2 = 6 (<= 6).
```

**Example 2:**
```
Input: dist = [1, 3, 2], hour = 2.7
Output: 3
Explanation: 
At speed 3: ceil(1/3) + ceil(3/3) + 2/3 = 1 + 1 + 0.67 = 2.67 (<= 2.7).
```

## Constraints

- `n == dist.length`
- `1 <= n <= 10^5`
- `1 <= dist[i] <= 10^5`
- `1 <= hour <= 10^9`
- There will be at most **two digits** after the decimal point in `hour`.
