# 2. Minimum Depth of Binary Tree

**Difficulty:** Medium

## Problem Statement

Find the minimum depth of a binary tree.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

## Example Testcases

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: 2
Explanation:
    3
   / \
  9  20
    /  \
   15   7
The shortest path to a leaf is 3 -> 9. The depth is 2 nodes.
```

**Example 2:**
```
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
Explanation:
  2
   \
    3
     \
      4
       \
        5
         \
          6
The only leaf node is 6. The depth is 5.
```

**Example 3:**
```
Input: root = [1,2,3,4,5]
Output: 2
Explanation:
    1
   / \
  2   3
 / \
4   5
Node 3 is a leaf node. Path 1 -> 3 has length 2.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
