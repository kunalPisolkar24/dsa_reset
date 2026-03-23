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
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
Output: 10
Explanation:
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
There are 10 nodes in total.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
