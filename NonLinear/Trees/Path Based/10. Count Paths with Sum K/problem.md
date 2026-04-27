# 10. Count Paths with Sum K

**Difficulty:** Hard

## Problem Statement

Given the `root` of a binary tree and an integer `k`, return the number of **downward** paths where the sum of values equals `k`. The tree can contain **negative** values. Optimize your solution using a prefix sum hashmap approach.

## Example Testcases

**Example 1:**
```text
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
```
```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], k = 8
Output: 3
Explanation: 5->3, 5->2->1, 10->-3->11.
```

**Example 2:**
```text
      1
     / \
   -2  -3
```
```
Input: root = [1,-2,-3], k = -1
Output: 1
Explanation: 1->-2.
```

**Example 3:**
```text
      0
     / \
    0   0
```
```
Input: root = [0,0,0], k = 0
Output: 5
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^5]`.
- `-10^9 <= Node.val <= 10^9` (Note: Use long long for sums)
