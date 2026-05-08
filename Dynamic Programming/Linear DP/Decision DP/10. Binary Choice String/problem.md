# Binary Choice String

## Description
You are given a binary string `s` consisting of '0's and '1's. You want to delete the minimum number of characters such that the resulting string has **no two adjacent '1's**.

In other words, in the final string, every '1' must be separated by at least one '0', or there can be no '1's at all.

Find the minimum number of deletions required.

## Examples

### Example 1
**Input:** `s = "1101011"`
**Output:** `2`
**Explanation:** 
- Delete the second '1' (at index 1) and the last '1' (at index 6).
- Result: "10101". No two '1's are adjacent.
- Total deletions = 2.

### Example 2
**Input:** `s = "11111"`
**Output:** `2`
**Explanation:**
- To have no two '1's adjacent, the best result is "10101" but we only have '1's.
- So we can only keep "11" is not allowed. We can keep "101" if we had 0s.
- With only '1's, we can keep at most `ceil(5/2) = 3` ones.
- Result: "111" but we need them to be non-adjacent.
- Wait, if there are NO '0's, then we can only keep ONE '1' or multiple '1's with '0's in between.
- If the original string is "11111", and we delete characters, the result is "1", "11", etc.
- If we keep "11", they are adjacent. So we can only keep "1".
- To keep "1", we delete 4.
- Wait, the example "1101011" output is 2.
- Original: `1 1 0 1 0 1 1`
- Indices: `0 1 2 3 4 5 6`
- If we delete index 1 and 6: `s[0]=1, s[2]=0, s[3]=1, s[4]=0, s[5]=1`. Result "10101".
- No two '1's are adjacent in the RESULTING string.
- This is correct.

### Example 3
**Input:** `s = "1001"`
**Output:** `0`
**Explanation:**
- No two '1's are adjacent. 0 deletions.

## Constraints
- `1 <= s.length <= 10^5`
- `s[i]` is either '0' or '1'.
