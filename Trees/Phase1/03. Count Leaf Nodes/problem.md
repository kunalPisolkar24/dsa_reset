# 3. Count Leaf Nodes

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the number of **leaf nodes** in the tree.

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
Nodes 4, 5, and 3 are leaf nodes.
```

**Example 2:**
```
Input: root = [1,null,2]
Output: 1
Explanation: Node 2 is the only leaf node.
```

**Example 3:**
```
Input: root = [1]
Output: 1
Explanation: The root itself is a leaf node.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
