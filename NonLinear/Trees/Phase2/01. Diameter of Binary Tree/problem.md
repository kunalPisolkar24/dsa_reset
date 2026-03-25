# 1. Diameter of Binary Tree

**Difficulty:** Medium

## Problem Statement

Return the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

## Example Testcases

**Example 1:**
```
Input: root = [1,2,3,4,5]
Output: 3
Explanation:
    1
   / \
  2   3
 / \
4   5
The longest path is 4 -> 2 -> 1 -> 3 (or 5 -> 2 -> 1 -> 3), which has 3 edges.
```

**Example 2:**
```
Input: root = [1,2]
Output: 1
Explanation:
    1
   /
  2
The longest path is 2 -> 1, which has 1 edge.
```

**Example 3:**
```
Input: root = [1,null,2,null,3]
Output: 2
Explanation:
  1
   \
    2
     \
      3
The longest path is 1 -> 2 -> 3, which has 2 edges.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-100 <= Node.val <= 100`
