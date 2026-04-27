# 9. Path with Maximum Even Sum

**Difficulty:** Hard

## Problem Statement

Given the `root` of a binary tree, return the maximum sum obtained from a **root-to-leaf** path such that the sum is an **even** number. If no such path exists, return -1.

## Example Testcases

**Example 1:**
```text
      1
     / \
    2   3
```
```
Input: root = [1,2,3]
Output: 4
Explanation: Paths are [1,2] (sum 3) and [1,3] (sum 4). Max even sum is 4.
```

**Example 2:**
```text
      5
     / \
    3   8
       /
      7
```
```
Input: root = [5,3,8,null,null,7]
Output: 20
Explanation: Paths are [5,3] (sum 8) and [5,8,7] (sum 20). Max even sum is 20.
```

**Example 3:**
```text
      1
     / \
    3   5
```
```
Input: root = [1,3,5]
Output: 6
Explanation: Paths [1,3] sum 4. [1,5] sum 6. Max 6.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 5000]`.
- `-1000 <= Node.val <= 1000`
