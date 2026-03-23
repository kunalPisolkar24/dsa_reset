# 8. Postorder Traversal (Recursive)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **postorder traversal** (Left -> Right -> Root).

## Example Testcases

**Example 1:**
```
Input: root = [1,null,2,3]
Output: [3,2,1]
Explanation:
1
 \
  2
 /
3
Postorder: [3, 2, 1]
```

**Example 2:**
```
Input: root = [1,2,3]
Output: [2,3,1]
```

**Example 3:**
```
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
