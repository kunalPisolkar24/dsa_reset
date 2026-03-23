# 12. Path Exists (Root-to-Leaf Sum)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree and `targetSum`, return `true` if there's a **root-to-leaf** path that sums to `targetSum`.

## Example Testcases

**Example 1:**
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Explanation: The path 5 -> 4 -> 11 -> 2 sums to 22.
Output: true
```

**Example 2:**
```
Input: root = [1,2,3], targetSum = 5
Output: false
```

**Example 3:**
```
Input: root = [], targetSum = 0
Output: false
Explanation: An empty tree has no paths.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`
