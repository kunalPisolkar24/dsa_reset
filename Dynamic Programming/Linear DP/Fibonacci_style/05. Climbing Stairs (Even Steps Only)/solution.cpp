#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int N) {
    if (N & 1)
      return 0;
    vector<int> dp(N + 1, -1);
    int MOD = 1e9 + 7;

    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      if (n == 0)
        return 1;

      if (dp[n] != -1)
        return dp[n];

      long long sum = 0;
      sum = (sum + sol(n - 2)) % MOD;
      sum = (sum + sol(n - 4)) % MOD;

      return dp[n] = sum;
    };

    return sol(N);
  }
};
