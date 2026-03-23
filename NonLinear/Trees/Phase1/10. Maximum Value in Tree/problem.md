# 10. Maximum Value in Tree

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **maximum value** among all nodes.

## Example Testcases

**Example 1:**
```
Input: root = [1,3,2,5]
Output: 5
Explanation:
    1
   / \
  3   2
 /
5
Max node is 5.
```

**Example 2:**
```
Input: root = [-10,-3,-20]
Output: -3
Explanation:
    -10
    / \
  -3  -20
Max node is -3.
```

**Example 3:**
```
Input: root = [10,5,15,3,7,12,18]
Output: 18
Explanation:
        10
      /    \
     5      15
    / \    /  \
   3   7  12   18
Max node is 18.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
