# 2. Maximum Root-to-Leaf Sum

**Difficulty:** Medium

## Problem Statement

Given the `root` of a binary tree, return the maximum sum obtained from a path starting at the root and ending at any leaf node.

A leaf is a node with no children.

## Example Testcases

**Example 1:**
```
Input: root = [5,3,8,null,null,7]
Output: 20
Explanation:
    5
   / \
  3   8
     /
    7
The root-to-leaf paths are:
- 5 -> 3 (Sum: 8)
- 5 -> 8 -> 7 (Sum: 20)
The maximum sum is 20.
```

**Example 2:**
```
Input: root = [1,2,3]
Output: 4
Explanation:
    1
   / \
  2   3
Paths are 1->2 (sum 3) and 1->3 (sum 4). Max is 4.
```

**Example 3:**
```
Input: root = [-10,9,20]
Output: 10
Explanation:
   -10
   /  \
  9   20
Paths are -10 -> 9 (sum -1) and -10 -> 20 (sum 10). Max is 10.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
