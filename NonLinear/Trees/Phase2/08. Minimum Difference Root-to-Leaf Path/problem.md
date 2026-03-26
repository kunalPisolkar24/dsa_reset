# 8. Minimum Difference Root-to-Leaf Path

**Difficulty:** Medium

## Problem Statement

Each path from the root to a leaf has a **score** defined as:
`score = max(node_value) - min(node_value)` along that path.

Return the **minimum** score among all possible root-to-leaf paths.

## Example Testcases

**Example 1:**
```
Input: root = [8,3,10,1,6]
Output: 2
Explanation:
    8
   / \
  3   10
 / \
1   6
Paths:
- 8 -> 3 -> 1: max=8, min=1, diff=7
- 8 -> 3 -> 6: max=8, min=3, diff=5
- 8 -> 10: max=10, min=8, diff=2
The minimum difference is 2.
```

**Example 2:**
```
Input: root = [1,2,3]
Output: 1
Explanation:
    1
   / \
  2   3
- Path 1 -> 2: max=2, min=1, diff=1
- Path 1 -> 3: max=3, min=1, diff=2
Minimum is 1.
```

**Example 3:**
```
Input: root = [10,5,15,3,7,12,20], X = 15
Output: 5
Explanation:
      10
     /  \
    5    15
   / \   / \
  3   7 12  20
- Path 10->5->3: diff 7
- Path 10->5->7: diff 5
- Path 10->15->12: diff 5
- Path 10->15->20: diff 10
Minimum is 5.
```

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`
