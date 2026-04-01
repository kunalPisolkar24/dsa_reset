# 3. Permutations II (With Duplicates)

**Difficulty:** Medium

## Problem Statement

Given a collection of numbers, `nums`, that might contain **duplicates**, return **all possible unique permutations** in any order.

### Example Testcases

**Example 1:**
```
Input: nums = [1, 1, 2]
Output: [[1,1,2], [1,2,1], [2,1,1]]
```

**Example 2:**
```
Input: nums = [1, 2, 3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
```

**Example 3:**
```
Input: nums = [1, 1]
Output: [[1,1]]
```

## Constraints

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

## Notes

- Use the **Loop-based Backtracking** pattern with **`visited` array**.
- **Duplicate Suppression**: 
    1. Sort the input array `nums`.
    2. Use a `visited` array to keep track of used indices.
    3. In the loop, if an element is the same as the previous one and the previous one was **not used** in the current prefix, skip it:
       `if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;`
- This ensures that for a set of identical numbers, only the first available one can be used to start a new branch at any given position, preventing duplicate permutations.
