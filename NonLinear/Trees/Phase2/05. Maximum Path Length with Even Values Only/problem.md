# 5. Maximum Path Length with Even Values Only

**Difficulty:** Medium

## Problem Statement

Return the maximum length of a **root-to-leaf** path, with the following rule:

- You can ONLY continue through nodes with **even** values.
- If a node has an **odd** value, the path breaks and becomes invalid.

Return the maximum valid path length. If no valid root-to-leaf path exists, return `0`.

The **length** of a path is defined as the number of nodes on that path.

## Example Testcases

**Example 1:**
```
Input: root = [2,4,6,3,null,null,8]
Output: 3
Explanation:
    2
   / \
  4   6
 /     \
3       8
- Path 2 -> 6 -> 8 is entirely even. Length = 3.
- Path 2 -> 4 -> 3 breaks at 3 because 3 is odd.
Maximum valid length is 3.
```

**Example 2:**
```
Input: root = [1,2,4]
Output: 0
Explanation:
    1
   / \
  2   4
The root value 1 is odd, so any root-to-leaf path is immediately invalid.
```

**Example 3:**
```
Input: root = [2,4,4,null,null,6,8]
Output: 3
Explanation:
      2
     / \
    4   4
       / \
      6   8
Paths 2->4 (left) is length 2, path 2->4->6 (right) is length 3, 2->4->8 is length 3.
All nodes are even. Max length is 3.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
