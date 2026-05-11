# 05. Mountain Camp Supplies

# Problem Statement

A trekking team is moving through `N` mountain camps arranged in a straight line.

Each camp contains some supply boxes.
The number of boxes at camp `i` is given by `supplies[i]`.

You start at camp `0`.

At every camp, you must choose exactly one of the following:

1. **Collect supplies from the current camp**

   * You gain `supplies[i]`
   * Your team becomes heavy, so you must skip the next **2 camps**
   * Next position becomes `i + 3`

2. **Skip the current camp**

   * Gain nothing
   * Move normally to the next camp
   * Next position becomes `i + 1`

Your goal is to maximize the total supplies collected.

---

# Example 1

```text
Input:
supplies = [4, 2, 7, 9, 3]

Output:
13
```

### Explanation

Best path:

* Take camp 0 → +4 → move to 3
* Take camp 3 → +9 → move outside array

Total = 13

---

# Example 2

```text
Input:
supplies = [5, 10, 4, 1, 8]

Output:
18
```

### Explanation

Best strategy:

* Skip 0
* Take 1 → +10 → move to 4
* Take 4 → +8

Total = 18

---

# Example 3

```text
Input:
supplies = [6]

Output:
6
```

---

# Constraints

```text
1 <= N <= 100000
0 <= supplies[i] <= 10^9
```
