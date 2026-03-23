# 4. Sum of All Nodes

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return the **sum of all node values** in the tree.

## Example Testcases

**Example 1:**
```
Input: root = [1,2,3,4]
Output: 10
Explanation:
    1
   / \
  2   3
 /
4
1 + 2 + 3 + 4 = 10.
```

**Example 2:**
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
Output: 55
Explanation:
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
5+4+8+11+13+4+7+2+1 = 55.
```

**Example 3:**
```
Input: root = [1,null,2,null,3]
Output: 6
Explanation:
1
 \
  2
   \
    3
1 + 2 + 3 = 6.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`
