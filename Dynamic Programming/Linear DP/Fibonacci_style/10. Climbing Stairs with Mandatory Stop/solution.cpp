#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairsWithMandatoryStop(int n, int m) {
    int MOD = 1e9 + 7;
    auto sol = [&](int n) -> int {
      if (n == 1 or n == 0)
        return 1;
      int p1 = 1, p2 = 1;
      for (int i = 2; i <= n; i++) {
        int curr = (p1 + p2) % MOD;
        p1 = p2;
        p2 = curr;
      }
      return p2;
    };
    return (1LL * sol(m) * sol(n - m)) % MOD;
  }
};
