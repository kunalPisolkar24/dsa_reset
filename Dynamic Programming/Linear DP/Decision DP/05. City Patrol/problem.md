# City Patrol

## Description
A security drone patrols city sectors arranged in a line. Each sector `i` has a risk value `risk[i]` representing the danger eliminated by securing that sector.

The drone's hardware limitations prevent it from securing sectors that are too close to each other.
**Rule:** The drone cannot secure two sectors within a distance of 2.
- If it secures sector `i`, it **cannot** secure:
  - `i - 1` (Distance 1)
  - `i - 2` (Distance 2)
  - `i + 1` (Distance 1)
  - `i + 2` (Distance 2)

Essentially, if you secure sector `i`, the next sector you can potentially secure is `i + 3`.

Find the maximum total risk eliminated.

## Examples

### Example 1
**Input:** `risk = [8, 2, 9, 3, 1, 7]`
**Output:** `17`
**Explanation:** 
- Option 1: Secure sector 0 (8) and sector 2 (9). Total = 17. (Distance between 0 and 2 is 2, wait. Rule says "within distance 2" means distance must be > 2. So 0 and 3 are okay, 0 and 2 are NOT.)
- Let's re-read: "if it secures sector i, it cannot secure: i-1, i+1, i+2".
- Distance 1 is `i+1`. Distance 2 is `i+2`. 
- So if I pick `i`, the next one must be at least `i+3`.
- Example 1 explanation in prompt: "Take 8, 9 OR 8, 7".
- Wait, if it takes 8 (index 0) and 9 (index 2), the distance is 2. But the rule says it cannot secure `i+2`.
- Let's look at the prompt's explanation again: "if it secures sector i, it cannot secure i-1, i+1, i+2".
- This means if I pick 0, I can't pick 1 or 2. So 3 is the next possible.
- If I pick 0 (8), next is 3 (3). Total = 11.
- If I pick 0 (8), next is 4 (1). Total = 9.
- If I pick 0 (8), next is 5 (7). Total = 15.
- If I pick 1 (2), next is 4 (1). Total = 3.
- If I pick 2 (9), next is 5 (7). Total = 16.
- Wait, the prompt says "Output 17". How?
- 8 + 9 = 17. That would mean distance 2 is ALLOWED, but distance 1 is NOT.
- BUT the prompt says "it cannot secure: i-1, i+1, i+2". `i+2` is distance 2.
- Let me re-read the prompt again: "The drone cannot secure two sectors within distance 2."
- Usually "within distance 2" means `dist <= 2`.
- Let's assume the rule is: `If pick i, cannot pick i+1 or i+2`.
- Then the next one is `i+3`.
- In `[8, 2, 9, 3, 1, 7]`:
  - Pick 0 (8), skip 1, 2, pick 3 (3), skip 4, 5. Total = 11.
  - Pick 0 (8), skip 1, 2, 3, pick 4 (1). Total = 9.
  - Pick 0 (8), skip 1, 2, 3, 4, pick 5 (7). Total = 15.
  - Pick 2 (9), skip 0, 1, 3, 4, pick ???
- Wait, if the output is 17, and the explanation says "Take 8, 9", then it means the rule is "skip ONLY 1 sector". But that's House Robber.
- Let's look at the "Learning Goal": "What changes if the skip distance changes?"
- Maybe the prompt's example explanation "Take 8, 9" is a typo and it should be "Take 8 and 7" or something else? No, 8+9=17 and 10+7=17? No.
- Actually, 8+9=17 is index 0 and index 2. Distance is 2.
- If "within distance 2" means `dist < 2`, then distance 2 is okay.
- If the rule is "cannot secure `i+1`", then it's skip 1.
- If the rule is "cannot secure `i+1` and `i+2`", then it's skip 2.
- I will stick to the rule: **If you pick `i`, you must skip at least 2 sectors (next is `i+3`)**.
- If I do that, the max for `[8, 2, 9, 3, 1, 7]` is 15 (8+7).
- Let me check if there is any other way to get 17. 2+3+1+7=13. 8+9=17. 
- If 17 is the answer, then the rule must be "cannot pick `i+1`". But the prompt says "cannot pick `i+1, i+2`".
- I'll assume the prompt meant "if it secures `i`, it cannot secure `i+1` OR `i-1`" for the 17 result, OR the example array was different.
- HOWEVER, I will follow the text: "cannot secure i-1, i+1, i+2". This implies a jump of 3.
- I'll use a different example that makes more sense for a jump of 3.
- Input: `[10, 2, 2, 10, 2, 2, 10]`. Max = 30 (0, 3, 6).
- I'll stick to the prompt's intent: Learning what happens when skip distance changes.

**Wait**, I'll re-read carefully: "if it secures sector i, it cannot secure: i-1, i+1, i+2".
This means `dp[i] = max(risk[i] + dp[i+3], dp[i+1])`.
I'll adjust the example to fit the logic.

### Example 1
**Input:** `risk = [8, 2, 9, 10, 1, 7]`
**Output:** `18`
**Explanation:** 
- Secure sector 0 (8) and sector 3 (10).
- Total = 8 + 10 = 18.
- Note: Sector 2 (9) is skipped because it is within distance 2 of sector 0.

### Example 2
**Input:** `risk = [100, 1, 1, 100, 1, 1, 100]`
**Output:** `300`
**Explanation:**
- Secure sectors 0, 3, and 6.

## Constraints
- `1 <= n <= 10^5`
- `0 <= risk[i] <= 10^4`
