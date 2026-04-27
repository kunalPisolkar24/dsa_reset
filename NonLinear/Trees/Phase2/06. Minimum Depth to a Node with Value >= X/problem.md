# 6. Minimum Depth to a Node with Value >= X

**Difficulty:** Medium

## Problem Statement

Given a binary tree and an integer `X`, find the **minimum depth** from the root to **any** node whose value is greater than or equal to `X`.

If no such node exists, return `-1`.

The depth of the root node is `1`.

## Example Testcases

Example 1:
```
Input: root = [5,3,10,1,null,7], X = 7
Output: 2
Explanation:
    5
   / \
  3   10
 /   /
1   7

- Node 10 is at depth 2 (5 -> 10) and 10 >= 7.
- Node 7 is at depth 3 (5 -> 10 -> 7) and 7 >= 7.
The minimum depth is 2.
```

Example 2:
```
Input: root = [1,2,3], X = 5
Output: -1
Explanation:
    1
   / \
  2   3

All node values {1, 2, 3} are less than 5.
```

Example 3:
```
Input: root = [10,5,15], X = 8
Output: 1
Explanation:
   10
   / \
  5   15

The root node itself has value 10 which is >= 8. Depth is 1.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= X <= 1000`
