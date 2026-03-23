# 10. Build Array With Stack Operations

**Difficulty:** Medium

## Problem Statement

You are given an integer array `target` and an integer `n`.

You have an empty stack with the two following operations:
- **"Push"**: Pushes an integer to the top of the stack.
- **"Pop"**: Removes the integer on the top of the stack.

You also have a stream of the integers `[1, 2, 3, ..., n]`.

Use the two stack operations to make the stack content equal to `target`. You should binary-check the integers in the stream in the order they appear.

Rules:
- If the integer in the stream is part of `target`, you should **"Push"** it.
- If the integer in the stream is NOT part of `target`, you should **"Push"** it, then **"Pop"** it.
- You can stop as soon as the stack matches `target`.

Return the list of operations needed.

### Example Testcases

**Example 1:**
```
Input: target = [1, 3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read 1: In target, Push 1.
Read 2: Not in target, Push 2 then Pop 2.
Read 3: In target, Push 3.
Stack becomes [1, 3].
```

**Example 2:**
```
Input: target = [1, 2, 3], n = 3
Output: ["Push","Push","Push"]
```

**Example 3:**
```
Input: target = [1, 2], n = 4
Output: ["Push","Push"]
Explanation: You can stop as soon as the stack matches target.
```

## Constraints

- `1 <= target.length <= 100`
- `1 <= n <= 100`
- `1 <= target[i] <= n`
- `target` is strictly increasing.
