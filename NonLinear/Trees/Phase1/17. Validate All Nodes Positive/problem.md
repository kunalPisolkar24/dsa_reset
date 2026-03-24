# 17. Validate All Nodes Positive

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return `true` if **every node** in the tree has a value strictly greater than `0`. An empty tree is also considered to satisfy this property.

## Example Testcases

**Example 1:**
```
Input: root = [1,2,3]
Output: true
Explanation:
    1
   / \
  2   3
All values are {1, 2, 3}, all > 0.
```

**Example 2:**
```
Input: root = [1,-2,3]
Output: false
Explanation:
    1
   / \
 -2   3
Value -2 is not > 0.
```

**Example 3:**
```
Input: root = [1,null,2,null,-3]
Output: false
Explanation:
1
 \
  2
   \
   -3
Value -3 is not > 0.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
