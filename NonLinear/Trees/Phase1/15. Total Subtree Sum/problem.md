# 15. Total Subtree Sum

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, calculate the **sum of all node values** in the entire tree.

## Example Testcases

**Example 1:**
```
Input: root = [1,2,3]
Output: 6
Explanation:
   1
  / \
 2   3
Sum = 1 + 2 + 3 = 6.
```

**Example 2:**
```
Input: root = [10,-2,5]
Output: 13
Explanation:
   10
  /  \
-2    5
Sum = 10 + (-2) + 5 = 13.
```

**Example 3:**
```
Input: root = [1,null,2,null,3]
Output: 6
Explanation:
1
 \
  2
   \
    3
Sum = 1 + 2 + 3 = 6.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
