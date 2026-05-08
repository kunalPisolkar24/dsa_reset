# Task Scheduling With Cooldown

## Description
You are given a list of tasks where each task `i` has a profit `profit[i]`.

Rules:
- If you perform task `i`, you must rest for **ONE day** before you can perform the next task. This means if you do task `i`, you cannot do task `i + 1`.
- You can skip as many tasks as you want.

Find the maximum total profit you can achieve.

### Advanced Extension
After solving the base problem, consider how the solution changes if:
1. The cooldown is `k` days (performing task `i` means you can't perform tasks `i+1` to `i+k`).
2. The cooldown `k` is a variable given in the input.

## Examples

### Example 1
**Input:** `profit = [3, 2, 5, 10, 7]`
**Output:** `15`
**Explanation:** 
- Perform task 0 (3).
- Skip task 1 (cooldown).
- Skip task 2 (to perform task 3).
- Perform task 3 (10).
- Skip task 4 (cooldown).
- Wait, 3 + 5 + 7 = 15? 
- Let's check: Task 0 (3), Task 2 (5), Task 4 (7). 
- Between 0 and 2 is 1 day (task 1), which is enough rest.
- Between 2 and 4 is 1 day (task 3), which is enough rest.
- Total = 3 + 5 + 7 = 15.

### Example 2
**Input:** `profit = [1, 2, 3, 4, 5]`
**Output:** `9`
**Explanation:**
- Perform tasks 0, 2, 4. Total = 1 + 3 + 5 = 9.

### Example 3
**Input:** `profit = [10, 1, 1, 10]`
**Output:** `20`
**Explanation:**
- Perform tasks 0 and 3. Total = 10 + 10 = 20. (Task 1 and 2 are skipped).

## Constraints
- `1 <= n <= 2 * 10^5`
- `0 <= profit[i] <= 10^6`
