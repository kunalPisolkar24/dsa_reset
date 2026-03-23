# 6. Preorder Traversal (Recursive)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **preorder traversal** (Root -> Left -> Right).

## Example Testcases

**Example 1:**
```
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:
1
 \
  2
 /
3
Preorder: [1, 2, 3]
```

**Example 2:**
```
Input: root = [1,2,3,4,5,6,7]
Output: [1,2,4,5,3,6,7]
Explanation:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
Preorder: [1, 2, 4, 5, 3, 6, 7]
```

**Example 3:**
```
Input: root = [1]
Output: [1]
Explanation:
1
Preorder: [1]
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
