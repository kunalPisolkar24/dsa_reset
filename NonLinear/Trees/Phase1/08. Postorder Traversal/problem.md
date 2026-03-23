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
Input: root = [1,2,3,4,5,6,7]
Output: [4,5,2,6,7,3,1]
Explanation:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
Postorder: [4, 5, 2, 6, 7, 3, 1]
```

**Example 3:**
```
Input: root = [1,null,2]
Output: [2,1]
Explanation:
1
 \
  2
Postorder: [2, 1]
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
