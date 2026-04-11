#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairsWithMandatoryStop(int n, int m) {
    vector<int> dp(n + 1, -1);
    int MOD = 1e9 + 7;
    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      if (n == 1 or n == 0)
        return 1;
      if (dp[n] != -1)
        return dp[n];
      int sum = 0;
      sum = (sum + sol(n - 1)) % MOD;
      sum = (sum + sol(n - 2)) % MOD;
      return dp[n] = sum;
    };
    return (1LL * sol(m) * sol(n - m)) % MOD;
  }
};
