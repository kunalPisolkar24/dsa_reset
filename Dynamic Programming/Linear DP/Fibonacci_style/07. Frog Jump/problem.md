# 7. Frog Jump

**Difficulty:** Medium

## Problem Statement

There is a frog staying on the 1st stair of a staircase. There are `n` stairs in total, and the $i$-th stair has a height $h_i$. The frog is currently on the 1st stair and wants to reach the $n$-th stair.

The frog can jump to either the $(i+1)$-th stair or the $(i+2)$-th stair from the $i$-th stair. The cost of a jump from $i$ to $j$ is $|h_i - h_j|$, where $|x|$ denotes the absolute value of $x$.

Find the minimum possible total cost incurred before the frog reaches the $n$-th stair.

### Example Testcases

**Example 1:**
```
Input: heights = [10, 30, 40, 20]
Output: 30
Explanation:
1. Jump from 1st to 2nd (cost |30-10| = 20)
2. Jump from 2nd to 4th (cost |20-30| = 10)
Total cost: 20 + 10 = 30.
```

**Example 2:**
```
Input: heights = [10, 10]
Output: 0
Explanation: Jump from 1st to 2nd (cost |10-10| = 0).
```

**Example 3:**
```
Input: heights = [30, 10, 60, 10, 60, 50]
Output: 40
Explanation:
1. Jump from 1st to 3rd (cost |60-30| = 30)
2. Jump from 3rd to 5th (cost |60-60| = 0)
3. Jump from 5th to 6th (cost |50-60| = 10)
Total cost: 30 + 0 + 10 = 40.
```

## Constraints

- `2 <= n <= 10^5`
- `1 <= heights[i] <= 10^4`
