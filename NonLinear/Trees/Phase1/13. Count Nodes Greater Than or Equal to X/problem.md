# 13. Count Nodes Greater Than or Equal to X

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree and an integer `X`, return the total number of nodes in the tree that have a value greater than or equal to `X`.

## Example Testcases

**Example 1:**
```
Input: root = [5,2,8,6], X = 5
Output: 3
Explanation:
    5
   / \
  2   8
 /
6
Nodes with value >= 5 are {5, 8, 6}.
```

**Example 2:**
```
Input: root = [1,2,3], X = 4
Output: 0
Explanation:
    1
   / \
  2   3
No nodes have value >= 4.
```

**Example 3:**
```
Input: root = [10,5,15,3,7], X = 7
Output: 3
Explanation:
      10
     /  \
    5    15
   / \
  3   7
Nodes with value >= 7 are {10, 15, 7}.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- `-10^4 <= X <= 10^4`
