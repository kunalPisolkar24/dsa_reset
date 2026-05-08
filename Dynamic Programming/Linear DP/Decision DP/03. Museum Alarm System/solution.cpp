#include <bits/stdc++.h>

using namespace std;

/**
 * Problem 3: Museum Alarm System
 *
 * Cannot rob two adjacent rooms. Can skip ANY number of rooms.
 * Find max loot.
 *
 * Goal: Solve in 4 ways (Recursive, Memoized, Tabulated, Space Optimized).
 */
typedef long long ll;
class Solution {
public:
  long long maxLoot(vector<int> &value) {

    int n = value.size();
    if (n == 1)
      return value[0];
    ll p0 = value[0];
    ll p1 = max(value[0], value[1]);
    for (int i = 2; i < n; i++) {
      long long curr = max(p1, p0 + value[i]);
      p0 = p1;
      p1 = curr;
    }
    return p1;
  }
};
