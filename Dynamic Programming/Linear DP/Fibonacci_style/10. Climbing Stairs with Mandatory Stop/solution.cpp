#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairsWithMandatoryStop(int n, int m) {
    int MOD = 1e9 + 7;
    auto sol = [&](int n) -> int {
      if (n == 1 or n == 0)
        return 1;
      vector<int> dp(n + 1, 0);
      dp[0] = dp[1] = 1;
      for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
      }
      return dp[n];
    };
    return (1LL * sol(m) * sol(n - m)) % MOD;
  }
};
