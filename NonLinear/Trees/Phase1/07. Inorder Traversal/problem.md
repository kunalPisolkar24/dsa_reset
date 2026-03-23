# 7. Inorder Traversal (Recursive)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **inorder traversal** (Left -> Root -> Right).

## Example Testcases

**Example 1:**
```
Input: root = [1,null,2,3]
Output: [1,3,2]
Explanation:
1
 \
  2
 /
3
Inorder: [1, 3, 2]
```

**Example 2:**
```
Input: root = [1,2,3,4,5,6,7]
Output: [4,2,5,1,6,3,7]
Explanation:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
Inorder: [4, 2, 5, 1, 6, 3, 7]
```

**Example 3:**
```
Input: root = [1,2,null,3]
Output: [3,2,1]
Explanation:
    1
   /
  2
 /
3
Inorder: [3, 2, 1]
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
