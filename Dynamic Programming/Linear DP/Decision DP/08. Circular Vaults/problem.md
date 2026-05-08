# Circular Vaults

## Description
A set of vaults is arranged in a **circle**. Each vault `i` contains `money[i]`.

Security Rule:
- Adjacent vaults cannot both be robbed.
- Since the vaults are circular, the first vault (`index 0`) and the last vault (`index n-1`) are considered adjacent.

Find the maximum amount of money you can collect without triggering the alarm.

## Examples

### Example 1
**Input:** `money = [2, 3, 2]`
**Output:** `3`
**Explanation:** 
- You cannot rob vault 0 and vault 2 because they are adjacent in the circle.
- You cannot rob vault 0 and vault 1.
- You cannot rob vault 1 and vault 2.
- The best option is to rob only vault 1. Total = 3.

### Example 2
**Input:** `money = [1, 2, 3, 1]`
**Output:** `4`
**Explanation:**
- Rob vault 0 (1) and vault 2 (3). Total = 4.
- Vault 0 and 2 are not adjacent. Vault 2 and 3 are adjacent. Vault 3 and 0 are adjacent.

### Example 3
**Input:** `money = [1, 2, 3]`
**Output:** `3`
**Explanation:**
- Rob vault 2. Total = 3.

## Constraints
- `1 <= n <= 10^5`
- `0 <= money[i] <= 10^4`
