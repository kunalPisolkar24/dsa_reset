# 4. Stack Permutation Check

**Difficulty:** Medium

## Problem Statement

You are given two arrays `A` and `B`, both of size `n` and containing permutations of numbers. Check if `B` can be obtained from `A` using a stack with the following operations:
1. Push an element from `A` onto the stack.
2. Pop an element from the stack and append it to `B`'s sequence.

Return `true` if `B` is a valid stack permutation of `A`, otherwise `false`.

### Example Testcases

**Example 1:**
```
Input: A = [1, 2, 3], B = [2, 1, 3]
Output: true
Explanation:
Push 1, Push 2. Pop 2. Pop 1. Push 3. Pop 3.
The popped sequence is [2, 1, 3], which matches B.
```

**Example 2:**
```
Input: A = [1, 2, 3], B = [3, 1, 2]
Output: false
```

## Constraints

- `1 <= n <= 10^5`
- `A` and `B` contain identical sets of unique numbers.
- Uses standard push and pop operations of a stack.
