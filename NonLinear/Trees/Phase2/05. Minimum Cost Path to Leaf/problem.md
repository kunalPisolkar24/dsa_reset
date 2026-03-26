# 5. Minimum Cost Path to Leaf

**Difficulty:** Easy

## Problem Statement

You are given the `root` of a binary tree. Each node in the tree contains an integer value representing a cost.

Return the minimum total cost of a path that starts at the `root` and ends at **any** leaf node.

A **leaf** is a node with no children.

## Example Testcases

**Example 1:**
```
Input: root = [5,3,8,null,null,2]
Output: 8
Explanation:
    5
   / \
  3   8
     /
    2
Paths:
- 5 -> 3 (Cost: 5 + 3 = 8)
- 5 -> 8 -> 2 (Cost: 5 + 8 + 2 = 15)
Minimum cost is 8.
```

**Example 2:**
```
Input: root = [10,null,5,null,1]
Output: 16
Explanation:
  10
    \
     5
      \
       1
The only leaf node is 1. The only root-to-leaf path is 10 -> 5 -> 1 with a total cost of 16.
```

**Example 3:**
```
Input: root = [1,2,3,4,null,null,5]
Output: 7
Explanation:
      1
     / \
    2   3
   /     \
  4       5
Path 1 -> 2 -> 4 (Cost 7), Path 1 -> 3 -> 5 (Cost 9). Minimum is 7.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
