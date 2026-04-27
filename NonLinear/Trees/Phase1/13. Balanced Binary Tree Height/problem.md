# 13. Balanced Binary Tree Height

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return its height if the tree is **balanced**, otherwise return `-1`.

A binary tree is considered **balanced** if for **every** node in the tree, the absolute difference between the heights of its left and right subtrees is at most `1`.

The height of a tree is the number of nodes in the longest path from the root to a leaf.

## Example Testcases

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: 3
Explanation:
    3
   / \
  9  20
    /  \
   15   7
The tree is balanced. Height is 3.
```

**Example 2:**
```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: -1
Explanation:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
At node 2, left subtree height is 3, right is 1. |3-1| = 2 > 1.
```

**Example 3:**
```
Input: root = [1,null,2,null,3]
Output: -1
Explanation:
1
 \
  2
   \
    3
At node 1, left height is 0, right is 2. |0-2| = 2 > 1.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
