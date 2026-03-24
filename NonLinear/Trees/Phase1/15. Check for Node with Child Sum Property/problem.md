# 15. Check for Node with Child Sum Property

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return `true` if there exists **at least one node** in the tree (excluding leaves) whose value is equal to the **sum** of the values of its immediate left and right children.

Assume `null` children have a value of `0`.

## Example Testcases

**Example 1:**
```
Input: root = [10,4,6]
Output: true
Explanation:
    10
   /  \
  4    6
Node 10 = 4 + 6.
```

**Example 2:**
```
Input: root = [5,3,1]
Output: false
Explanation:
    5
   / \
  3   1
Node 5 != 3 + 1.
```

**Example 3:**
```
Input: root = [1,2,3,4,null,null,5]
Output: false
Explanation:
      1
    /   \
   2     3
  /       \
 4         5
No internal node satisfies the sum property.
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
