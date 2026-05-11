# 04. Desert Relay Stations

# Problem Statement

A rescue vehicle is traveling through `N` desert relay stations.

Each station provides some fuel units:

```text id="bfv1cl"
fuel[i]
```

At every station `i`, you must choose one action:

---

## Option 1 — Quick Refuel

* Collect `fuel[i]`
* Move to station `i + 1`

---

## Option 2 — Heavy Refuel

* Collect `2 * fuel[i]`
* The vehicle becomes overloaded
* You must skip the next station
* Move to station `i + 2`

---

## Option 3 — Ignore Station

* Collect nothing
* Move to station `i + 1`

---

Your task is to maximize the total fuel collected.

---

# Example 1

```text id="2mjlwm"
Input:
fuel = [4, 5, 3]

Output:
15
```

### Explanation

Best strategy:

* Quick at 0 → +4
* Quick at 1 → +5
* Heavy at 2 → +6

Total = 15

Other options:
* Quick at 0 (+4), Heavy at 1 (+10), Skip 2: Total = 14
* Heavy at 0 (+8), Skip 1, Heavy at 2 (+6): Total = 14

---

# Example 2

```text id="pm1v8q"
Input:
fuel = [10, 1, 10]

Output:
40
```

### Explanation

* Heavy at 0 → +20 → move to 2
* Heavy at 2 → +20

Actually possible because skipping after 2 exits array.

Answer = 40

---

# Constraints

```text id="qkkkj8"
1 <= N <= 100000
0 <= fuel[i] <= 10^9
```
