# 1. Path Exists (Root-to-Leaf Sum)

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree and `targetSum`, return `true` if there's a **root-to-leaf** path that sums to `targetSum`.

## Example Testcases

**Example 1:**
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation:
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
The path 5 -> 4 -> 11 -> 2 sums to 22.
```

**Example 2:**
```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation:
    1
   / \
  2   3
Paths are 1->2 (sum 3) and 1->3 (sum 4). None sum to 5.
```

**Example 3:**
```
Input: root = [1,2,null,3,null,4], targetSum = 10
Output: true
Explanation:
      1
     /
    2
   /
  3
 /
4
The only path is 1 -> 2 -> 3 -> 4 which sums to 10.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`
