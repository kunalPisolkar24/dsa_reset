# 6. Maximum Root-to-Leaf Path

**Difficulty:** Medium

## Problem Statement

Given the `root` of a binary tree, return the **path** (as a list of node values) that results in the maximum sum from root to any leaf. If multiple paths have the same maximum sum, return any one of them.

## Example Testcases

**Example 1:**
```text
      1
     / \
    2   3
```
```
Input: root = [1,2,3]
Output: [1,3]
Explanation: Paths are [1,2] (sum 3) and [1,3] (sum 4). Max is [1,3].
```

**Example 2:**
```text
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
Output: [5,8,4,1]
Explanation: Path sum is 18. Other paths have smaller sums.
```

**Example 3:**
```text
    -10
    / \
   9  20
      / \
     15  7
```
```
Input: root = [-10,9,20,null,null,15,7]
Output: [-10,20,15]
Explanation: Sum is 25.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 5000]`.
- `-1000 <= Node.val <= 1000`
