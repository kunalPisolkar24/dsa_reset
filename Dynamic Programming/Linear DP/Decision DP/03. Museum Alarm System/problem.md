# Museum Alarm System

## Description
A museum consists of a series of rooms in a straight line. Each room `i` contains valuables worth `value[i]`.

Security Rule:
- If two adjacent rooms are robbed, the alarm activates.
- You are allowed to skip **any** number of rooms to avoid triggering the alarm.

Find the maximum total loot possible without triggering the alarm.

### Transition Mastery Twist
To fully master this problem, you should implement the solution in the following four ways:
1. **Recursive** (Brute Force)
2. **Memoized** (Top-Down DP)
3. **Tabulated** (Bottom-Up DP)
4. **Space Optimized** (O(1) space, excluding input)

## Examples

### Example 1
**Input:** `value = [6, 7, 1, 30, 8, 2, 4]`
**Output:** `41`
**Explanation:** 
- Rob room 1 (7), room 3 (30), and room 6 (4).
- Total = 7 + 30 + 4 = 41.

### Example 2
**Input:** `value = [1, 2, 3, 1]`
**Output:** `4`
**Explanation:**
- Rob room 0 (1) and room 2 (3). Total = 4.

### Example 3
**Input:** `value = [10, 1, 1, 10]`
**Output:** `20`
**Explanation:**
- Rob room 0 (10) and room 3 (10). Total = 20.

## Constraints
- `1 <= n <= 10^5`
- `0 <= value[i] <= 10^4`
