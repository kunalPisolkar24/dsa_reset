# 9. Level Order Traversal (BFS)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **level order traversal** (level by level, left to right).

## Example Testcases

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Explanation:
    3
   / \
  9  20
    /  \
   15   7
Level 1: [3]
Level 2: [9, 20]
Level 3: [15, 7]
```

**Example 2:**
```
Input: root = [1,2,3,4,null,null,5]
Output: [[1],[2,3],[4,5]]
Explanation:
    1
   / \
  2   3
 /     \
4       5
Level 1: [1]
Level 2: [2, 3]
Level 3: [4, 5]
```

**Example 3:**
```
Input: root = [1,null,2,null,3,null,4]
Output: [[1],[2],[3],[4]]
Explanation:
1
 \
  2
   \
    3
     \
      4
Level by level from root down.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`
