#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n, int k) {
    vector<int> dp(n + 1, -1);
    int MOD = 1e9 + 7;
    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      if (n == 0 or n == 1)
        return 1;
      if (dp[n] != -1)
        return dp[n];
      int sum = 0;
      for (int i = 1; i <= k; i++) {
        sum = (sum + sol(n - i)) % MOD;
      }
      return dp[n] = sum;
    };
    return sol(n);
  }
};
