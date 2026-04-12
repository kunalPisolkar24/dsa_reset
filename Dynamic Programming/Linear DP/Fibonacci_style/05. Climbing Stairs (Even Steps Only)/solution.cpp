#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n & 1)
      return 0;

    int MOD = 1e9 + 7;
    int m = n / 2;

    int p0 = 1, p1 = 1;
    for (int i = 2; i <= m; i++) {
      int curr = (p0 + p1) % MOD;
      p0 = p1;
      p1 = curr;
    }
    return p1;
  }
};
