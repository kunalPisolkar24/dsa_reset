# 2. Tree Height (Maximum Depth)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return its **maximum depth**.

## Example Testcases

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: 3
Explanation:
    3
   / \
  9  20
    /  \
   15   7
The longest path is 3 -> 20 -> 15 (or 7), which has 3 nodes.
```

**Example 2:**
```
Input: root = [1,null,2]
Output: 2
Explanation:
  1
   \
    2
The longest path is 1 -> 2, depth is 2.
```

**Example 3:**
```
Input: root = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
Output: 4
Explanation:
           1
        /     \
       2       3
      / \     / \
     4   5   6   7
    / \ / \ / \ / \
   8  9 10 11 12 13 14 15
The tree is a perfect binary tree of height 4.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-100 <= Node.val <= 100`
