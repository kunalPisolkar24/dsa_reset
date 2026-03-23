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
Input: root = [1,2,3,4,null,null,5]
Output: 2
Explanation:
    1
   / \
  2   3
 /     \
4       5
Nodes 4 and 5 are the only leaf nodes.
```

**Example 3:**
```
Input: root = [1,null,2,null,3,null,4]
Output: 1
Explanation:
1
 \
  2
   \
    3
     \
      4
Only node 4 is a leaf node.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
