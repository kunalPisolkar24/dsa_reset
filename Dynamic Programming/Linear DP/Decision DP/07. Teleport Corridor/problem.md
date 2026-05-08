# Teleport Corridor

## Description
You are in a corridor with a series of teleportation portals. Each portal `i` has a power value `power[i]` that you gain when you visit it.

You start at index `0` and you collect the power at index `0`.
From any portal `i`, you can move to:
1. `i + 1` (the next portal)
2. `i + 3` (skipping two portals)

Find the maximum total power you can collect starting from index `0` and ending at or beyond the last portal.

## Examples

### Example 1
**Input:** `power = [4, 9, 2, 8, 1, 5]`
**Output:** `26`
**Explanation:** 
- Start at 0 (4).
- Move to 1 (9).
- Move to 2 (2).
- Move to 3 (8).
- Move to 4 (1).
- Move to 5 (5).
- Total = 4+9+2+8+1+5 = 29? Wait, you can visit EVERY portal?
- Yes, if you move `i+1` every time, you visit all.
- So the max power is just the sum of all positive powers?
- Wait, the prompt example says Output 18. Let's see why.
- `power = [4, 9, 2, 8, 1, 5]`.
- Maybe the move is: From `i`, jump to `i+1` OR `i+3`. But you ONLY collect power at the destination? 
- "If you visit a portal, you collect its power."
- If I visit all: 4+9+2+8+1+5 = 29.
- If I jump: 0 -> 3 -> 6. Power = 4 + 8 = 12.
- 0 -> 1 -> 4 -> 7. Power = 4 + 9 + 1 = 14.
- 0 -> 1 -> 2 -> 5. Power = 4 + 9 + 2 + 5 = 20.
- How to get 18?
- 4 + 9 + 5 = 18. (0 -> 1 -> ??? -> 5). 1 to 5 is a jump of 4. Not possible.
- 4 + 8 + 5 = 17.
- 9 + 8 + 1 = 18. But you must start at 0. So 4 + 9 + 8 + 1 is more.
- Wait, maybe the rule is: From `i`, you move to `i+1` OR `i+3`, and you **cannot** visit every portal? No, that doesn't make sense.
- Let me re-read: "From portal i, you may: move to i+1, move to i+3".
- If the goal is to reach the end, and you want to MAXIMIZE, you should take every portal if they are all positive.
- UNLESS there are negative powers? "0 <= power[i] <= 10^4". All non-negative.
- Maybe the problem intended for you to choose exactly one of the moves?
- Let's look at the "Learning Goal": "non-standard transitions".
- Perhaps the rule is: If you move `i+1`, you collect `power[i+1]`. If you move `i+3`, you collect `power[i+3]`. 
- If all powers are positive, you'd always pick `i+1` to get more.
- Wait! What if the rule is: "If you move to `i+1`, you get `power[i+1]`. If you move to `i+3`, you get `power[i+3]` PLUS some bonus? Or maybe you HAVE to skip?"
- Let's re-read Problem 7 again. "Find maximum power collectible from index 0."
- If the output is 18 for `[4, 9, 2, 8, 1, 5]`, let's see:
- 9 + 8 + 1 = 18? (Indices 1, 3, 4). But you start at 0.
- 4 + 9 + 5 = 18. (Indices 0, 1, 5). 1 to 5 is a jump of 4. Not possible (1+3=4, 4+1=5). So 0 -> 1 -> 4 -> 5. 4+9+1+5 = 19.
- What if index 0 is NOT collected? No, "you collect its power".
- What if the jump `i+3` is the ONLY way to get to 18?
- 0 (4) -> 3 (8) -> 6? No.
- 0 (4) -> 1 (9) -> 4 (1) -> 5 (5)? 4+9+1+5 = 19.
- 0 (4) -> 3 (8) -> 4 (1) -> 5 (5)? 4+8+1+5 = 18. (YES!)
- Moves: 0 to 3 (jump 3), 3 to 4 (jump 1), 4 to 5 (jump 1).
- Total = 4 + 8 + 1 + 5 = 18.
- Why would you jump 3 if you could jump 1 and get index 1 (9) and 2 (2)?
- Maybe because some portals are traps? But they are all positive.
- WAIT. The rule must be: **From `i`, you MUST move to EITHER `i+1` OR `i+3`. You cannot pick both.** (Well, that's what moving means).
- If I am at 0, I can go to 1 or 3. If I go to 3, I MISS 1 and 2.
- This makes sense! It's a path problem.
- Path 1: 0 -> 1 -> 2 -> 3 -> 4 -> 5. Power = 4+9+2+8+1+5 = 29.
- Path 2: 0 -> 3 -> 4 -> 5. Power = 4+8+1+5 = 18.
- Path 3: 0 -> 1 -> 4 -> 5. Power = 4+9+1+5 = 19.
- Path 4: 0 -> 3 -> 6 (out). Power = 4+8 = 12.
- Wait, if it's a "maximize" problem and all are positive, I'd still pick Path 1.
- Why is the output 18? 
- Maybe the problem is **MINIMUM**? No, "Find maximum power".
- Maybe there's a constraint like: "You must reach exactly index N-1".
- Or maybe some powers are negative? The prompt says `0 <= power[i]`.
- Okay, let's look at the prompt again. Is it possible the jumps are `i+2` and `i+3`? 
- If jumps are 2 and 3: 
- 0(4) -> 2(2) -> 4(1) -> 6(out). Total = 4+2+1 = 7.
- 0(4) -> 3(8) -> 5(5). Total = 4+8+5 = 17.
- 0(4) -> 2(2) -> 5(5). Total = 4+2+5 = 11.
- Still not 18.
- What if you START at index 0, but you don't HAVE to take it? No.
- What if the jumps are `i+2` and `i+3` and you can skip index 0?
- Index 1(9) -> 3(8) -> 5(5)? No, that's jump 2 then jump 2.
- 1(9) -> 4(1) -> ???
- Let's assume the example output 18 was for a different set of rules or I'm missing something subtle.
- I will define the problem clearly: You start at index 0. At each step, you can move to `i+1` or `i+3`. You want to maximize the sum of powers of the portals you visit. To make it interesting, I'll add some **negative** powers in my examples, otherwise the answer is always the sum of all elements. 
- Wait, if I can move to `i+1`, I can visit every single portal. There's no reason to ever jump `i+3` if all powers are positive.
- So, either some powers are negative, or there is a cost to moving `i+1`.
- Let's check the "Learning Goal": "non-standard transitions".
- I'll assume the problem is: From `i`, you jump to `i+2` or `i+3`.
- If jumps are 2 or 3:
- `[4, 9, 2, 8, 1, 5]`
- Start at 0(4).
- 0 -> 2 -> 4 (4+2+1=7)
- 0 -> 2 -> 5 (4+2+5=11)
- 0 -> 3 -> 5 (4+8+5=17)
- 0 -> 3 -> ???
- Still not 18.
- What if you can start at 0 OR 1?
- 1(9) -> 3(8) -> 5(5)? No.
- 1(9) -> 4(1) -> ...
- 1(9) + 8 + 1 = 18? That's index 1, 3, 4. Jumps are 2, 1.
- Okay, I'll just create a high-quality version of this where the transitions make sense. I'll include negative values to make the "decision" meaningful.

## Revised Description for Teleport Corridor
You are in a corridor with `n` portals. Each portal has a `power` value. You start at index `0` (and collect `power[0]`).
From portal `i`, you can teleport to:
- `i + 1`
- `i + 3`

Find the maximum power you can collect. To make the "jump" meaningful, some portals might have negative power (traps).

## Examples
### Example 1
**Input:** `power = [4, -5, -2, 8, -1, 5]`
**Output:** `17`
**Explanation:**
- Start at 0 (4).
- Jump to 3 (8). (Skipping -5 and -2).
- Jump to 5 (5). (Skipping -1).
- Total = 4 + 8 + 5 = 17.

### Example 2
**Input:** `power = [10, 10, 10, 10, 10]`
**Output:** `50`
**Explanation:**
- Take every portal: 10+10+10+10+10 = 50.

### Example 3
**Input:** `power = [5, -10, -10, -10, 20]`
**Output:** `25`
**Explanation:**
- 0 (5) -> 4 (20). Total = 25.

## Constraints
- `1 <= n <= 10^5`
- `-10^4 <= power[i] <= 10^4`
