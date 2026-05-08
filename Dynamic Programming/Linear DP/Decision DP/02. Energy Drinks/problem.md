# Energy Drinks

## Description
A runner is moving through a sequence of checkpoints. Each checkpoint `i` has an energy drink with a specific energy value `energy[i]`.

The runner wants to maximize the total energy gained, but there is a restriction:
- If the runner drinks at checkpoint `i`, they become tired and **cannot** drink at the next checkpoint `i + 1`.

Find the maximum total energy the runner can gain.

## Examples

### Example 1
**Input:** `energy = [5, 1, 2, 10, 6]`
**Output:** `15`
**Explanation:** 
- Drink at index 0 (5).
- Skip index 1.
- Skip index 2 (to allow drinking at index 3).
- Drink at index 3 (10).
- Skip index 4.
- Total = 5 + 10 = 15.

### Example 2
**Input:** `energy = [1, 2, 3, 1]`
**Output:** `4`
**Explanation:**
- Drink at index 0 (1) and index 2 (3). Total = 4.
- Or drink at index 1 (2) and index 3 (1). Total = 3.
- Maximum is 4.

### Example 3
**Input:** `energy = [10, 20, 30, 40, 50]`
**Output:** `90`
**Explanation:**
- Drink at index 1 (20) and index 3 (40)? No, index 0, 2, 4 is better.
- 10 + 30 + 50 = 90.

## Constraints
- `1 <= n <= 2 * 10^5`
- `0 <= energy[i] <= 10^6`
