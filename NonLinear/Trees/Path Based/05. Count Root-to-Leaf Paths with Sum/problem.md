# 5. Count Root-to-Leaf Paths with Sum

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return the **number** of root-to-leaf paths where the sum of node values equals `targetSum`.

## Example Testcases

**Example 1:**
```text
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 2
Explanation: Paths are 5->4->11->2 and 5->8->4->5.
```

**Example 2:**
```text
      1
     / \
    2   3
```
```
Input: root = [1,2,3], targetSum = 3
Output: 1
```

**Example 3:**
```text
      1
     / \
    2   3
```
```
Input: root = [1,2,3], targetSum = 5
Output: 0
```

## Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^9 <= Node.val <= 10^9`
