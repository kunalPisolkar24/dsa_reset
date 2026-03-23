# 1. Count Total Nodes

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the total number of nodes in the tree.

## Example Testcases

**Example 1:**
```
Input: root = [1,2,3,4]
Output: 4
Explanation:
    1
   / \
  2   3
 /
4
There are 4 nodes in total.
```

**Example 2:**
```
Input: root = [1,null,2,null,3]
Output: 3
Explanation:
1
 \
  2
   \
    3
There are 3 nodes in total.
```

**Example 3:**
```
Input: root = []
Output: 0
Explanation: The tree is empty.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
