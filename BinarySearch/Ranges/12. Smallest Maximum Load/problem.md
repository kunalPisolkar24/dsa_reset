# 12. Smallest Maximum Load

**Difficulty:** Medium

## Problem Statement

You have `n` tasks with weights given in the array `tasks`. You need to distribute these **contiguous** tasks among `k` identical workers. Every task must be assigned to exactly one worker, and each worker must be assigned a contiguous segment of tasks.

The **load** of a worker is the sum of the weights of the tasks assigned to them. Your goal is to distribute the tasks such that the **maximum load** among all workers is **minimized**.

### Example Testcases

**Example 1:**
```
Input: tasks = [1, 2, 3, 4, 5], k = 3
Output: 6
Explanation: 
Worker 1: [1, 2, 3] (Load 6)
Worker 2: [4] (Load 4)
Worker 3: [5] (Load 5)
Max load = 6.
```

**Example 2:**
```
Input: tasks = [10, 20, 30], k = 2
Output: 30
```

## Constraints

- `1 <= tasks.length <= 10^5`
- `1 <= tasks[i] <= 10^9`
- `1 <= k <= tasks.length`
