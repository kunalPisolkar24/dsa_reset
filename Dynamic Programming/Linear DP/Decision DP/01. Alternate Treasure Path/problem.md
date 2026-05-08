# Alternate Treasure Path

## Description
You are given an array `coins[]` representing the number of coins at each position. You start at index `0` and want to maximize the total coins collected.

From any index `i`, you have two choices:
1. **Take** the coins at the current position `coins[i]` and move to index `i + 2`.
2. **Skip** the current position `coins[i]` and move to index `i + 1`.

Return the maximum number of coins you can collect starting from index `0`.

## Examples

### Example 1
**Input:** `coins = [4, 2, 7, 9, 3]`
**Output:** `14`
**Explanation:** 
- Take `coins[0]` (4), move to index 2.
- Take `coins[2]` (7), move to index 4.
- Take `coins[4]` (3), move to index 6 (end).
- Total = 4 + 7 + 3 = 14.

### Example 2
**Input:** `coins = [10, 1, 1, 10]`
**Output:** `20`
**Explanation:**
- Take `coins[0]` (10), move to index 2.
- Skip `coins[2]` (1), move to index 3.
- Take `coins[3]` (10), move to index 5 (end).
- Total = 10 + 10 = 20.

### Example 3
**Input:** `coins = [5, 10, 15]`
**Output:** `20`
**Explanation:**
- Skip `coins[0]` (5), move to index 1.
- Take `coins[1]` (10), move to index 3 (end).
- Wait, actually taking `coins[0]` (5) then taking `coins[2]` (15) gives 20.
- So, Total = 5 + 15 = 20.

## Constraints
- `1 <= n <= 10^5`
- `0 <= coins[i] <= 10^4`
