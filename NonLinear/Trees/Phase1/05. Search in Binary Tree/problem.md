# 5. Search in Binary Tree

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree and an integer `val`, return `true` if a node with value `val` exists in the tree.

## Example Testcases

**Example 1:**
```
Input: root = [4,2,7,1,3], val = 2
Output: true
Explanation:
      4
     / \
    2   7
   / \
  1   3
Node 2 exists in the tree.
```

**Example 2:**
```
Input: root = [1,null,2,null,3], val = 5
Output: false
Explanation:
1
 \
  2
   \
    3
Node 5 does not exist in the tree.
```

**Example 3:**
```
Input: root = [1,2,2,3,4,4,3], val = 4
Output: true
Explanation:
    1
   / \
  2   2
 / \ / \
3  4 4  3
Node 4 exists in the tree.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^7 <= Node.val <= 10^7`
- `-10^7 <= val <= 10^7`
