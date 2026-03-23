# 11. Mirror Tree Check (Basic)

**Difficulty:** Easy

## Problem Statement

Check if a binary tree is symmetric around its center (mirror of itself).

## Example Testcases

**Example 1:**
```
Input: root = [1,2,2,3,4,4,3]
Output: true
Explanation:
    1
   / \
  2   2
 / \ / \
3  4 4  3
This tree is symmetric.
```

**Example 2:**
```
Input: root = [1,2,2,null,3,null,3]
Output: false
Explanation:
    1
   / \
  2   2
   \   \
    3   3
This tree is not symmetric.
```

**Example 3:**
```
Input: root = [1,2,2,3,None,None,3]
Output: true
Explanation:
    1
   / \
  2   2
 /     \
3       3
This tree is symmetric.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 1000]`.
- `-100 <= Node.val <= 100`
