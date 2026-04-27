# 8. Longest Path with Given Sum

**Difficulty:** Medium

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return the **length** (number of nodes) of the longest downward path whose sum equals `targetSum`.

## Example Testcases

**Example 1:**
```text
      1
     / \
    2   3
   / \ / \
  1  1 1  1
```
```
Input: root = [1,2,3,1,1,1,1], targetSum = 3
Output: 2
Explanation: Paths are [1,2] (len 2) and [3] (len 1) and [2,1] (len 2). Max len is 2.
```

**Example 2:**
```text
      0
     / \
    0   0
   /
  0
```
```
Input: root = [0,0,0,0], targetSum = 0
Output: 3
Explanation: Longest path [0,0,0] from root to leaf.
```

**Example 3:**
```text
      5
     / \
    4   8
   /   / \
  11  13  4
```
```
Input: root = [5,4,8,11,null,13,4], targetSum = 9
Output: 2
Explanation: 5+4=9 has length 2.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 1000]`.
- `-1000 <= Node.val <= 1000`
