# 3. All Root-to-Leaf Paths

**Difficulty:** Easy

## Problem Statement

Given the `root` of a binary tree, return all **root-to-leaf** paths as a list of strings where each path is represented as nodes joined by `->`.

## Example Testcases

**Example 1:**
```text
      1
     / \
    2   3
     \
      5
```
```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```

**Example 2:**
```text
    1
```
```
Input: root = [1]
Output: ["1"]
```

**Example 3:**
```text
      1
     / \
    2   3
   / \
  4   5
```
```
Input: root = [1,2,3,4,5]
Output: ["1->2->4","1->2->5","1->3"]
```

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
